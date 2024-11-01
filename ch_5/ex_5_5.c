#include <stdio.h>

void my_strncpy(char *s, const char *t, int n);
void my_strncat(char *s, const char *t, int n);
int my_strncmp(const char *s, const char *t, int n);

int main() {
    char s1[20];
    char s2[20] = "Hello";
    char s3[20] = "Hello, world!";
    
    // Testing my_strncpy
    my_strncpy(s1, s2, 3);
    printf("my_strncpy(s1, s2, 3) -> s1: %s\n", s1); // Expected: "Hel"
    
    my_strncpy(s1, s3, 10);
    printf("my_strncpy(s1, s3, 10) -> s1: %s\n", s1); // Expected: "Hello, wor"
    
    // Testing my_strncat
    my_strncpy(s1, "Hello", 20);  // Start with "Hello" in s1
    my_strncat(s1, " World", 3);
    printf("my_strncat(s1, \" World\", 3) -> s1: %s\n", s1); // Expected: "Hello Wo"
    
    my_strncat(s1, "ld!", 5);
    printf("my_strncat(s1, \"ld!\", 5) -> s1: %s\n", s1); // Expected: "Hello Wold!"
    
    // Testing my_strncmp
    int cmp1 = my_strncmp("Hello", "Hello", 5);
    printf("my_strncmp(\"Hello\", \"Hello\", 5) -> %d\n", cmp1); // Expected: 0

    int cmp2 = my_strncmp("Hello", "Helium", 3);
    printf("my_strncmp(\"Hello\", \"Helium\", 3) -> %d\n", cmp2); // Expected: 0 (first 3 chars match)

    int cmp3 = my_strncmp("Hello", "Helium", 5);
    printf("my_strncmp(\"Hello\", \"Helium\", 5) -> %d\n", cmp3); // Expected: non-zero (first 5 chars don't match)

    return 0;
}

void my_strncpy(char *s, const char *t, int n)
{
    int i = 0;

    while((i < n) && ((*(s + i) = *(t + i)) != '\0'))
        i++;
    while (i < n) {  // Pad with '\0' if t has fewer than n characters
        *(s + i++) = '\0';
    }
}

void my_strncat(char *s, const char *t, int n)
{
    int i, j;

    i = j =  0;
    while(*(s + i) != '\0') /* find end of s */
        i++;
    while((j < n) && ((*(s + i++) = *(t + j++)) != '\0'))
        ;
    *(s + i) = '\0';
}

int my_strncmp(const char *s, const char *t, int n)
{
    int i = 0;

    while((i < n) && (*(s + i) == *(t + i))){
        if (s[i] == '\0')
            return 0;
        i++;
    }
    if(i == n)
        return 0;

    return *(s + i) - *(t + i);
}