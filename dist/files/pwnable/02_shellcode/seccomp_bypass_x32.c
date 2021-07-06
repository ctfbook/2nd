#include <unistd.h>
#include <sys/syscall.h>

int set_seccomp(void);

char msg[] = "Hello, World!\n";

int main(void){
	set_seccomp();

	syscall(__X32_SYSCALL_BIT|__NR_write, STDOUT_FILENO, msg, sizeof(msg));
}
