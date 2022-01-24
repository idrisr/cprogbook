#include <stdio.h>
#define MAXLINE  1000

void print_line(char line[]) {
    printf("%s", line);
}

int getlime(char s[], int lim) {
    // read a line, put it into a buffer
    // return the length
    int c, i;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c=='\n') {
        s[i]=c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main() {
    int len;
    char line[MAXLINE];

    while ((len=getlime(line, MAXLINE)) > 0) {
        if (len>=80) {
            print_line(line);
        }
    }
    return 0;
}
