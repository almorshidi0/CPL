#include <stdio.h>

void main(){
    char c;
    char lastc = 'a';

    while((c = getchar()) != EOF){
        if(c != ' ')
            putchar(c);
        else if(c == ' '){
            if(lastc != ' ')
                putchar(c);
        }
        lastc = c;
    }
}