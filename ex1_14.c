#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LETTERS 26

int is_word_char(char c){
    return (c>=65 && c<=90) || (c>=97 && c<=122);
}

int char_index(char c) {
    int index=0;

    if (is_word_char(c)) {
        if (c>=97) {
            c = c-32;
        }
        index=c-'A';
    } else {
        exit(1);
    }
    assert(index>=0);
    assert(index<=25);
    return index;
}

void print_hist(int *count) {
    for (int i=0;i<LETTERS; i++) {
        printf("%c\t", i+'a');
        for (int j=0; j<count[i]; j++) {
            putchar('x');
        }
        putchar('\n');
    }
}


int main(void) {
    int c = 0;
    int count[LETTERS];
    int index=0;

    for (int i=0;i<LETTERS; i++) {
        count[i] = 0;
    }

    while ((c=getchar()) != EOF) {
        if (is_word_char(c)) {
            index = char_index(c);
            count[index]++;
        }
    }

    print_hist(count);
    return 0;
}
