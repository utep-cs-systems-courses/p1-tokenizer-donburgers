#include <stdio.h>
#include <stdlib.h>
#include "history.h"

// Initialize the linked list to keep the history.
List* init_history() {
    // Allocate space for the List struct and set the root to NULL
    List* list = (List*)malloc(sizeof(List));
    list->root = NULL;
    return list;
}

// Add a history item to the end of the list.
void add_history(List *list, char *str) {
    // Allocate space for the new item, set its string and next fields
    Item* new_item = (Item*)malloc(sizeof(Item));
    new_item->str = str;
    new_item->next = NULL;

    if(list->root == NULL) {
        // If the list is empty, set the new item as the root
        new_item->id = 1;
        list->root = new_item;
    } else {
        // If the list is not empty, add the new item at the end
        Item* temp = list->root;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        new_item->id = temp->id + 1;
        temp->next = new_item;
    }
}

// Retrieve the string stored in the node where Item->id == id.
char *get_history(List *list, int id) {
    Item* temp = list->root;
    while(temp != NULL) {
        // If the id of the current item matches the requested id, return its string
        if(temp->id == id) {
            return temp->str;
        }
        temp = temp->next;
    }
    // If no matching id was found, return NULL
    return NULL;
}

// Print the entire contents of the list.
void print_history(List *list) {
    Item* temp = list->root;
    while(temp != NULL) {
        printf("%d: %s\n", temp->id, temp->str);
        temp = temp->next;
    }
}

// Free the history list and the strings it references.
void free_history(List *list) {
    Item* current = list->root;
    Item* next;

    while(current != NULL) {
        next = current->next;
        // Free the string and the item itself
        free(current->str);
        free(current);
        current = next;
    }
    // Finally, free the list struct
    free(list);
}
