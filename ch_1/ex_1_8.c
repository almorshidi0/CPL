#include <stdio.h>

void main(){
    char c;
    int blanks, tabs, new_lines;

    blanks = tabs = new_lines = 0;
    while((c = getchar()) != EOF){
        if (c == ' ')
            blanks++;
        else if (c == '\t')
            tabs++;
        else if (c == '\n')
            new_lines++;
    }
    printf("%-6d\t%-4d\t%-9d\n", blanks, tabs, new_lines);
}