#include <stdlib.h>

int main(void){
	void *p[4];

	for(int i=0; i<sizeof(p)/sizeof(void*); i++)
		p[i] = malloc(0x18);
	for(int i=0; i<7; i++)
		free(calloc(1, 0x18));
	for(int i=0; i<sizeof(p)/sizeof(void*); i++)
		free(p[i]);
	for(int i=0; i<2; i++)
		malloc(0x18);

	calloc(1, 0x18);
}
