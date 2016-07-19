#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int val;
  struct node * next;
}Node;

Node * sumLists(Node *, Node *);
void printList(Node * head);
void push(Node ** head_ref, int data);
void free(Node * head);

int main(void){
  Node * head1 = NULL, * head2 = NULL, * summed = NULL;
  push(&head1, 3);
  push(&head1, 0);
  push(&head1, 9);

  push(&head2, 2);
  push(&head2, 0);
  push(&head2, 0);

  printList(head1);
  printList(head2);

  summed = sumLists(head1, head2);
  printList(summed);
  free(summed);
  free(head1);
  free(head2);
  return 0;
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

Node * sumLists(Node * head1, Node * head2){
  int carry = 0, sum = 0;
  Node * summed = NULL;
  while(head1 || head2){
    sum = 0;
    if(head1)
      sum += head1->val;
    if(head2)
      sum += head2->val;

    Node * digit = (Node *) malloc(sizeof(Node));
    digit->val = (sum +carry) % 10;
    carry = (sum + carry) /10;
    if(head1)
      head1 = head1->next;
    if(head2)
      head2 = head2->next;

    digit->next = summed;
    summed = digit;
  }
  if(carry){
    Node * digit = (Node *) malloc(sizeof(Node));
    digit->val = 1;
    digit->next = summed;
    summed = digit ;
  }
  return summed;
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
void free(Node * head){
  while(head){
    Node * prev = head;
    head = head->next;
    free(prev);
  }
}



