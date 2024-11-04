#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define NUMBER '0' /* signal that a number was found */
#define MAXOP 20
char s[MAXOP];

int arg_type(char *arg);
void push(double f);
double pop(void);

int main(int argc, char **argv)
{
    int type, op2;
    if(argc < 2){
        printf("Usage: %s <expression>\n", *argv);
        return -1;
    }
    else{
        while(--argc){
            switch(type = arg_type(*(++argv))){
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
                default:
                    printf("error: unknown command %s\n", s);
                    break;
            }
            if(argc == 1)
                printf("\t%.8g\n", pop());
        }
    }
}

#include <ctype.h>

int arg_type(char *arg)
{
    int i, c;
    
    while((s[0] = c = *arg++) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if(isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = *arg++))
            ;
    if(c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = *arg++))
            ;
    s[i] = '\0';

    return NUMBER;
}

#define MAXVAL 100 /* maximum depth of val stack */

double val[MAXVAL]; /* value stack */
double *sp = val; /* next free stack position */

/* push: push f onto value stack */
void push(double f)
{
    if(sp < (val + MAXVAL))
        *(sp++) = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if(sp > val)
        return *(--sp);
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}