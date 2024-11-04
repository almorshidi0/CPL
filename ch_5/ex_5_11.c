/* I don't know what it wants me to do exactly, so I'll just jump ahead */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000    /* maximum input line length */
#define TAB_SIZE 8
#define TAB_STOP (TAB_SIZE - 1)
#define YES 1
#define NO 0

int our_getline(char line[], int maxline);
void entab(char to[], char from[], int len);
void settab(char *to, int len, char argc, char **argv);

/* print the entabbed line */
int main(char argc, char **argv)
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char entabbed[MAXLINE];  /* entabbed line saved here */
    
    max = 0;
    while((len = our_getline(line, MAXLINE)) > 0){
        settab(entabbed, MAXLINE, argc, argv);
        entab(entabbed, line, len);
        printf("%s", entabbed);
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

/* entab: entab 'from' into 'to'; assume to is big enough */
void entab(char to[], char from[], int len)
{
    int c, pos, i;
    int nb = 0;
    int nt = 0;

    for(pos = 0, i = 0; (c = from[pos]) != EOF && c != '\0'; pos++){
        if(c == ' '){
            if(to[pos] == NO)
                ++nb;
            else{
                nb = 0;
                ++nt;
            }
        }
        else{
            for( ; nt > 0; nt--)
                to[i++] = '\t';
            if(c == '\t')
                nb = 0;
            else{
                for( ; nb > 0; nb--)
                    to[i++] = ' ';
            }
            to[i++] = c;
            if(c == '\n')
                break;
        }
    }
}

void settab(char *to, int len, char argc, char **argv)
{
    int i, pos;
    char argc_copy;
    char **argv_copy;

    argc_copy = argc;
    argv_copy = argv;
    if(argc < 2){
        for(i = 0; i < len; i++){
            if(i % TAB_SIZE == TAB_STOP)
                *(to + i) = YES;
            else
                *(to + i) = NO;
        }
    }
    else{
        for(i = 0; i < len; i++)
            *(to + i) = NO;
        while(--argc){
            if(((pos = atoi(*++argv)) < len) && (pos > 0))
                *(to + pos) = YES;
        }
    }
}