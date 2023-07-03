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

void remove_newline(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            return;
        }
        i++;
    }
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
    while(1){
        printf("Enter an option: ");
        if(fgets(input, MAX, stdin) == NULL) {
            puts("Error reading input.");
            continue;
        }
        // remove newline character
        remove_newline(input);

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

            // Get user input
            if(fgets(input, MAX, stdin) == NULL) {
                puts("Error reading input.");
                continue;
            }
            // remove newline character
            remove_newline(input);

            // Tokenizer loop
            while(1){
                // Check for empty input
                if(input[0] == '\0'){
                    puts("Empty String");
                    break;
                }
                else{
                    // Print tokens and add input to history
                    print_tokens(tokens);
                    add_history(list, copy_str(input, my_strlen(input)));
                }
            }
            free_tokens(tokens);
            tokens = NULL;
        }
        // Option 2: History
        else if(*tokens[0] == '2'){
            print_history(list);
        }
        // Option: Quit
        else if(*tokens[0] == 'q'){
            break;
        }
        // Invalid option
        else{
            puts("Invalid input");
        }

        if(tokens != NULL){
            free_tokens(tokens);
            tokens = NULL;
        }
    }

    free_history(list);
    return 0;
}
