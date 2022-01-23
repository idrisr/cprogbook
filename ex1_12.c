#include <stdio.h>

/* on or off word split */
#define ON 1
#define OFF 0

int isspace(int c){
    return (c==' ' || c=='\n' || c=='\t');
}

int main() {
    int c=0;
    int blank=ON;
    
    while ((c=getchar()) != EOF) {
        if (blank) {
            if (isspace(c)) {
                ;
            } else {
                putchar(c);
                blank=OFF;
            }
        } else {
            if (isspace(c)) {
                putchar('\n');
                blank=ON;
            } else {
                putchar(c);
            }
        }
    }

    return 0;
}
