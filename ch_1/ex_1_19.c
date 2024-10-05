#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int getline(char line[], int maxline);
void reverse(char to[], char from[], int len);

/* print the reversed line */
int main(){
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char reversed[MAXLINE];  /* reversed line saved here */
    
    max = 0;
    while((len = getline(line, MAXLINE)) > 0){
        reverse(reversed, line, len);
        printf("%s", reversed);
    }
    
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim){
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
            s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

/* reverse: reverse 'from' into 'to'; assume to is big enough */
void reverse(char to[], char from[], int len){
    int i;

    i = 0;
    while ((to[i] = from[len - i - 2]) && i < len - 1)
        ++i;
    to[++i] = '\n';
    to[++i] = '\0';
}