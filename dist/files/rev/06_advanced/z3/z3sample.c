#include <stdio.h>

int check_input(unsigned int n) {
  int a, b, c, d;
  a = n & 0xff;
  b = (n >> 8) & 0xff;
  c = (n >> 16) & 0xff;
  d = (n >> 24) & 0xff;
  if ((a + b + c + d == 824)
      && (a - b + c - d == 0)
      && (a * b + c * d == 83816)
      && (a * b - c * d == 7004)) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  unsigned int code;
  printf("CODE: ");
  scanf("%u", &code);
  if (check_input(code)) {
    puts("Correct!");
  } else {
    puts("Wrong...");
  }
}
