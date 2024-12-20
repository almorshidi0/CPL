#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int  our_getline(char line[], int max);

    sum = 0;
    while(our_getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));

    return 0;
}

/*  our_getline: get line into s, return length */
int  our_getline(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

double atof(char s[])
{
    double val = 0.0, power = 0.0, epower = 0.0;
    int i = 0, sign = 0, esign = 0;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;
    esign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (epower = 1.0; isdigit(s[i]); i++)
        epower = 10.0 * epower + (s[i] - '0');
    while(epower > 0){
        power = (esign < 0)?  power * 10 : power / 10;
        epower--;
    }
    
    return sign * val / power;
}