#include <stdio.h>
#include <unistd.h>
#include <sys/uio.h>

int set_seccomp(void);

int main(void){
	set_seccomp();

	char msg[] = "Hello, World!\n";
	struct iovec iov = {
		.iov_base = msg,
		.iov_len = sizeof(msg)
	};

	writev(STDOUT_FILENO, &iov, 1);
}
