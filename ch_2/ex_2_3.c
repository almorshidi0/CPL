#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int my_getline(char line[], int maxline);
int htoi(char line[], int len);

int main(){
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */
    int n = 0;
    
    while((len = my_getline(line, MAXLINE)) > 0){
        if(len > 0){
            n = htoi(line, len);
            if(n >= 0)
                printf("%d\n", n);
        }
    }
    
    return 0;
}

/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim){
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

int htoi(char line[], int len){
    int i =0;
    int n = 0;

    if(line[0] == '0' && (line[1] == 'x' || line[1] == 'X'))
        i = 2;
    while(line[i] != '\0' && line[i] != '\n'){
        if((line[i] >= '0') & (line[i] <= '9')){
            n = n * 16 + line[i] - '0';
        }
        else if((line[i] >= 'A') & (line[i] <= 'F'))
            n = n * 16 + 10 + (line[i] - 'A');
        else if((line[i] >= 'a') & (line[i] <= 'f'))
            n = n * 16 + 10 + (line[i] - 'a');
        i++;
    }

    return n;
}