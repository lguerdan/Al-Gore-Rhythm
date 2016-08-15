#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tree {
   int val;
   struct tree * right, * left;
}Tree;

void insert(Tree ** root, Tree * item);
void printout(Tree * root);
int getDepth(Tree * root);


int main(void){

  Tree * root = NULL;
  for(int i=1;i<=10;i++) {
    Tree * curr = (Tree *)malloc(sizeof(Tree));
    curr->left = curr->right = NULL;
    curr->val = rand() % 100;
    insert(&root, curr);
   }

   printout(root);
   getDepth(root) == -1 ? puts("Not ballanced") : puts("balanced");

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

int getDepth(Tree * root){
  if(!root) return 0;

  int l_depth, r_depth;
  // If left subtree not balanced
  if((l_depth = getDepth(root->left)) == -1)
    return -1;

  // If right subtree not balanced
  if((r_depth = getDepth(root->right)) == -1)
    return -1;

  if(abs(r_depth - l_depth) > 1)
    return -1;

  return (r_depth > l_depth) ?  r_depth + 1 :  l_depth + 1;

}
