#include <stdio.h>

unsigned rightrot(unsigned x, int n);

void main(void){
    printf("%d\n", rightrot(241, 3));
}

unsigned rightrot(unsigned x, int n){
    return (x >> n) | (x << ((8 * sizeof(x)) - n));
}