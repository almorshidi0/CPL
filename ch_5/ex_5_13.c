#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define BUFSIZE 10000
#define DEF_TAIL 10

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int maxlines, char *lines_buf, int max);
void writelines(char *lineptr[], int nlines);

int main(char argc, char **argv)
{
    int nlines, n; /* number of input lines read */
    char lines_buf[BUFSIZE];

    if((nlines = readlines(lineptr, MAXLINES, lines_buf, BUFSIZE)) >= 0){
        if(argc < 2){
            if(nlines >= DEF_TAIL)
                writelines(lineptr + (nlines - DEF_TAIL), DEF_TAIL);
            else
                writelines(lineptr, nlines);
        }
        else{
            n = atoi(*++argv);
            if(n <= nlines)
                writelines(lineptr + (nlines - n), n);
            else
                writelines(lineptr, nlines);
        }
        return 0;
    }
    else{
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */

int our_getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *lines_buf, int max)
{
    int len, nlines, buf_i;
    char line[MAXLEN];
    
    nlines = 0;
    buf_i = 0;
    while((len = our_getline(line, MAXLEN)) > 0){
        if(nlines >= maxlines || ((buf_i + len) >= max))
            return -1;
        else{
            line[len-1] = '\0'; /* delete newline */
            strcpy((lines_buf + buf_i), line);
            lineptr[nlines++] = (lines_buf + buf_i);
            buf_i += len;
        }
    }

    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while(nlines--)
        printf("%s\n", *lineptr++);
}


/* our_getline: read a line into s, return length */
int our_getline(char *s, int lim)
{
    int c, i;

    i = 0;
    while(i < lim - 1 && (c = getchar()) != EOF && c != '\n')
        *(s + i++) = c;
    if(c == '\n')
        *(s + i++) = c;
    s[i] = '\0';

    return i;
}