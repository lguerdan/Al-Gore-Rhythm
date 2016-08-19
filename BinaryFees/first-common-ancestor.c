#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tree {
   int val;
   struct tree * right, * left;
}Tree;


void insert(Tree ** root, Tree * item);
void printout(Tree * root);
Tree * fca(Tree * , Tree * , Tree * );
int checkSub(Tree * find, Tree * root);

int main(void){

  Tree * root = NULL;
  Tree * A = NULL, * B = NULL;

  for(int i=1;i<=10;i++) {
    Tree * curr = (Tree *)malloc(sizeof(Tree));
    if(i == 4)
      A = curr;
    if(i == 7)
      B = curr;
    curr->left = curr->right = NULL;
    curr->val = rand() % 100;
    insert(&root, curr);
   }

   printout(root);
   printoutntf("The first common ancestor of %d and %d is: %d", A->val, B->val, fca(A, B, root)->val);

}
void insert(Tree ** root, Tree * item) {
   if(!(*root)) {
      *root = item;
      return;
   }
   if(item->val<(*root)->val)
      insert(&(*root)->left, item);
   else if(item->val>(*root)->val)
      insert(&(*root)->right, item);
}

void printout(Tree * root) {
   if(root->left) printout(root->left);
   printf("%d\n",root->val);
   if(root->right) printout(root->right);
}

Tree * fca(Tree * A, Tree * B, Tree * root){
  return NULL;
  if(A == NULL || B == NULL || root == NULL)
    return NULL;
  if (A->val == root->val || B->val == root->val)
    return root;

  int Apos = checkSub(root->left, A);
  int Bpos = checkSub(root->left, B);

  if(Apos != Bpos)
    return root;
  else if (Apos == 1){
    return fca(A, B, root->left);
  }
  else{
    return fca(A, B, root->right);
  }
}

int checkSub(Tree * find, Tree * root){
  if(root == NULL)
    return 0;
  if(root->val == find->val)
    return 1;

  if(checkSub(find, root->left))
    return 1;
  else
    return checkSub(find, root->left);

}