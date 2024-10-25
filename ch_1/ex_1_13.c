#include <stdio.h>

#define IN  0   /* inside a word */
#define OUT 1   /* outside a word */
#define MAX_WORD_LENGTH 20 /* Maximum characters in a word*/
#define MAX_WORDS 100 /* Maximum number of words */

void main(int argc, char **argv)
{
    if(argc == 2){
        char c = 0, state = 0;
        if((argv[1][0] == 'h')){
            state = OUT;
            while((c = getchar()) != EOF){
                if((c == ' ' || c == '\n' || c == '\t')){
                    if(state != OUT){
                        state = OUT;
                        printf("\n");
                    }
                }
                else{
                    state = IN;
                    printf("#");
                }
            }
        }
        else if((argv[1][0] == 'v')){
            char index = 0, greatest_word_length = 0, lines = 0;
            char word_length[MAX_WORDS] = {0};
            char words_per_length[MAX_WORD_LENGTH] = {0};

            state = OUT;
            while((c = getchar()) != EOF){
                if((c == ' ' || c == '\n' || c == '\t')){
                    if(state != OUT){
                        state = OUT;
                        words_per_length[word_length[index] - 1]++;
                        index++;
                    }
                }
                else{
                    state = IN;
                    if(word_length[index] < 20)
                        word_length[index]++;
                }
            }

            index = MAX_WORD_LENGTH - 1;
            while(index >= 0){
                if(words_per_length[index] != 0){
                    greatest_word_length = index + 1;
                    break;
                }
                index--;
            }

            if(greatest_word_length > 0){
                printf("\n");
                lines = greatest_word_length;
                while(lines > 0){
                    index = 0;
                    while(index < MAX_WORDS){
                        if(word_length[index] != 0){
                            if(word_length[index] >= lines)
                                printf("#");
                            else
                                printf(" ");
                            index++;
                        }
                        else
                            break;
                    }
                    printf("\n");
                    lines--;
                }
            }
        } 
        else
            printf("\nUsage: ./%s <h or v>\n", argv[0]);
    }
    else
        printf("\nUsage: ./%s <h or v>\n", *argv);
}