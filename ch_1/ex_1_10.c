#include <stdio.h>

void main()
{
    char c;

    while((c = getchar()) != EOF){
        if(c == ' ')
            printf("\\b");
        else if(c == '\t')
            printf("\\t");
        else if(c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}