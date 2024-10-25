#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */
#define TAB_SIZE 8

int our_getline(char line[], int maxline);
void detab(char to[], char from[], int len);

/* print the detabbed line */
int main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char detabbed[MAXLINE];  /* detabbed line saved here */
    
    max = 0;
    while((len = our_getline(line, MAXLINE)) > 0){
        detab(detabbed, line, len);
        printf("%s", detabbed);
    }
    
    return 0;
}

/* our_getline: read a line into s, return length */
int our_getline(char s[], int lim)
{
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

/* detab: detab 'from' into 'to'; assume to is big enough */
void detab(char to[], char from[], int len)
{
    int i, j;

    for(i = 0, j = 0; i < len - 1 && j < MAXLINE - 2; ++i){
        if(from[i] == '\t'){
            to[j] = ' ';
            ++j;
            while(j % TAB_SIZE > 0){
                to[j] = ' ';
                ++j;
            }
        }
        else{
            to[j] = from[i];
            ++j;
        }
    }
    to[j++] = '\n';
    to[j++] = '\0';
}