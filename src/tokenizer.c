#include <stdio.h>
#include <stdlib.h>
#include <tokenizer.h>

int space_char(char c){
    // return 1 if c is a space or tab, otherwise 0
    return (c == '\t' || c == ' ') ? 1 : 0;
}

int non_space_char(char c){
    // return 1 if c is neither a space nor a tab, otherwise 0
    return (c != '\t' && c != ' ') ? 1 : 0;
}


char *word_start(char *str){
    // Loop until we reach end of string
    while (*str != '\0'){
        // If the current character is not a space, return the current position
        if (non_space_char(*str)){
            return str;
        }
        // Move to the next character
        str++;
    }
    // If we've reached this point, all characters were spaces, so return a pointer to the null terminator
    return str;
}

char *copy_str(char *inStr, short len){
    // Allocate memory for new string
    char *strCopy = malloc((len+1) * sizeof(char));
    // Check if malloc succeeded
    if(strCopy == NULL) {
        fprintf(stderr, "Failed to allocate memory in copy_str\n");
        return NULL;
    }
    // Copy characters from inStr to strCopy
    for (int i = 0; i < len; i++){
        strCopy[i] = inStr[i];
    }
    // Add null terminator to the end of the new string
    strCopy[len] = '\0';
    // Return the new string
    return strCopy;
}


void print_tokens(char **tokens){
    // Loop until we encounter NULL (indicating the end of the tokens)
    while (*tokens != NULL){
        // Print the current token followed by a newline
        printf("%s\n", *tokens);
        // Move to the next token
        tokens++;
    }
}
