#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int our_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */
    
    max = 0;
    while((len = our_getline(line, MAXLINE)) > 0){
        printf("%d\t%s\n", len, line);
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0) /* there was a line */
        printf("%s", longest);
    
    return 0;
}

/* our_getline: read a line into s, return length */
int our_getline(char s[], int lim)
{
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}