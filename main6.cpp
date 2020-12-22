#include<stdio.h>  
#include<stdlib.h>  

struct Node {
    int num;
    Node *next;
} *head, *tail, *current;

Node *createNode(int num) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
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
   int A, B, C, D;
    printf("Enter a number: ");
    scanf("%d %d %d %d", &A, &B, &C, &D);
    pushHead(C);
    pushHead(D);
    pushTail(B);
    pushTail(A);
    printf("Number after sorted: ");
    printList();
    return 0;
}