// Given sorted array w/ unique integer elements,
// create binary search tree with minimal height.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tree {
   int val;
   struct tree * right, * left;
}Tree;

void printout(Tree * root);
Tree * shallowTree(Tree * root, int * arr, int low, int high);

int main(void){
  Tree * root = NULL;
  int arr[] = {0, 13, 14, 19, 20 , 22, 35, 71, 100, 248};
  root = shallowTree(root, arr, 0, sizeof(arr) / sizeof(int));

  printout(root);
}

void printout(Tree * root) {
   if(root->left) printout(root->left);
   printf("%d\n",root->val);
   if(root->right) printout(root->right);
}


// Recursively assign left & right sub trees to array partition.
Tree * shallowTree(Tree * root, int * arr, int low, int high){
  if(high < low){
    return NULL;
  }
  int mid = (high + low) / 2;

  // make new root and sub trees
  Tree * new = (Tree * )malloc(sizeof(Tree));
  new->val = arr[mid];
  new->left = shallowTree(root, arr, low, mid - 1);
  new->right = shallowTree(root, arr, mid + 1, high);

  return new;
}

