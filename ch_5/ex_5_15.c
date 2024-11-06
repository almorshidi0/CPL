#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void my_qsort(void *lineptr[], int left, int right, const int reverse, int fold, int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0, reverse = 0, fold = 0;
    char c = 0;

    while(--argc > 0 && (*++argv)[0] == '-'){
        while(c = *++argv[0]){
            switch(c){
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                case 'f':
                    fold = 1;
                    break;
                default:
                    printf("qsort: illegal option %c\n", c);
                    argc = 0;
                    return -1;
            }
        }
    }
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        my_qsort((void**) lineptr, 0, nlines-1, reverse, fold, (int (*)(void*,void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else{
        printf("input too big to sort\n");
        return 1;
    }
}

/* my_qsort: sort v[left]...v[right] into increasing order */
void my_qsort(void *v[], int left, int right, const int reverse, int fold, int (*comp)(void *, void *))
{
    int i, last, cmp;
    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    cmp = (*comp)(v[left], v[(left + right)/2]);
    if(fold)
        cmp = ((cmp == 'A' - 'a') || (cmp == 'a' - 'A')) ? 0 : cmp;
    (cmp == 0) ? cmp: swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++){
        cmp = (*comp)(v[i], v[left]);
        if(fold)
            cmp = ((cmp == 'A' - 'a') || (cmp == 'a' - 'A')) ? 0 : cmp;
        if(reverse ? (cmp > 0) : (cmp < 0))
            swap(v, ++last, i);
    }
    swap(v, left, last);
    my_qsort(v, left, last-1, reverse, fold, comp);
    my_qsort(v, last+1, right, reverse, fold, comp);
}

#include <stdlib.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j)
{
    void *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define MAXLEN 1000 /* max length of any input line */

int our_getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    
    nlines = 0;
    while ((len = our_getline(line, MAXLEN)) > 0){
        if ((nlines >= maxlines) || ((p = alloc(len)) == NULL))
            return -1;
        else{
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    }
    else /* not enough room */
        return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
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