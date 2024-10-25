#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define __USE_XOPEN
#include <math.h> /* for sin(), exp(), and pow() */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void top(void);
void swap(void);
void duplicate(void);
void clear(void);

/* reverse Polish notation calculator */ 
int main()
{
    int type;
    double op1;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
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
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                op1 = pop();
                if (op2 == 0.0)
                    printf("error: zero divisor\n");
                else if(((op2 - (int) op2) != 0.0) || ((op1 - (int) op1) != 0.0))
                    printf("error: modulus operands must be integers\n");
                else
                    push(((int) op1) % ((int) op2));
                break;
            case 'S':
                push(sin(pop() * (M_PI / 180.0)));
                break;
            case 'E':
                push(exp(pop()));
                break;
            case 'P':
                op2 = pop();
                op1 = pop();
                if(((op1 == 0) && (op2 <= 0)))
                    printf("error: zero divisor\n");
                else if((op1 < 0) && ((op2 - (int) op2) != 0.0))
                    printf("error: invalid pow operation\n");
                else
                    push(pow(op1, op2));
                break;
            case 'p':
                top();
                break;
            case 's':
                swap();
                break;
            case 'd':
                duplicate();
                break;
            case 'c':
                clear();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
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

/* top: print top element of the stack */
void top(void)
{
    if(sp > 0)
        printf("\t%.8g\n", val[sp - 1]);
    else
        printf("error: stack empty\n");
}

/* swap: swap top two elements of the stack */
void swap(void)
{
    double tmp;

    if(sp > 1){
        tmp = val[sp - 2];
        val[sp - 2] = val[sp - 1];
        val[sp - 1] = tmp;
    }
    else
        printf("error: stack %s\n", (sp == 0) ? "empty" : "has only one element");
}

/* duplicate: duplicate top element of the stack */
void duplicate(void)
{
    if(sp > 0){
        val[sp] = val[sp - 1];
        sp++;
    }
    else
        printf("error: stack empty\n");
}

/* clear: clear the stack */
void clear(void)
{
    if(sp > 0)
        sp = 0;
    else
        printf("error: stack empty\n");
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    i = 0;
    if (isdigit(c) || c == '-') /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if(s[0] == '-' && s[1] == '\0')
        return '-';

    return NUMBER;
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
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}