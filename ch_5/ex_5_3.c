#include<stdio.h>

void my_strcat(char *s, char *t);

int main()
{
    char s[14] = "hello";

    my_strcat(s, ", world!");
    printf("%s\n", s);
}

/* strcat: concatenate t to end of s; s must be big enough */
void my_strcat(char *s, char *t)
{
    int i, j;

    i = j = 0;
    while (*(s + i) != '\0') /* find end of s */
        i++;
    while ((*(s + i++) = *(t + j++)) != '\0') /* copy t */
        ;
}