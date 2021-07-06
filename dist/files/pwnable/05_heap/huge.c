#include <stdio.h>
#include <stdlib.h>

int main(void){
	void *p;

	setbuf(stdout, NULL);
	printf("malloc(0x20000) = %p\n", malloc(0x20000));
	printf("malloc(0x20000) = %p\n", malloc(0x20000));
	printf("malloc(0x20000) = %p\n", p=malloc(0x20000));
	printf("free(%p)\n", p); free(p);
	printf("malloc(0x20000) = %p\n", malloc(0x20000));
}
