#include <stdio.h>
#include <stdint.h>
#include "wheel.h"

typedef struct Bet {
  union {
    uint8_t number;
    Color color;
  } color_or_number;
} Bet;

int main(void) {
  Wheel wheel;
  assemble_wheel(&wheel);
  wheel_print(&wheel);
  
  Pole pole = wheel_rotation(&wheel);
  print_number_from_pole(&pole);
  print_color_from_pole(&pole);
  
  return 0;
}



