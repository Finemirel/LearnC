#include <stdio.h>

void func_one(int);
void func_two(int *);

int main(void) {
  int s = 4;
  int * ps = &s;
  printf("%d\n", s);
  printf("%d\n", *ps);
  func_one(s);
  printf("%d\n", s);
  func_two(ps);
  printf("%d\n", s);
  
  
  return 0;
}

void func_one(int s) {
  s = s + 3;
  printf("%d\n", s);
}

void func_two(int *ps) {
  *ps = *ps + 5;
  printf("%d\n", *ps);
}
