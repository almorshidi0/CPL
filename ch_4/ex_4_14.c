#include <stdio.h>

#define swap(t, x, y)   {\
                            t tmp;\
                            tmp = x;\
                            x = y;\
                            y = tmp;\
                        }

int main()
{
    int x, y;
    
    x = 4;
    y = 5;
    swap(int, x, y)
    printf("%d\t%d\n", x, y);
    
    return 0;
}