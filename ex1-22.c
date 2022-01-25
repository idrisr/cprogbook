#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXLINE 200
#define COL 5

int main(int argc, char *argv[]) {
    int c=0;
    int index=0;
    int last_space=-1;
    char buffer[COL];

    while ((c=getchar()) != EOF) {
        if (index<COL) {
            if (c=='\n') {
                buffer[index]=c;
                index++;
                for (int i=0; i<index; i++) {
                    putchar(buffer[i]);
                }
                index=0;
                last_space=-1;
            } else if (c==' ' || c=='\t') {
                buffer[index]=c;
                last_space=index;
                index++;
            } else {
                buffer[index]=c;
                index++;
            }
        } else {
            if (c==' ' || c=='\t') {
                for (int i=0; i<index; i++) {
                    putchar(buffer[i]);
                }
                index=0;
                last_space=-1;
                buffer[index]=c;
                index++;
            } else if (last_space==-1) {
                for (int i=0; i<index-1; i++) {
                    putchar(buffer[i]);
                }
                buffer[0]=buffer[index-1];
                buffer[1]=c;
                putchar('-');
                index=2;
            } else {
                for (int i=0; i<last_space; i++) {
                    putchar(buffer[i]);
                }
                index=0;
                for (int i=last_space; i<COL; i++) {
                    buffer[i-last_space]=buffer[i];
                    index++;
                }
                buffer[0]=c;
                index=1;
                last_space=-1;
            }
            putchar('\n');
        }
    }

    return 0;
}
