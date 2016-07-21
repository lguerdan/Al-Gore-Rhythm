#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int val;
  struct node * next;
}Node;

Node * findLoop(Node * head);
void printList(Node * head);
void push(Node ** head_ref, int data);
void delete(Node * head);

int main(void){
  Node * head = NULL;
  push(&head, 7);
  push(&head, 3);
  push(&head, 5);
  push(&head, 9);
  push(&head, 10);
  push(&head, 3);

  printList(head);

  head->next->next->next->next = head->next;

  Node * loop_node = findLoop(head);
  printf("Looped node is %d\n", loop_node->val);

  return 0;
}

Node * findLoop(Node * head){
  Node * slow_ptr = head, * fast_ptr = head;

  while(slow_ptr && fast_ptr && fast_ptr->next){
    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;

    if(slow_ptr == fast_ptr) return slow_ptr;
  }
  return NULL;
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
void delete(Node * head){
  while(head){
    Node * prev = head;
    head = head->next;
    free(prev);
  }
}



