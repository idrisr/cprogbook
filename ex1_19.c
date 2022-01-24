#include <stdio.h>
#include <stdlib.h>
// reverse a string
#define MAX_SIZE 1000
#define START 0
#define NOTSTART 1

int main(void) {
    int c=0;
    int state=START;
    int index=0;

    char line[MAX_SIZE];

    while ((c=getchar()) != EOF) {
        if (state==START) {
            if (c=='\n') {
                putchar(c);
            } else {
                line[index] = c;
                index++;
                state=NOTSTART;
            }
        } else if (state==NOTSTART) {
            if (c=='\n') {
                for (int i=index-1; i>=0; i--) {
                    putchar(line[i]);
                }
                putchar(c);
                state=START;
                index=0;
            } else {
                line[index]=c;
                index++;
            }
        } else {
            exit(1);
        }
    }
}
