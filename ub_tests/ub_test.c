#include <stdio.h>
#include <limits.h>

int main(void) {

    volatile y = INT_MAX;
    printf("y + 1 = %d\n", y + 1);
    if(y + 1 < 0) {
        puts("Overflow\n");
    }
}