#include <stdio.h>

int main() {
    int c;
    long nc=0;
    
    while ((c=getchar()) != EOF) {
        if ((c==' ') || (c=='\t') || (c=='\n')) {
            nc++;
        }
    }
    printf("blanks: %ld\n", nc);
}
