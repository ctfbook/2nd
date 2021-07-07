#include <stdio.h>
#include <string.h>

unsigned int flist[] = {
  6, 9, 7, 11, 5, 1, 5, 5, 2, 14, 3, 3, 0, 0, 1, 7, 14, 4, 15, 11
};

unsigned char func(int i) {
  return (flist[i*2] ^ i) * 16 + (flist[i*2+1] ^ (i+1));
}

int authenticate(const unsigned char *password) {
  int i, len = strlen(password);

  if (len != 10) {
    return 0;
  }

  for(i = 0; i < len; i++) {
    if (password[i] != func(i)) {
      return 0;
    }
  }

  return 1;
}

int main(int argc, char **argv) {
  char password[0x20];

  printf("Enter password: ");
  scanf("%31s", password);

  if (authenticate(password)) {
    puts("Password is correct!");
  } else {
    puts("Password is wrong...");
  }

  return 0;
}
