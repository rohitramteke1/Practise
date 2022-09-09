#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main(){
    
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));    
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));    
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));    

    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = NULL;

    // Normal traversing
    struct Node *temp = head;
    while(temp != NULL) {
        printf(" Data: %d\n", temp->data);
        temp = temp->next;
    }

    // Reverse order traversing
    temp = third;
    while(temp != NULL) {
        printf(" Data: %d\n", temp->data);
        temp = temp->prev;
    }

    
    return 0;
}