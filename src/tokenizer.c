#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int space_char(char c){
    return (c == ' ' || c == '\t');
}

int non_space_char(char c){
    return (c != ' ' && c != '\t' && c != '\0');
}

char *token_start(char *str){
    while(space_char(*str) && *str != '\0')
        str++;
    return str;
}

char *token_terminator(char *token){
    while(non_space_char(*token) && *token != '\0')
        token++;
    return token;
}

int count_tokens(char *str){
    int count = 0;
    char *start = token_start(str);
    while(*start != '\0'){
        start = token_terminator(start);
        start = token_start(start);
        count++;
    }
    return count;
}

char *copy_str(char *inStr, short len){
    char *outStr = malloc((len+1) * sizeof(char));
    strncpy(outStr, inStr, len);
    outStr[len] = '\0';
    return outStr;
}

char **tokenize(char* str){
    int token_count = count_tokens(str);
    char **tokens = malloc((token_count + 1) * sizeof(char*));

    char *start = str;
    char *end;
    for(int i = 0; i < token_count; i++){
        start = token_start(start);
        end = token_terminator(start);
        tokens[i] = copy_str(start, end - start);
        start = end;
    }
    tokens[token_count] = NULL;
    return tokens;
}

void print_tokens(char **tokens){
    for(int i = 0; tokens[i] != NULL; i++){
        printf("%s\n", tokens[i]);
    }
}

void free_tokens(char **tokens){
    for(int i = 0; tokens[i] != NULL; i++){
        free(tokens[i]);
    }
    free(tokens);
}
