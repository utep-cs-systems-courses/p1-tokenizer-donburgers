#include <stdio.h>
#include <stdlib.h>
#include "history.h"

// Function to create a copy of the string
char* str_copy(char* str) {
    // Allocate memory for the copy
    char* copy = malloc(sizeof(char) * (str_length(str) + 1));
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        copy[i] = str[i];
    }
    copy[i] = '\0'; // null terminate the copy
    return copy;
}

// Function to find the length of the string
int str_length(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Initialize the linked list to keep the history.
List* init_history(){
    List* history = (List*)malloc(sizeof(List));
    history->root = NULL;
    return history;
}

// Add a history item to the end of the list.
void add_history(List *list, char *str){
    Item* newItem = (Item*)malloc(sizeof(Item));
    newItem->str = str_copy(str); // make a copy of the string
    newItem->next = NULL;

    if(list->root == NULL){
        newItem->id = 1;
        list->root = newItem;
    } else {
        Item* temp = list->root;
        int id = 1;
        while(temp->next != NULL){
            temp = temp->next;
            id++;
        }
        newItem->id = id+1;
        temp->next = newItem;
    }
}

// Retrieve the string stored in the node where Item->id == id.
char *get_history(List *list, int id){
    Item* temp = list->root;
    while(temp != NULL){
        if(temp->id == id){
            return temp->str;
        }
        temp = temp->next;
    }
    return NULL;
}

// Print the entire contents of the list.
void print_history(List *list){
    Item* temp = list->root;
    while(temp != NULL){
        printf("Id: %d, String: %s\n", temp->id, temp->str);
        temp = temp->next;
    }
}

// Free the history list and the strings it references.
void free_history(List *list){
    Item* temp = list->root;
    while(temp != NULL){
        Item* next = temp->next;
        free(temp->str);
        free(temp);
        temp = next;
    }
    free(list);
}
