#include <stdio.h>

int main() {
    int a;
    a = getchar() != EOF;
    printf("a: %d\n", a);
    printf("EOF: %d\n", EOF);
    return 0;
}
