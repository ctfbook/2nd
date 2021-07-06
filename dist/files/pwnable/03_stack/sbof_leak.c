#include <stdio.h>
#include <unistd.h>

void main(void){
	char buf[0x10];

	dprintf(STDOUT_FILENO, "Input Name >> ");
	read(STDIN_FILENO, buf, 0x100);

	dprintf(STDOUT_FILENO, "Hello, %s!\nInput Message >> ", buf);
	read(STDIN_FILENO, buf, 0x100);
}

void win(void){
	puts("Congratz!!");
}
