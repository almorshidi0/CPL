#include <stdio.h>
#define MAXLINE 1000

int our_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(){
    char line[MAXLINE];
    int index = 0;

    while(our_getline(line, MAXLINE) > 0){
        index = strindex(line, pattern);
        if(index >= 0){
            printf("%d\n", index);
        }
    }

    return 0;
}

int our_getline(char s[], int lim){
    int c, i;
    
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

int strindex(char s[], char t[]){
    int i, j, k, index = -1;

    for (i = 0; s[i] != '\0'; i++){
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
        {
            index = i;
        }
    }

    return index;
}