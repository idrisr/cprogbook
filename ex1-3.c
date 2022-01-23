#include <stdio.h>

int main(int argc, char *argv[]) {
    int cel, lower, upper, step;
    lower = 0;
    upper = 100;
    step = 5;
    cel = lower;
    float fahr = 0;

    printf("F\tC\n");
    while (cel <= upper) {
        fahr = cel * 9/5 + 32;
        printf("%3.1f\t%3d\n", fahr, cel);
        cel = cel + 5;
    }

    return 0;
}
