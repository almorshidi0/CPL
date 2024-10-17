#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int my_getline(char line[], int maxline);
void squeeze(char line[], char chars[]);

int main(){
    int len1, len2;                /* current line length */
    char line[MAXLINE];     /* current input line */
    char chars[MAXLINE];
    
    while((len1 = my_getline(line, MAXLINE)) && (len2 = my_getline(chars, MAXLINE))){
        if(len1 > 0 && len2 > 0){
            squeeze(line, chars);
            printf("%s\n", line);
        }
    }
    
    return 0;
}

/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim){
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
            s[i] = c;
    s[i] = '\0';

    return i;
}

void squeeze(char line[], char chars[]){
    int i, j;
    int k;

    i = j = 0;
    while(line[i] != '\0'){
        k = 0;
        while(1){
            if (line[i] == chars[k]){
                break;
            }
            if(chars[k++] == '\0'){
                line[j++] = line[i];
                break;
            }
        }
        i++;
    }
    line[j] = '\0';
}