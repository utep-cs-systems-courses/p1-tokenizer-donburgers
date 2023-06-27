#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 100

int my_strlen(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main(){
    // Buffer for user input
    char input[MAX];
    // Initialize history list
    List *list = init_history();
    // Pointer to hold tokens
    char **tokens = NULL;




    printf("#######\n");    
    printf("   #     ####  #    # ###### #    # # ###### ###### ##### \n");
    printf("   #    #    # #   #  #      ##   # #     #  #      #    #\n");
    printf("   #    #    # ####   #####  # #  # #    #   #####  #    #\n");
    printf("   #    #    # #  #   #      #  # # #   #    #      #####\n");
    printf("   #    #    # #   #  #      #   ## #  #     #      #   #\n");
    printf("   #     ####  #    # ###### #    # # ###### ###### #    #\n");
    printf("\n");
    printf("Created by: Brian Mata");
    printf("\n");

    // Main menu loop
    // Main menu loop
    while(1){
        // ... (display menu and get user input)

        // Tokenize input
        tokens = tokenize(input);

        // Check for tokenize error
        if(tokens == NULL) {
            puts("Tokenize failed.");
            continue;
        }

        // Option 1: Tokenize
        if(*tokens[0] == '1'){
            puts("Tokenizer");
            puts("Enter a string");

            // Tokenizer loop
            while(1){
                // ... (get user input and tokenize it)

                // Check for empty input
                if(*(tokens[0]+1) == '\0'){
                    puts("Empty String");
                    break;
                }
                else{
                    // Print tokens and add input to history
                    print_tokens(tokens);
                    add_history(list, copy_str(input, my_strlen(input))); // minus 1 to remove the newline character
                }
                free_tokens(tokens);
            }
        }
        // Option 2: History
        else if(*tokens[0] == '2'){
            // ... (display history menu)

            // History loop
            while(1){
                // ... (get user input and tokenize it)

                // Sub-option 1: View History
                if(*tokens[0] == '1'){
                    // ... (print history)
                }
                // Sub-option: Quit
                else if(*tokens[0] == 'q'){
                    // ... (quit to main menu)
                }
                // Sub-option: History by ID
                else{
                    // Get history item
                    char *history_item = get_history(list, atoi(tokens[0]));
                    // Check for error
                    if (history_item != NULL) {
                        printf("%s", history_item);
                    } else {
                        puts("History item not found.");
                    }
                }
                free_tokens(tokens);
            }
        }
        // Option: Quit
        else if(*tokens[0] == 'q'){
            // ... (free history and quit)
        }
        // Invalid option
        else{
            puts("Invalid input");
        }
        free_tokens(tokens);
    }
}
