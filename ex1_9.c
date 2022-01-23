#include <stdio.h>
#include <stdbool.h>

/* _ _ */
/* _ 1 */

/* 1 _ */
/* 1 1 */


int main() {
    int c=0;
    bool wasblank=false;

    while ((c=getchar()) != EOF) {
        if (c==' ') {
            if (wasblank) {
                ;
            } else {
                putchar(c);
            }
            wasblank = true;
        } else {
            putchar(c);
            wasblank = false;
        }
    }
}
