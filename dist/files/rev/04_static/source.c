#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int i;

  if (argc == 2) {
    if (atoi(argv[1]) == 777) {
      puts("Passcode is correct!");
    } else {
      puts("Passcode is wrong...");
    }
  } else {
    printf("Usage: %s [passcode]\n", argv[0]);
  }

  return 0;
}
