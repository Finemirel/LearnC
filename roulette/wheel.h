#ifndef WHEEL_H
#define WHEEL_H

#include <stdint.h>

typedef enum Color {
  BLACK,
  RED,
  GREEN
} Color;

typedef struct Values {
  uint8_t number;
  Color color;
} Values;

typedef struct Pole {
  struct Pole * previous;
  struct Pole * next;
  Values value;
} Pole;

typedef struct Wheel {
  Pole pole[37];
  Pole * actionPole;
} Wheel;

void print_number_from_pole(Pole * pole);
void print_color_from_pole(Pole * pole);
void assemble_wheel(Wheel *wheel);
void wheel_print(Wheel * wheel);
Pole wheel_rotation(Wheel * wheel);

#endif
