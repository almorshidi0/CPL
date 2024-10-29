#include <stdio.h>

void rec_itoa(int n, char s[]);

int main()
{
    int num = 21474;
    char result[20];

    rec_itoa(num, result);
    printf("%d -> \t%s\n", num, result);
    
    return 0;
}

/* rec_itoa: convert n to characters in s recursively */
void rec_itoa(int n, char s[])
{
    static int i = 0;

    if(n < 0){ /* record sign */
        s[i++] = '-';
        n = -n; /* make n positive */
    }
    if(n / 10)
        rec_itoa(n / 10, s);
    s[i++] = (n % 10) + '0';
    s[i] = '\0';
}