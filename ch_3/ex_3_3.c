#include <stdio.h>
#define MAXLINE 1000

void expand(char from[], char to[]);
int is_letter_or_digit(char c);

int main(){
    int len;
    char line[MAXLINE]  = "a-z a-a a-b-c a-z0-9 -a-z A-Z a-f a-d-g - --";
    char expanded[MAXLINE];

    printf("%s\n", line);
    expand(line, expanded);
    printf("%s\n", expanded);
    
    return 0;
}

void expand(char from[], char to[]){
    int i, j;

    i = 0;
    j = 0;
    while(from[i] != '\0'){
        if((i != 0) && (from[i] == '-') && is_letter_or_digit(from[i - 1]) && is_letter_or_digit(from[i + 1]) && (from[i - 1] <= from[i + 1])){
            while((to[j] = to[j - 1] + 1) < from[i + 1])
                j++;
            if(from[i - 1] == from[i + 1])
                j--;
            i++;
        }
        else{
            to[j] = from[i];
        }
        i++;
        j++;
    }
    to[j] = '\0';
}

int is_letter_or_digit(char c){
    if(((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9')))
        return 1;
    return 0;
}