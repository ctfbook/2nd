#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char *p;

	p = strdup("uname -a");
	__free_hook = (void(*)(void*, const void*))system;
	free(p);
}
