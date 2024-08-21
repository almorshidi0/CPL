#include <stdio.h>
#define IN  0   /* inside a word */
#define OUT 1   /* outside a word */

void main(){
    char c, state, lastc;

    state = OUT;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            if(state != OUT){
                state = OUT;
                printf("\n");
            }
        }
        else if(state == OUT){
            state = IN;
            printf("%c", c);
        }
        else{
            printf("%c", c);
        }
    }
}