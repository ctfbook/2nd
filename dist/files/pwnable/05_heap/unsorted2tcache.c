#include <stdio.h>
#include <stdlib.h>

int main(void){
	void *p[5];

	p[0] = malloc(0x88);  malloc(0);
	p[1] = malloc(0xf8);  malloc(0);
	p[2] = malloc(0x418); malloc(0);
	p[3] = malloc(0x88);  malloc(0);
	p[4] = malloc(0x88);  malloc(0);

	for(int i=0; i<7; i++){
		free(calloc(1, 0x88));
		free(calloc(1, 0xf8));
	}

	for(int i=0; i<sizeof(p)/sizeof(unsigned long*); i++)
		free(p[i]);

	malloc(0x88);
	malloc(0xf8);

	calloc(1, 0x88);
}
