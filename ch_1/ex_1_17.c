#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */
#define PRINTABLE_LINE 80

int getline(char line[], int maxline);

/* print the longest input line */
int main(){
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */
    
    while((len = getline(line, MAXLINE)) > 0)
        if(len > PRINTABLE_LINE)
            printf("%s\n", line);
    
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim){
    int c, i;

    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i){
        if(i < lim - 2)
            s[i] = c;
    }
    if(i < lim - 1){
        if(c == '\n'){
            s[i] = c;
            ++i;
        }
        s[i] = '\0';
    }
    else
        s[lim - 1] = '\0';

    return i;
}