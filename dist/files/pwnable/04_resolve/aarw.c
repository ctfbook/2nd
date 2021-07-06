#include <stdio.h>
#include <stdlib.h>

void aar(void);
void aaw(void);

__attribute__((constructor))
int init(void){
	setbuf(stdout, NULL);
}

int main(void){
	char buf[0x20] = {};

	printf("1 : AAR\n2 : AAW\n>> ");

	do {
		fgets(buf, sizeof(buf), stdin);
	} while(buf[0] == '\n');

	switch(atoi(buf)){
		case 1:
			aar();
			break;
		case 2:
			aaw();
			break;
	}
	exit(0);
}

void aar(void){
	void **p;

	printf("Input address to read >> ");
	scanf("%p", &p);
	printf("%p : %p\n", p, *p);
}

void aaw(void){
	void **p;

	printf("Input address to write >> ");
	scanf("%p", &p);
	printf("Input value >> ");
	scanf("%p", p);
}

void win(void){
	puts("Congratz!!");
}
