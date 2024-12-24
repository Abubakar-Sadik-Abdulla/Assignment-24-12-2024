#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char device[20];
    int priority;
    struct node* next;
};

struct node* head = NULL;


void insertRequest(char* device, int priority) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->device, device);
    newNode->priority = priority;
    newNode->next = NULL;

    if (head == NULL || head->priority > priority) {
        newNode->next = head;
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


void handleRequest() {
    if (head == NULL) {
        printf("No requests to handle.\n");
        return;
    }
    struct node* temp = head;
    printf("Handling request for: %s (Priority: %d)\n", temp->device, temp->priority);
    head = head->next;
    free(temp);
}


void displayRequests() {
    if (head == NULL) {
        printf("No pending requests.\n");
        return;
    }
    printf("Pending Requests (in priority order):\n");
    struct node* temp = head;
    while (temp != NULL) {
        printf("%s (Priority: %d)\n", temp->device, temp->priority);
        temp = temp->next;
    }
}

int main() {
    insertRequest("Keyboard", 1);
    insertRequest("Mouse", 2);
    insertRequest("Printer", 4);
    insertRequest("Scanner", 3);
    displayRequests();

    handleRequest();
    displayRequests();
    return 0;
}
