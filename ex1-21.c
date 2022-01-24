#include <stdio.h>
#include <stdlib.h>

#define SPACE 0
#define NOTSPACE 1
#define NEWLINE 2
#define TABSTOP 7

int main(void) {
    int c=0;
    int spaces=0;
    int state=SPACE;

    while ((c=getchar()) != EOF) {
        if (state==SPACE) {
            if (c==' ') {
                spaces++;
                if (spaces==TABSTOP) {
                    putchar('\t');
                    spaces = 0;
                    state=NOTSPACE;
                }
            } else if (c=='\n') {
                for (int i=0; i<spaces;i++) {
                    putchar(' ');
                }
                putchar(c);
                spaces = 0;
                state=NEWLINE;
            } else {
                putchar(c);
                state=NOTSPACE;
            }
        } else if (state==NOTSPACE) {
            if (c==' ') {
                spaces=1;
                state=SPACE;
            } else if (c=='\n') {
                state=NEWLINE;
                putchar(c);
            } else {
                putchar(c);
            }
        } else if (state==NEWLINE) {
            if (c==' ') {
                state=SPACE;
                spaces=1;
            } else if (c=='\n') {
                putchar(c);
            } else {
                state=NOTSPACE;
                putchar(c);
            }
        } else {
            exit(1);
        }
    }

    return 0;
}
