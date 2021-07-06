#ifndef MALLOC_STRUCT
#define MALLOC_STRUCT

#define chunk2mem(p)   ((void*)(p)+0x10)
#define mem2chunk(mem) ((malloc_chunk*)((void*)(mem)-0x10))

typedef struct malloc_chunk {
  size_t prev_size;
  size_t size;

  union{
	  struct {
		  struct malloc_chunk* fd;
		  struct malloc_chunk* bk;

		  struct malloc_chunk* fd_nextsize;
		  struct malloc_chunk* bk_nextsize;
	  };
	  char mem[0x20];
  };
} malloc_chunk;

typedef struct tcache_entry {
  struct tcache_entry *next;
  struct tcache_perthread_struct *key;
} tcache_entry;
#endif
