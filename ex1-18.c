#include <stdio.h>
#include <stdlib.h>

#define START 0
#define BLANK 1
#define NOTBLANK 2
#define SIZE 80

int main() {
    int index=0;
    int state=START;
    int c=0;
    char spaces[SIZE];

    while ((c=getchar()) != EOF) {
        if (state==START) {
            if (c=='\n') {
                // noop
            } else if (c==' ' || c=='\t') {
                state=BLANK;
                spaces[index]=c;
                index++;
            } else {
                state=NOTBLANK;
                putchar(c);
                index=0;
            }
        } else if (state==BLANK) {
            if (c=='\n') {
                putchar(c);
                state=START;
                index=0;
            } else if (c==' ' || c=='\t') {
                spaces[index]=c;
                index++;
            } else {
                for (int i=0; i<index; i++) {
                    putchar(spaces[i]);
                }
                putchar(c);
                index=0;
                state=NOTBLANK;
            }
        } else if (state==NOTBLANK) {
            if (c=='\n') {
                putchar(c);
                state=START;
                index=0;
            } else if (c==' ' || c=='\t') {
                spaces[index]=c;
                index++;
                state=BLANK;
            } else {
                putchar(c);
            }
        } else {
            exit(1);
        }
    }
}
