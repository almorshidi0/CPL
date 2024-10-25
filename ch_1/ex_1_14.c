#include <stdio.h>

#define ALPHABET_SIZE   ('z' - 'a' + 1)

void main(int argc, char **argv)
{
    if(argc == 2){
        char c = 0, index = 0, greatest_char_frequency = 0;
        char char_frequency[ALPHABET_SIZE] = {0};

        while((c = getchar()) != EOF){
            if(c >= 'A' && c <= 'Z'){
                if(++char_frequency[c - 'A'] > greatest_char_frequency)
                    greatest_char_frequency = char_frequency[c - 'A'];
            }
            else if(c >= 'a' && c <= 'z'){
                if(++char_frequency[c - 'a'] > greatest_char_frequency)
                    greatest_char_frequency = char_frequency[c - 'a'];
            }
        }

        if((argv[1][0] == 'h')){
            index = 0;
            while(index < ALPHABET_SIZE){
                printf("\n%c%c\t", 'A' + index, 'a' + index);
                while(char_frequency[index]--){
                    printf("# ");
                }
                index++;
            }
        }
        else if((argv[1][0] == 'v')){
            char lines = 0;

            if(greatest_char_frequency > 0){
                printf("\n");
                lines = greatest_char_frequency + 1;
                while(lines > 0){
                    index = 0;
                    while(index < ALPHABET_SIZE){
                        if(lines == 1)
                            printf("%c%c ", 'A' + index, 'a' + index);
                        else if(char_frequency[index] >= lines - 1)
                            printf(" # ");
                        else
                            printf("   ");
                        index++;
                    }
                    printf("\n");
                    lines--;
                    if(lines == 1)
                        printf("\n");
                }
            }
        } 
        else
            printf("\nUsage: ./%s <h or v>\n", argv[0]);
    }
    else
        printf("\nUsage: ./%s <h or v>\n", *argv);
}