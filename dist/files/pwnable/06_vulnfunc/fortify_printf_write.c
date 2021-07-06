#define _FORTIFY_SOURCE 2

#include <stdio.h>

int main(void){
	unsigned int x;
	char *fmt1  = "%nOK\n";
	char fmt2[] = "%nOK\n";

	setbuf(stdout, NULL);
	printf("fmt1 : ");
	printf(fmt1, &x);

	printf("fmt2 : ");
	printf(fmt2, &x);
}
