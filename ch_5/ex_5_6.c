/* I'll be doing only one ;) */
#include <stdio.h>
#include <string.h>

#define ABS(number)  (((number) < 0)? -(number) : (number))

void reverse(char *s, int i ,int j);
void itoa(int n, char *s, int field);

int main()
{
    int num = 21474;
    char result[20];
    itoa(num, result, 8);
    printf("%d -> \t%s\n", num, result);

    num = -48; // Min value for a 32-bit signed integer
    itoa(num, result, 8);
    printf("%d -> \t%s\n", num, result);
    
    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char *s, int field)
{
    int i, sign;

    sign = n;
    i = 0;

    do { /* generate digits in reverse order */
            *(s + i++) = ABS(n % 10) + '0'; /* get next digit */
    } while ((n /= 10) != 0); /* delete it */

    if (sign < 0)
        *(s + i++) = '-';

    while(i < field)
        *(s + i++) = ' ';
    
    *(s + i) = '\0';
    reverse(s, 0 , i - 1);
}

/* reverse: reverse string s in place */
void reverse(char *s, int i, int j)
{
    int tmp;

    if(!(i < j))
        return;

    reverse(s, i + 1, j - 1);
    
    tmp = *(s + i);
    *(s + i) = *(s + j);
    *(s + j) = tmp;
}