#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(){
    printf("%d\n", setbits(240, 6, 4, 7));

    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
    x &= ~(~(~0 << n) << (p - n + 1));
    unsigned mask = ((y & ~(~0 << n)) << (p - n + 1));

    return (x | mask);
}