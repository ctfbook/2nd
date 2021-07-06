#include <stdio.h>
#include <string.h>

void main(void){
	char *priv = "user";
	unsigned key = 0xcafebabe;
	char secret[0x10] = "AAAA";
	char name[0x10] = {0};

	printf("Input Name >> ");
	fgets(name, 0x100, stdin);
	printf("\nname\t: %s\nsecret\t: %s\nkey\t: %x\npriv\t: %s\n", name, secret, key, priv);

	if(!strcmp(priv, "admin") &&
		!strcmp(secret, "H4cked!") &&
		key == 0xdeadbeef)
		puts("Correct!");
	else
		puts("Wrong...");
}
