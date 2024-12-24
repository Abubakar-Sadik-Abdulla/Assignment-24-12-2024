#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;


void push(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}


void displayStack() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    displayStack();
    return 0;
}
