#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXLINE 1000    /* maximum input line length */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int our_getline(void);
int getop(char []);
void push(double);
double pop(void);

/* reverse Polish notation calculator */ 
int main()
{
    int type, len;
    double op2;
    char s[MAXOP];
    int line[MAXLINE] = {0};

    while((len = our_getline()) > 0){
        while((type = getop(s)) != '\0' && type != EOF){
            switch(type){
                case NUMBER:
                    push(atof(s));
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if(op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                case '\n':
                    printf("\t%.8g\n", pop());
                    break;
                default:
                    printf("error: unknown command %s\n", s);
                    break;
            }
        }        
    }

    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* our_getline: read a line into s, return length */
int our_getline(void)
{
    int c, i;

    bufp = 0;
    for(i = 0; i < BUFSIZ - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
            buf[i] = c;
    if(c == '\n'){
        buf[i] = c;
        ++i;
    }
    buf[i] = '\0';

    return i;
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i = 0, c = 0;

    while((s[0] = c = buf[bufp++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if(isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = buf[bufp++]))
            ;
    if(c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = buf[bufp++]))
            ;
    s[i] = '\0';
    if(c != EOF)
        bufp--;

    return NUMBER;
}