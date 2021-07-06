#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

unsigned long key;

int main(void){
	char buf[0x30] = {};
	unsigned long secret = 0;
	int fd;

	if((fd = open("/dev/urandom", O_RDONLY)) < 0)
		return -1;
	read(fd, &secret, 3);
	read(fd, &key, 3);
	close(fd);

	read(STDIN_FILENO, buf, sizeof(buf));
	printf(buf);

	printf("\nsecret = %#08lx\nkey    = %#08lx\n", secret, key);
	puts(key^secret ? "Wrong key..." : "Correct!");
}
