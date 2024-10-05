#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int getline(char line[], int maxline);
int delete_trailing(char line[], int len);

/* print the longest input line */
int main(){
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */
    
    while((len = getline(line, MAXLINE)) > 0){
        if(len > 0){
            len = delete_trailing(line, len);
            if(len > 0)
                printf("%s", line);
        }
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

int delete_trailing(char line[], int len){
    int c, i;

    i = len - 2;
    while(i >= 0 && (line[i] == ' ' || line[i] == '\t'))
        --i;
    if(i >= 0){
        line[++i] = '\n';
        line[++i] = '\0';
    }

    return ++i;
}