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
  removeDupes(curr);
  printList(curr);
}

void removeDupes(Node * head){
  Node * ptr1, * ptr2, * dup;
  ptr1 = head;

  while(ptr1 != NULL && ptr1->next != NULL){
    ptr2 = ptr1;
    while(ptr2->next != NULL){

      if(ptr1->val == ptr2->next->val){
        dup = ptr2->next;
        ptr2->next = ptr2->next->next;
        free(dup);
      }
      else{
        ptr2 = ptr2->next;
      }
    }
    ptr1 = ptr1->next;
  }
}
void printList(Node * head){
  puts("\n");
  while(head){
    printf("%d->", head->val);
    head = head->next;
  }
}