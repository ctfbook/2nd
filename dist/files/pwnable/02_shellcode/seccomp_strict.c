#include <stdio.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <linux/seccomp.h>

int main(void){
	puts("Before");
	printf("pid = %d\n", getpid());

	prctl(PR_SET_SECCOMP, SECCOMP_MODE_STRICT, NULL);

	puts("After");
	printf("pid = %d\n", getpid());
}
