#include <stdio.h>
#include <stdlib.h>

static int getint(int min, int max){
	char buf[0x10] = {};
	int n;
	fgets(buf, sizeof(buf), stdin);
	if((n=atoi(buf)) < min || n > max) exit(0);
	return n;
}

int main(void){
	char* p[3];

	setbuf(stdout, NULL);

	puts("You can malloc three times");
	for(int i=0; i<3; i++){
		printf("size (%d/3) >> ", i+1);
		p[i] = malloc(getint(0, 0x800));
	}

	for(int i=0; i<3; i++)
		free(p[i]);

	printf("read buffer index >> ");
	printf("content : %s\n", p[getint(0,2)]);

	printf("write buffer index >> ");
	fgets(p[getint(0,2)], 8, stdin);

	puts("\nYou can malloc two times");
	for(int i=0; i<2; i++){
		int size;
		printf("size (%d/2) >> ", i+1);
		p[i] = malloc(size = getint(0, 0x800));
		printf("content >> ");
		fgets(p[i], size, stdin);
	}

	for(int i=0; i<2; i++)
		free(p[i]);

	return 0;
}
