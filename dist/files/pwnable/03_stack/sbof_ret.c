#include <stdio.h>

void main(void){
	char name[0x10];

	printf("Input Name >> ");
	fgets(name, 0x100, stdin);
}

void win1(void){
	puts("This is win1\n");
	puts("Congratz!!");
}

void win2(unsigned key){
	puts("This is win2\n");
	if(key == 0xcafebabe)
		puts("Correct!");
	else
		puts("Wrong...");
}
