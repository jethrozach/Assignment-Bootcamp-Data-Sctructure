#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    Node *next; 
} *head, *tail, *current, *next_next;

Node *createNode(int num) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

void removeDuplicates() {
    current = head;
    if (current == NULL) {
        return;
    }
    while (current->next != NULL) {
        if (current->num == current->next->num) {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }else {
            current = current->next;
        }
    }
}

void pushHead(int num) {
    Node *temp = createNode(num);
    if (!head) {
        head = tail = temp;
    }else {
        temp->next = head;
        head = temp;
    } 
}

void pushTail(int num) {
    Node *temp = createNode(num);
    if (!head) {
        head = tail = temp;
    }else {
        tail->next = temp;
        tail = temp;
    } 
}

void printList() {
    Node *current = head;
    while (current)
    {
        printf("%d->", current->num);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    pushHead(45);
    pushHead(40);
    pushHead(35);
    pushHead(35);
    pushHead(28);
    pushHead(28);
    pushHead(23);
    pushHead(23);
    pushHead(23);
    pushTail(23);
    pushTail(23);
    pushTail(23);
    pushTail(28);
    pushTail(28);
    pushTail(35);
    pushTail(35);
    pushTail(40);
    printf("Number before duplicate: ");
    printList();
    removeDuplicates();
    printf("Number after  duplicate: ");
    printList();
    return 0;
}
