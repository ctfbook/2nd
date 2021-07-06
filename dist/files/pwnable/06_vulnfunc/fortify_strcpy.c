#define _FORTIFY_SOURCE 1

#include <stdio.h>
#include <string.h>

int main(void){
	char buf[0x10];

	strcpy(buf, "aaaabbbbccccdddd");
	puts(buf);
}
