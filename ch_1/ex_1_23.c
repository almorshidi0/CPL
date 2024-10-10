#include <stdio.h>

/* print the folded lines */
int main(){
    char c;
    
    while((c = getchar()) != EOF){
        if(c == '"'){
            while((c = getchar()) != '"')
                putchar(c);
            putchar(c);
        }
        else if(c == '/'){
            if((c = getchar()) == '*'){
                while(1){
                    if((c = getchar()) == '*'){
                        if((c = getchar()) == '/')
                            if((c = getchar()) == '\n');
                            break;
                    }
                }
            }
            else if(c == '/'){
                while(1){
                    if((c = getchar()) == '\n'){
                        putchar(c);
                        break;
                    }
                }
            }
            else{
                putchar('/');
                putchar(c);
            }
        }
        else
            putchar(c);
    }
    
    return 0;
}