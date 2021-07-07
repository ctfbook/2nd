#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_CHAR_PER_LINE 0x100

/* 自身のTracerPidを取得する */
int gettpid(void) {
  int fd, i, s;
  char line[MAX_CHAR_PER_LINE], c;

  /* /proc/self/statusを開く */
  fd = open("/proc/self/status", O_RDONLY);
  if (fd == -1)
    return -1;

  do {
    /* 1行読む */
    for (i = 0; (s = read(fd, &c, 1)) == 1; i++) {
      if (c == '\n')
        break;
      if (i < MAX_CHAR_PER_LINE)
        line[i] = c;
    }

    /* TracerPidを調べる */
    if (strncmp(line, "TracerPid:", 10) == 0) {
      close(fd);
      return atoi(&line[10]);
    }
  } while(s == 1);

  close(fd);
  return -1;
}

int main() {
  int tpid = gettpid();

  if (tpid == -1) {
    puts("Unknown");
  } else if (tpid == 0) {
    puts("Not Attached");
  } else {
    printf("Attached by [PID=%d]\n", tpid);
  }
}
