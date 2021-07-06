#include <stdio.h>

unsigned long A = 0xdeadbeef;
unsigned long B = 0xcafeba00;

int main(void){
	char *buf;
	void *p1 = &A, *p2 = &p1;

	scanf("%ms", &buf);
	printf(buf);

	printf("\nA = %#08lx (%s)\nB = %#08lx (%s)\n",
		 A, A^0xdeadbeef ? "NG" : "OK",
		 B, B^0xcafebabe ? "NG" : "OK");
	return 0;
}
