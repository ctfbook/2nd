#include <stdio.h>
#include <stdlib.h>
#include "malloc_struct.h"

int main(void){
	void *m;

	m = malloc(0x18);
	printf("m = %p\n", m);

	free(m);
	((tcache_entry*)m)->key = NULL;	// vuln
	free(m);			// vuln

	printf("1st malloc : %p\n", malloc(0x18));
	printf("2nd malloc : %p\n", malloc(0x18));
}
