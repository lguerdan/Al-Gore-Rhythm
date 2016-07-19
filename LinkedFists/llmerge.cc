// C program to merge a linked list into another at
// alternate positions
#include <stdio.h>
#include <stdlib.h>

void merge(struct node * p, struct node ** q);
void push(struct node ** head_ref, int new_data);
void printList(struct node *head);

// A nexted list node
struct node
{
    int data;
    struct node *next;
};

int main()
{
     struct node *p = NULL, *q = NULL;
     push(&p, 3);
     push(&p, 2);
     push(&p, 1);
     printf("First Linked List:\n");
     printList(p);

     push(&q, 8);
     push(&q, 7);
     push(&q, 6);
     push(&q, 5);
     push(&q, 4);
     printf("Second Linked List:\n");
     printList(q);

     merge(p, &q);

     printf("Modified First Linked List:\n");
     printList(p);

     printf("Modified Second Linked List:\n");
     printList(q);

     getchar();
     return 0;
}


/* Function to insert a node at the beginning */
void push(struct node ** head_ref, int new_data)
{
    struct node* new_node =
           (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}

/* Utility function to print a singly linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void merge(struct node * p, struct node ** q){
  struct node *p_curr = p, *q_curr = *q;
  struct node *p_next, *q_next;

  while(p_curr != NULL && q_curr != NULL){
    p_next = p_curr->next;
    q_next = q_curr->next;

    q_curr->next = p_next;
    p_curr->next = q_curr;

    p_curr = p_next;
    q_curr = q_next;
  }
  *q = q_curr;
}