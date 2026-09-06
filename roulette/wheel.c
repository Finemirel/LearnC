#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "wheel.h"


void assemble_wheel(Wheel * wheel) {
  uint8_t counter = 0;
  wheel->actionPole = &wheel->pole[0];
  uint8_t array[37] = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26};
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

void print_number_from_pole(Pole * pole) {
  printf("%u\n", pole->value.number);
}

void print_color_from_pole(Pole * pole) {
  switch(pole->value.color) {
    case BLACK:
      printf("Black\n");
      break;
    case RED:
      printf("Red\n");
      break;
    case GREEN:
      printf("Green\n");
      break;
  }  
}

static void wheel_point_previous(Wheel * wheel) {
  wheel->actionPole = wheel->actionPole->previous;
}

static void wheel_point_next(Wheel * wheel) {
  wheel->actionPole = wheel->actionPole->next;
}

static void wheel_backward_by_steps(Wheel * wheel, uint8_t steps) {
  for(int i = 0; i < steps; i++) {
    wheel_point_previous(wheel);
  } 
}

static void wheel_forward_by_steps(Wheel * wheel, uint8_t steps) {
  for(int i = 0; i < steps; i++) {
    wheel_point_next(wheel);
  } 
}
/*
static void wheel_print_by_point_backward(Wheel * wheel, uint8_t steps) {
  for(int i = 0; i < steps; i++) {
    printf("Number = %u", wheel->actionPole->value.number);
    printf(" color = %d\n", wheel->actionPole->value.color);
    wheel_point_previous(wheel);
  } 
}

static void wheel_print_by_point_forward(Wheel * wheel, uint8_t steps) {
  for(int i = 0; i < steps; i++) {
    printf("Number = %u", wheel->actionPole->value.number);
    printf(" color = %d\n", wheel->actionPole->value.color);
    wheel_point_next(wheel);
  } 
}
*/
static void wheel_print_number_steps(Wheel * wheel, uint8_t steps) {
  for(int i = 0; i < steps; i++) {
    printf(" %u ", wheel->actionPole->value.number);
    wheel_point_next(wheel);
  } 
}

static void wheel_print_number_steps_back(Wheel * wheel, uint8_t steps) {
  for(int i = 0; i < steps; i++) {
    printf(" %u ", wheel->actionPole->value.number);
    wheel_point_previous(wheel);
  } 
}

void wheel_print(Wheel * wheel) {
  Pole * pp = wheel->actionPole;
  //1
  wheel_forward_by_steps(wheel, 12);
  printf("\t\t");
  wheel_print_number_steps(wheel, 14);
  printf("\n");
   //2
  wheel_backward_by_steps(wheel, 17);
  printf("   ");
  wheel_print_number_steps(wheel, 3);
  printf("\t\t\t\t\t\t\t   ");
  wheel_forward_by_steps(wheel, 14);
  wheel_print_number_steps(wheel, 3);
  printf("\n");
  //3
  wheel_forward_by_steps(wheel, 16);
  wheel_print_number_steps(wheel, 1);
  printf("\t\t\t\t\t\t\t\t\t\t");
  wheel_backward_by_steps(wheel, 17);
  wheel_print_number_steps(wheel, 1);
  printf("\n");
  //4
  wheel_forward_by_steps(wheel, 14);
  wheel_print_number_steps(wheel, 1);
  printf("\t\t\t\t\t\t\t\t\t\t");
  wheel_backward_by_steps(wheel, 15);
  wheel_print_number_steps(wheel, 1);
  printf("\n");
  //5
  wheel_forward_by_steps(wheel, 12);
  printf("   ");
  wheel_print_number_steps_back(wheel, 3);
  printf("\t\t\t\t\t\t\t   ");
  wheel_backward_by_steps(wheel, 7);
  wheel_print_number_steps_back(wheel, 3);
  printf("\n");
  //6
  wheel_forward_by_steps(wheel, 10);
  printf("\t\t  ");
  wheel_print_number_steps_back(wheel, 3);
  printf("\t  < < | %u | > >  ", wheel->actionPole->value.number);
  wheel_point_previous(wheel);
  wheel_print_number_steps_back(wheel, 3);
  printf("\n");
  wheel->actionPole = pp;
}

static void clean_print_wheel() {
  printf("\33[1A");
  printf("\33[2K");
  printf("\33[1A");
  printf("\33[2K");
  printf("\33[1A");
  printf("\33[2K");
  printf("\33[1A");
  printf("\33[2K");
  printf("\33[1A");
  printf("\33[2K");
  printf("\33[1A");
  printf("\33[2K"); 
}

Pole wheel_rotation(Wheel * wheel) {
  srand((unsigned int)time(NULL));
  int rotation = 150 + (int)((double)rand() / (RAND_MAX +1.0) * 200);
  for(int i = 0; i < rotation; i++) {
    wheel_point_next(wheel);
    clean_print_wheel();
    wheel_print(wheel);
    usleep(1000 * i);
  }
  Pole pole = *wheel->actionPole;
  return pole;
}

