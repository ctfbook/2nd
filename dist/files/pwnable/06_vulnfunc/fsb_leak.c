#include <stdio.h>

int main(void){
	char *buf;
	char *secret = "SECRET_KEY";

	setbuf(stdout, NULL);
	scanf("%ms", &buf);
	printf(buf);
}
