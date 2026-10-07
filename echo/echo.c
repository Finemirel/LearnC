#include <stdio.h>

int main(void) {
    int c;

    while((c = getchar()) != EOF) {
        putchar(c);
        usleep(800000); //не выводит посимвольно с паузами!
        printf(" ");
    }

    return 0;
}