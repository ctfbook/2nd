#include <stdio.h>

char msg[0x100];

void main(void){
	char name[0x10];
	
	puts("Hello!");

	printf("Input Name >> ");
	fgets(name, 0x20, stdin);

	printf("Input Message >> ");
	fgets(msg, sizeof(msg), stdin);
}

void win(unsigned key1, unsigned key2){
	puts("This is win\n");
	if(key1 == 0xcafebabe && key2 == 0xc0bebeef)
		puts("Correct!");
	else
		puts("Wrong...");
}
