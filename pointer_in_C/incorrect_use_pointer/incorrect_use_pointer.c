#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void view_binary_unsigned_int(unsigned int x);

int main(void) {
  unsigned long your_number = 0;
  bool uncorect = false;
  do {
    printf("Enter the number you want to represent in binary : ");
    int r = scanf("%lu", &your_number);
    uncorect = false;
    if((r != 1) || (your_number > UINT_MAX)) {
      your_number = 0;
      printf("Your input is incorrect, please try again!\n");
      uncorect = true;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
  } while(uncorect);
  printf("You entered the number : %u\n", (unsigned int)your_number);
  printf("Your number in binary : ");
  view_binary_unsigned_int((unsigned int)your_number);
  return 0;
}

void view_binary_unsigned_int(unsigned int x) {
  unsigned char *px = (unsigned char *)&x;
  bool yn = false;
  if(*(px+3) != 0) {
    printf("%b", *(px+3));
    yn = true;
  }
  if(yn) {
    printf("%08b", *(px+2));
    yn = true;
  } else if(*(px+2) != 0) {
    printf("%b", *(px+2));
    yn = true;
  }
  if(yn) {
    printf("%08b", *(px+1));
    yn = true;
  } else if(*(px+1) != 0) {
    printf("%b", *(px+1));
    yn = true;
  }
  if(yn) {
    printf("%08b\n", *px);
  } else if(*px != 0) {
    printf("%b\n", *px);
  }
}
