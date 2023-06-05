#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtHead(Node* head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) {
        return head;
    }
    newNode->next = head;
    return newNode;
}

void deleteNode(Node** head, int data) {
    Node* prev = NULL;
    Node* curr = *head;
    while (curr) {
        if (curr->data == data) {
            if (prev) {
                prev->next = curr->next;
            } else {
                *head = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Node with data %d not found\n", data);
}

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
