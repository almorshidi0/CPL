#include <stdio.h>
#define MAXLINE 1000

void escape(char to[], char from[]);
void unescape(char to[], char from[]);

int main()
{
    int len;
    char line[MAXLINE]  = "Hello,\tworld!\n";
    char escaped[MAXLINE];
    char unescaped[MAXLINE];

    printf("%s\n", line);
    escape(escaped, line);
    printf("%s\n", escaped);
    unescape(unescaped, escaped);
    printf("%s\n", unescaped);
    
    return 0;
}

void escape(char to[], char from[])
{
    int i = 0, j = 0;

    while((to[j] = from[i]) != '\0'){
        switch(from[i]){
            case '\t':
                to[j] = '\\';
                ++j;
                to[j] = 't';
                break;
            case '\n':
                to[j] = '\\';
                ++j;
                to[j] = 'n';
                break;
        }
        ++i;
        ++j;
    }
}

void unescape(char to[], char from[])
{
    int i = 0, j = 0;

    while((to[j] = from[i]) != '\0'){
        if(from[i] == '\\'){
            switch(from[i + 1]){
                case 't':
                    to[j] = '\t';
                    ++i;
                    break;
                case 'n':
                    to[j] = '\n';
                    ++i;
                    break;
            }
        }
        ++i;
        ++j;
    }
}