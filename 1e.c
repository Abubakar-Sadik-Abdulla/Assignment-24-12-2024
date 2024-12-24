#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};

struct node* head = NULL; 


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtBeginning(int data) {
    struct node* newNode = createNode(data);
    newNode->next = head; 
    head = newNode;     
    printf("Inserted %d at the beginning.\n", data);
}


void insertAtEnd(int data) {
    struct node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode; 
    } else {
        struct node* temp = head;
        while (temp->next != NULL) { 
            temp = temp->next;
        }
        temp->next = newNode; 
    }
    printf("Inserted %d at the end.\n", data);
}


void displayList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    insertAtBeginning(20);
    insertAtBeginning(10);
    displayList();

    insertAtEnd(30);
    insertAtEnd(40);
    displayList();

    return 0;
}
