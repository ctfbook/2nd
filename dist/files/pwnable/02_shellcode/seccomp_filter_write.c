#include <stdio.h>
#include <stddef.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <linux/filter.h>
#include <linux/seccomp.h>

int set_seccomp(void){
	struct sock_filter filter[] = {
		BPF_STMT(BPF_LD | BPF_W | BPF_ABS, (offsetof(struct seccomp_data, nr))),

		BPF_JUMP(BPF_JMP | BPF_JEQ | BPF_K, __NR_write, 0, 1),
		BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_KILL),

		BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_ALLOW),
	};

	struct sock_fprog prog = {
		.len = (unsigned short) (sizeof(filter) / sizeof(struct sock_filter)),
		.filter = filter,
	};

	if(prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0)) {
		perror("prctl PR_SET_NO_NEW_PRIVS");
		return -1;
	}

	if(prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &prog)){
		perror("prctl PR_SET_SECCOMP");
		return -1;
	}

	return 0;
}
