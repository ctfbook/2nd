#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	char buf[0x30] = {};

	setbuf(stdout, NULL);

	puts("Input message");
	read(STDIN_FILENO, buf, sizeof(buf));
	printf(buf);
	exit(0);
}
