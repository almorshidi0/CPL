#include <stdio.h>

int bitcount(unsigned x);

int main(){
    printf("%d\n", bitcount(241));

    return 0;
}

int bitcount(unsigned x){
    int b = 0;

    while(x){
        x &= (x-1);
        b++;
    }
    
    return b;
}