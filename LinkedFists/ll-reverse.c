#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int val;
  struct node * next;
}Node;

void reverseList(Node ** first);
void reverseRecursive(Node **);
void printList(Node * head);
void push(Node ** head_ref, int data);

int main(void){
  Node * head = NULL;
  push(&head, 20);
  push(&head, 15);
  push(&head, 23);
  push(&head, 6);
  push(&head, 2);

  printList(head);
  reverseRecursive(&head);
  printList(head);

}

void reverseList(Node ** first){
  if (*first == NULL){
    return;
  }
  Node * head = (*first)->next;
  Node * prev = *first;
  prev->next = NULL;

  while(head){
    prev = head;
    head = head->next;

    prev->next = *first;
    *first = prev;
  }
  return;
}

void reverseRecursive(Node ** head){
  if(*head == NULL){
    return;
  }

  Node * first, * rest;
  first = *head;
  rest = first->next;

  if(rest == NULL){
    return;
  }

  reverseRecursive(&rest);
  first->next->next = first;
  first->next = NULL;

  *head = rest;
}


void push(Node ** head_ref, int data){
    Node * new = (Node *)malloc(sizeof(Node));
    new->val = data;
    new->next = *head_ref;
    *head_ref = new;
}

void printList(Node * head){
  puts("");
  while(head){
    printf("%d->",head->val);
    head = head->next;
  }
  puts("");
}


