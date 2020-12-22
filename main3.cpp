#include<stdio.h>  
#include<stdlib.h>  

struct Node {
    int num;
    Node *next;
} *head, *tail, *ptr1, *ptr2, *current;

Node *createNode(int num) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

void printMiddle() {
    ptr1 = head;
    ptr2 = head;
    if (head != NULL) {
        while (ptr2 != NULL && ptr2->next != NULL) {
            ptr2 = ptr2->next->next;
            ptr1 = ptr1->next;
        }
        printf("The middle element is [%d]\n", ptr1->num);
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
    while (current) {
        printf("%d->", current->num);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    for (int i = 1; i < 5; i++)
    {
        pushHead(i);
    }
    for ( int j = 1; j < 5; j++) {
        printf("Linked list:");
        pushTail(j);
    }
    printList();
    printMiddle();
    return 0;  
}  