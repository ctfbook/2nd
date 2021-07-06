#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <linux/filter.h>
#include <linux/seccomp.h>

void set_seccomp(void){
	struct sock_filter filter[] = {
	BPF_STMT(BPF_LD | BPF_W | BPF_ABS, (offsetof(struct seccomp_data, nr))),
	BPF_JUMP(BPF_JMP | BPF_JEQ | BPF_K, __NR_write, 0, 3),
	BPF_STMT(BPF_LD | BPF_W | BPF_ABS, (offsetof(struct seccomp_data, args[0]))),
	BPF_JUMP(BPF_JMP | BPF_JEQ | BPF_K, STDOUT_FILENO, 0, 1),
	BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_ALLOW),

	BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_KILL),
	};

	struct sock_fprog prog = {
		.len = (unsigned short) (sizeof(filter) / sizeof(struct sock_filter)),
		.filter = filter,
	};

	prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0);
	prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &prog);
}

int main(void){
	puts("Before");
	fputs("hoge\n", stderr);

	set_seccomp();

	puts("After");
	fputs("fuga\n", stderr);
}
