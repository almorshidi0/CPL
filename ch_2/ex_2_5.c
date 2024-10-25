#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int my_getline(char line[], int maxline);
int any(char line[], char chars[]);

int main()
{
    int len1, len2;                /* current line length */
    int index = 0;
    char line[MAXLINE];     /* current input line */
    char chars[MAXLINE];
    
    while((len1 = my_getline(line, MAXLINE)) && (len2 = my_getline(chars, MAXLINE))){
        if(len1 > 0 && len2 > 0){
            index = any(line, chars);
            printf("%d\n", index);
        }
    }
    
    return 0;
}

/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
            s[i] = c;
    s[i] = '\0';

    return i;
}

int any(char line[], char chars[])
{
    int i;
    int k;
    int index = -1;

    i = 0;
    while(line[i] != '\0'){
        k = 0;
        while(chars[k] != '\0'){
            if (line[i] == chars[k]){
                index = i;
                break;
            }
            k++;
        }
        if(index != -1)
            break;
        i++;
    }

    return index;
}