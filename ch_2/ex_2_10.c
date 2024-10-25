#include <stdio.h>

char lower(char c);

int main()
{
    printf("%c\n", lower('c'));

    return 0;
}

char lower(char c)
{
    (c >= 'A' && c <= 'Z') ? c += 'a' - 'A' : c;

    return c;
} 