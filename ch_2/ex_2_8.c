#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
    printf("%d\n", rightrot(241, 3));

    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    return (x >> n) | (x << ((8 * sizeof(x)) - n));
}