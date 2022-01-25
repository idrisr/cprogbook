#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BLANK 0
#define NOTBLANK 1
#define MAXLINE 200
#define COL 100

int main() {
    int c=0;
    char buffer[MAXLINE];
    int state=BLANK;
    int index=0;
    int col=0;

    while ((c=getchar()) != EOF) {
        if (state==BLANK) {
            if (c=='\t' || c==' ') {
                buffer[index]=c;
                index++;
                col++;
            } else if (c=='\n') {
                index=0;
                putchar(c);
                col=0;
            } else {
                if (col>COL) {
                    putchar('\n');
                    col=0;
                } else {
                    for (int i=0; i<index; i++) {
                        putchar(buffer[i]);
                    }
                }
                index=0;
                state=NOTBLANK;
                col++;
                buffer[index]=c;
                index++;
            }
        } else if (state==NOTBLANK) {
            if (c=='\t' || c==' ') {
                state=BLANK;
                if (col>COL) {
                    putchar('\n');
                    col=0;
                    for (int i=0; i<index; i++) {
                        putchar(buffer[i]);
                        col++;
                    }
                    index=0;
                } else {
                    for (int i=0; i<index; i++) {
                        putchar(buffer[i]);
                    }
                    index=0;
                    buffer[index]=c;
                    index++;
                }
            } else if (c=='\n') {
                index=0;
                putchar(c);
                col=0;
            } else {
                buffer[index]=c;
                index++;
                col++;
            }

        } else {
            exit(1);
        }
    }

    return 0;
}
