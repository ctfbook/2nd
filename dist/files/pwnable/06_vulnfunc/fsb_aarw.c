#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	char buf[0x50] = {};
	unsigned long lv = 0xdeadbeef;

	setbuf(stdout, NULL);
	read(STDIN_FILENO, buf, sizeof(buf));
	printf(buf);
	printf("\nBye!");
}
