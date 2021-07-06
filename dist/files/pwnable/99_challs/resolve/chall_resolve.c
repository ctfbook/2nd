#include <stdio.h>
#include <unistd.h>

int main(void){
	char msg[0x10] = {};
	void **p;

	setbuf(stdout, NULL);

	printf("Input message >> ");
	fgets(msg, 0x80, stdin);

	printf("Input address >> ");
	scanf("%p", &p);
	printf("Input value   >> ");
	scanf("%p", p);

	return 0;
}

