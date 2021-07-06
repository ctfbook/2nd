#include <stdlib.h>

int main(void){
	void *p[4];

	for(int i=0; i<sizeof(p)/sizeof(void*); i++){
		p[i] = malloc(0x88);
		malloc(0);
	}
	for(int i=0; i<7; i++)
		free(calloc(1, 0x88));
	for(int i=0; i<sizeof(p)/sizeof(void*); i++)
		free(p[i]);

	malloc(0xf8);
	for(int i=0; i<2; i++)
		malloc(0x88);

	calloc(1, 0x88);
}
