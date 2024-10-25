#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */
#define OUT_MAXLINE 80

int our_getline(char line[], int maxline);
void fold(char to[], char from[], int len);
void copy(char to[], char from[]);

/* print the folded lines */
int main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char folded[MAXLINE];  /* folded lines saved here */
    
    max = 0;
    while((len = our_getline(line, MAXLINE)) > 0){
        printf("%s", line);
    }
    
    return 0;
}

/* our_getline: read a line into s, return length */
int our_getline(char s[], int lim)
{
    int c = 0, i = 0, last_blank = -1, last_line_break = -1;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
        if(c == ' ')
            last_blank = i;
        else if(i - last_line_break == OUT_MAXLINE){
            if(last_blank != -1){
                s[last_blank] = '\n';
                last_line_break = last_blank;
                last_blank = -1;
            }
            else{
                s[i++] = '-';
                s[i++] = '\n';
                s[i] = c;
                last_line_break = i;
            }
        }
    }
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}