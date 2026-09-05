#include <stdio.h>
#include "wheel.h"


void assemble_wheel(Wheel * wheel) {
  uint8_t counter = 0;
  wheel->actionPole = &wheel->pole[0];
  uint8_t array[37] = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22,18, 29, 7, 28, 12, 35, 3, 26};
  for(int i = 0; i < 37; i++) {
    if(0 == counter) {
      wheel->pole[i].previous = &wheel->pole[36];
      wheel->pole[i].value.number = array[i];
      wheel->pole[i].value.color = GREEN;
      wheel->pole[i].next = &wheel->pole[i+1];
      counter = 1;
      continue;
    }
    if(1 == counter) {
      if(1 == i) {
        wheel->pole[i].previous = &wheel->pole[0];
        wheel->pole[i].value.number = array[i];
        wheel->pole[i].value.color = RED;
        wheel->pole[i].next = &wheel->pole[i+1];
        counter = 2;
      } else {
        wheel->pole[i].previous = &wheel->pole[i-1];
        wheel->pole[i].value.number = array[i];
        wheel->pole[i].value.color = RED;
        wheel->pole[i].next = &wheel->pole[i+1];
        counter = 2;
      }
      continue;
    }
    if(2 == counter) {
      if(36 == i) {
        wheel->pole[i].previous = &wheel->pole[i-1];
        wheel->pole[i].value.number = array[i];
        wheel->pole[i].value.color = BLACK;
        wheel->pole[i].next = &wheel->pole[0];
        counter = 0;
      } else {
        wheel->pole[i].previous = &wheel->pole[i-1];
        wheel->pole[i].value.number = array[i];
        wheel->pole[i].value.color = BLACK;
        wheel->pole[i].next = &wheel->pole[i+1];
        counter = 1;
      }
      continue;
    }
  }
}

void wheel_print(Wheel * wheel) {
  for(int i = 0; i < 37; i++) {
    printf("Number = %u", wheel->pole[i].value.number);
    printf(" color = %d\n", wheel->pole[i].value.color);
  } 
}
