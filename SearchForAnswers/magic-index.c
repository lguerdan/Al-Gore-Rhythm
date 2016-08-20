#include <stdio.h>
#include <stdlib.h>

int magicIndex(int * arr, int len, int dupes);
int searchSub(int * arr, int low, int high);
int miDupes(int * arr, int low , int high);
int max(int A, int B);
int min(int a, int b);

int main(void){

  puts("Checking unique for magic index.");
  int arr[] = {-23, -10, -5,  3, 8, 9, 12, 20, 25, 30 ,32, 40};
  printf("Magic index found at: %d\n\n", magicIndex(arr, sizeof(arr) / sizeof(int), 0));

  puts("Checking non-unique for magic index.");
  int arr_dupes[] = {-18, -15, -3, 0 , 4, 4, 4, 5 , 7, 9 ,20};
  printf("Magic index found at: %d\n\<n></n>", magicIndex(arr_dupes, sizeof(arr) / sizeof(int), 1));

  return 0;
}

int magicIndex(int * arr, int len, int dupes){
  int high = len - 1;
  int low = 0;
  return dupes ? miDupes(arr, low , high) : searchSub(arr, low, high);
}

// Search unique sorted array for magic index
int searchSub(int *arr, int low, int high){
  if (high < low){
    return -1;
  }
  int mid = (high + low )/ 2;

  if(arr[mid] == mid){
    return mid;
  }
  else if(arr[mid] > mid){
    return searchSub(arr, low, mid - 1);
  }
  else{
    return searchSub(arr, mid + 1, high);
  }
}

// Search non-unique sorted array for magic index
int miDupes(int * arr, int low , int high){
  if (high < low)
    return -1;
  int midInd = (low + high) / 2;
  int midVal = arr[midInd];

  if (midInd == midVal)
    return midInd;

  // Search left sub array
  int leftInd = min(midInd - 1, midVal);
  int searchL = miDupes(arr, low, leftInd);
  if(searchL != -1 )
    return searchL;

  // Search right sub array
  int rightInd = max(midInd + 1, midVal);
  int searchR = miDupes(arr, rightInd, high);
  return searchR;

}

int max(int a, int b){
  return a > b ? a : b;
}

int min(int a, int b){
  return a > b ? b : a;
}