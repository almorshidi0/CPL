#include<stdio.h>

int my_strend(char *s, char *t);

int main()
{
    printf("%d\n", my_strend("hello", "world")); // Should print 0
    printf("%d\n", my_strend("hello", "llo"));   // Should print 1
    printf("%d\n", my_strend("hello", "hello")); // Should print 1
    printf("%d\n", my_strend("hello", "o"));     // Should print 1
    printf("%d\n", my_strend("hello", ""));      // Should print 1 (empty t matches)
    printf("%d\n", my_strend("hello", "helloo")); // Should print 0 (t is longer than s)
}

/* strcat: concatenate t to end of s; s must be big enough */
int my_strend(char *s, char *t)
{
    int i, j;

    i = j = 0;
    while(*(s + i) != '\0') /* find end of s */
        i++;
    while(*(t + j) != '\0') /* find end of t */
        j++;
    if(j > i)
        return 0;
    while(j >= 0){
        if(*(s + i--) != *(t + j--))
            return 0;
    }

    return 1;
}