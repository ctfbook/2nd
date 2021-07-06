#define _FORTIFY_SOURCE 2

#include <stdio.h>

int main(void){
	unsigned int x;
	char *fmt1  = "%1$cOK\n";
	char *fmt2  = "%2$cOK\n";

	setbuf(stdout, NULL);
	printf("fmt1 :");
	printf(fmt1, ' ');

	printf("fmt2 :");
	printf(fmt2, ' ');
}
