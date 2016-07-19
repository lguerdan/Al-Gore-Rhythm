#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Given an unsorted linked list, remove duplicate values without using a buffer.
typedef struct node{
  int val;
  struct node * next;
}Node;

void removeDupes(Node * start);
void printList(Node * head);
void deleteMiddle(Node *);

int main(void){
  Node * head, * curr;
  head = NULL;


  for (int i = 0; i < 20; i++){
    curr = (Node *)malloc(sizeof(Node));
    curr->val = rand() % 50;
    curr->next = head;
    head = curr;
  }
  curr = head;

  printList(curr);

  Node * link = curr->next->next->next->next;
  printf("\n%d\n", link->val);

  deleteMiddle(link);
  printList(curr);
}

void deleteMiddle(Node * link){
  Node * prev = link;
  link = link->next;
  while(link->next){
    prev->val = link->val;
    prev = prev->next;
    link = link->next;
  }
  prev->next = NULL;
  free(link);
  return;
}


void printList(Node * head){
  puts("\n");
  while(head){
    printf("%d->", head->val);
    head = head->next;
  }
}