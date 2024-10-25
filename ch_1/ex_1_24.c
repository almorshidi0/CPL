#include <stdio.h>

/* print the folded lines */
int main()
{
    char c;
    int parentheses = 0, braces = 0, brackets = 0;
    int lines = 1;
    
    c = getchar();
    while(c != EOF){
        if(c == '\n'){
            lines++;
        }
        else if(c == '"'){
            while(1){
                c = getchar();
                if(c == '\\'){
                    c = getchar();
                    if(c == '"'){
                        //Pass
                    }
                    else if(c == '\n' || c == EOF){
                        printf("Error on line %d: Missing closing double quote.\n", lines);
                        return -1;
                    }
                }
                else if(c == '"'){
                    break;
                }
                else if(c == '\n' || c == EOF){
                    printf("Error on line %d: Missing closing double quote.\n", lines);
                    return -1;
                }
                else{
                    //Pass
                }
            }
        }
        else if(c == '\''){
            c = getchar();
            if(c == '\\'){
                c = getchar();
                if(c == '\n' || c == EOF){
                    printf("Error on line %d: Missing closing single quote.\n", lines);
                    return -1;
                }
            }
            else if(c == '\n' || c == EOF){
                printf("Error on line %d: Missing closing single quote.\n", lines);
                return -1;
            }
            else{
                //Pass
            }
            c = getchar();
            if(c == '\''){
                //Pass
            }
            else{
                printf("Error on line %d: Missing closing single quote\n", lines);
                return -1;
            }
        }
        else if(c == '/'){
            c = getchar();
            if(c == '*'){
                while(1){
                    c = getchar();
                    if(c == '*'){
                        c = getchar();
                        if(c == '/'){
                            c = getchar();
                            break;
                        }
                    }
                    else if(c == EOF){
                        printf("Error: Unclosed block comment.\n");
                        return -1;
                    }
                }
            }
            else if(c == '/'){
                while(1){
                    c = getchar();
                    if(c == '\n'){
                        break;
                    }
                    else if(c == EOF){
                        printf("Error: Unclosed block comment.\n");
                        return -1;
                    }
                }
            }
            else{
                //Pass
            }
        }
        else if(c == '('){
            parentheses++;
        }
        else if(c == ')'){
            parentheses--;
        }
        else if(c == '{'){
            braces++;
        }
        else if(c == '}'){
            braces--;
        }
        else if(c == '['){
            brackets++;
        }
        else if(c == ']'){
            brackets--;
        }
        else{
            //Pass
        }
        c = getchar();
    }
    if(parentheses != 0){
        printf("Parentheses mismatch (total: %d)\n", parentheses);
        return -1;
    }
    if(braces != 0){
        printf("Braces mismatch (total: %d)\n", braces);
        return -1;
    }
    if(brackets != 0){
        printf("Brackets mismatch (total: %d)\n", brackets);
        return -1;
    }
    printf("\n");

    return 0;
}