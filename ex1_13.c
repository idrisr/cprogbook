#include <stdio.h>

// histogram of word counts
#define ON 1
#define OFF 0
#define MAX_SIZE 10

int is_word_char(char c){
    return (c>=65 && c<=90) || (c>=97 && c<=122);
}

void print_hist(int* count) {
    for (int i=1; i<MAX_SIZE; i++) {
        printf("%2d\t", i);
        for (int j=0; j<count[i]; j++) {
            putchar('X');
        }
        putchar('\n');
    }
}

void print_array(int* count) {
    for (int i=0; i<MAX_SIZE; i++) {
        printf("%2d\t%2d\n", i, count[i]);
    }
}

int main(void) {
    int blank=ON;
    int c=0;
    int count[MAX_SIZE];
    int size=0;

    for (int i=0; i<MAX_SIZE; i++) {
        count[i] = 0;
    }

    while ((c=getchar()) != EOF) {
        if (blank) {
            if (!is_word_char(c)) {
                ;
            } else {
                size=1;
                blank=OFF;
            }
        } else {
            if (is_word_char(c)) {
                size++;
            } else {
                blank=ON;
                if (size<MAX_SIZE) {
                    count[size]++;
                } else {
                    count[MAX_SIZE-1]++;
                }
                size=0;
            }
        }
    }
    print_hist(count);

    return 0;
}
