#include <stdio.h>

#define TABSTOP 8

int main(void) {
    int c=0;
    int index=0;
    int spaces=0;

    while ((c=getchar()) != EOF) {
        if (c=='\t') {
            spaces=TABSTOP - (index%TABSTOP);
            /* printf("spaces: %d\n", spaces); */
            for (int i=0;i<spaces;i++) {
                putchar(' ');
                index++;
            }
        } else if (c=='\n') {
            index=0;
            putchar(c);
        } else {
            index++;
            putchar(c);
        }
    }
}
