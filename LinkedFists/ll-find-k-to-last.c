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
Node * findLink(Node * head, int k);

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
  findLink(curr, 4);
  printList(curr);
}

Node * findLink(Node * head, int k){
    Node * store = head;
    int len = 0;
    while(head){
        head = head->next;
        len++;
    }
    int stop_ind = len - k - 1;
    if(stop_ind < 0)
        return NULL;
    head = store;
    while(stop_ind > 0){
        stop_ind--;
        head = head->next;
    }
    printf("\n%d\n ", head->val);
    return head;
}

void printList(Node * head){
  puts("\n");
  while(head){
    printf("%d->", head->val);
    head = head->next;
  }
}