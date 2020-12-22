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

void printNthFromLast(int n) { 
  ptr1 = head; 
  ptr2 = head; 
  
  int count = 0; 
  if(head != NULL) { 
     while( count < n ) { 
        if(ptr2 == NULL) { 
           printf("%d is not in the number of nodes in list\n", n); 
           return; 
        } 
        ptr2 = ptr2->next; 
        count++; 
     } 
     if(ptr2 == NULL) { 
        head = head->next; 
        if(head != NULL) 
            printf("Node number %d from last is %d \n", n, ptr1->num); 
     }else { 
       while(ptr2 != NULL) { 
          ptr1 = ptr1->next; 
          ptr2 = ptr2->next; 
       } 
       printf("Node number %d from last is %d \n", n, ptr1->num); 
     } 
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
    pushHead(A);
    pushHead(B);
    pushTail(C);
    pushTail(D);
    printf("Number after sorted: ");
    printList();
    printNthFromLast(D);
    return 0;
}