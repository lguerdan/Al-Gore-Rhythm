#include <stdlib.h>
#include <stdio.h>

void mergeLists(int * A, int * B, int lenA, int lenB);


int main(void){
  int A[50] = {3,3,5,6,7,8,10,12,15};
  int B[4] = {1,9,10,16};

  mergeLists(A, B, 9, 4);

  puts("");
  for(int i = 0; i < 13; i++){
    printf("%d ", A[i]);
  }
  puts("");


  return 0;
}

void mergeLists(int * A, int * B, int lenA, int lenB){
  int mergeInd = lenA-- + lenB-- - 1;
  while(mergeInd >= 0){

    while (lenA >= 0 && lenB >= 0){
      if(A[lenA] > B[lenB]){
        A[mergeInd] = A[lenA];
        mergeInd--;
        lenA--;
      }
      else{
        A[mergeInd] = B[lenB];
        mergeInd--;
        lenB--;
      }
    }
    if (lenA == 0)
      return;
    while(lenB >= 0){
      A[mergeInd] = B[mergeInd];
      mergeInd--;
      lenB--;
    }
    return;
  }
}


