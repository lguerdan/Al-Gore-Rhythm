#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int val;
  struct node * next;
}Node;

int checkPal(Node * head);
void printList(Node * head);
void push(Node ** head_ref, int data);
void delete(Node * head);
Node * pusher(Node * top, int val);

int main(void){
  Node * head = NULL;
  push(&head, 9);
  push(&head, 3);
  push(&head, 5);
  push(&head, 5);
  push(&head, 3);
  push(&head, 9);

  printList(head);

  checkPal(head) ? puts("Is a palendrome!") : puts("Is not a palendrome!");

  delete(head);
  return 0;
}

int checkPal(Node * head){
  Node * stackHead = NULL, *storeList = head, * stackStore = NULL;

  while(head){
    stackHead = pusher(stackHead, head->val);
    head = head->next;
  }
  head = storeList;
  stackStore = stackHead;

  while(head){
    if(head->val != stackHead->val){
      delete(stackStore);
      return 0;
    }
    else{
      head = head->next;
      stackHead = stackHead->next;
    }
  }
  delete(stackStore);
  return 1;
}


void push(Node ** head_ref, int data){
    Node * new = (Node *)malloc(sizeof(Node));
    new->val = data;
    new->next = *head_ref;
    *head_ref = new;
}

Node * pusher(Node * top, int val){
  Node * link = (Node * )malloc(sizeof(Node));
  link->val = val;
  link->next = top;
  return link;
}

void printList(Node * head){
  puts("");
  while(head){
    printf("%d->",head->val);
    head = head->next;
  }
  puts("");
}
void delete(Node * head){
  while(head){
    Node * prev = head;
    head = head->next;
    free(prev);
  }
}



