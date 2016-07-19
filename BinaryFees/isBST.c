#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int val;
   struct node * right, * left;
}Node;

void insert(Node ** tree, Node * item);
void printout(Node * tree);
int isBST(Node * tree);


int main(void){

  Node * root = NULL;
  for(int i=1;i<=10;i++) {
    Node * curr = (Node *)malloc(sizeof(Node));
    curr->left = curr->right = NULL;
    curr->val = rand() % 100;
    insert(&root, curr);
   }
   isBST(root) ? puts("Is a valid BST") : puts("Is not a valid BST");
   printout(root);
}

void insert(Node ** tree, Node * item) {
   if(!(*tree)) {
      *tree = item;
      return;
   }
   if(item->val<(*tree)->val)
      insert(&(*tree)->left, item);
   else if(item->val>(*tree)->val)
      insert(&(*tree)->right, item);
}

void printout(Node * tree) {
   if(tree->left) printout(tree->left);
   printf("%d\n",tree->val);
   if(tree->right) printout(tree->right);
}

int isBST(Node * tree){
  static Node * prev = NULL;
  if(tree){
    if (tree->left != NULL && prev->val >= tree->val){
      return 0;
    }
    if(!isBST(tree->left)){
      return 0;
    }
    prev = tree;

    return isBST(tree->right);
  }
  return 1;
}