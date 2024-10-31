#include <stdio.h>

#define SIZE 1000

int getfloat(float *pn);

int main(void)
{
    int n, s;
    float array[SIZE];

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;

    printf("storing in n = %d, getint %g\n", n, array[n]);

    for (s = 0; s <= n; s++)
        printf("%g\n", array[s]);

    return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getfloat(float *pn)
{
    int c, sign = 0;
    float power = 1.0;

    while(isspace(c = getch())) /* skip white space */
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c); /* it is not a number */
        return EOF;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-')
        c = getch();
    if(!isdigit(c))
        return EOF;
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if(c == '.'){
        c = getch();
        for(power = 1.0; isdigit(c); c = getch()){
            *pn = 10 * *pn + (c - '0');
            power *= 10;
        }
    }
    *pn = (sign * *pn) / power;
    if(c != EOF)
        ungetch(c);

    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}