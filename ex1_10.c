#include <stdio.h>

#define TAB 9
#define BACKSPACE 8
#define BACKSLASH 92


int main() {
    int c=0;

    while ((c=getchar()) != EOF) {
        if (c==TAB) {
            putchar('\\');
            putchar('t');
            printf("TAB");
        } else if (c==BACKSPACE) {
            putchar('\\');
            putchar('b');
        } else if (c==BACKSLASH) {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }

    return 0;
}
