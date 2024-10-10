#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */
#define TAB_SIZE 8
#define TAB_STOP (TAB_SIZE - 1)

int getline(char line[], int maxline);
void entab(char to[], char from[], int len);

/* print the entabbed line */
int main(){
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char entabbed[MAXLINE];  /* entabbed line saved here */
    
    max = 0;
    while((len = getline(line, MAXLINE)) > 0){
        entab(entabbed, line, len);
        printf("%s", entabbed);
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

/* entab: entab 'from' into 'to'; assume to is big enough */
void entab(char to[], char from[], int len){
    int i, j;
    int start, count;
    
    start = -1;
    count = 0;
    for(i = 0, j = 0; i < len - 1 && j < MAXLINE - 2; ++i){
        if(from[i] == ' '){
            if(start == -1){
                start = i;
                count++;
            }
            else if(i % TAB_SIZE == TAB_STOP){
                to[j++] = '\t';
                start = -1;
                count = 0;
            }
            else
                count++;
        }
        else{
            while(count > 0){
                to[j++] = ' ';
                count--;
            }
            to[j++] = from[i];
        }
    }
    to[j++] = '\n';
    to[j++] = '\0';
}