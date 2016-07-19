#include <stdlib.h>
#include <stdio.h>

void mergeSort(int *, int low, int high);
void merge(int *, int, int,int);


int main(void){
  int arr[50];
  puts("enter the elements\n");

  for (int i = 0; i < 5; i++){
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < 5; ++i)
  {
    printf("%d ", arr[i]);
  }
  mergeSort(arr,0,4);
  puts("array sorted");
  for (int i = 0; i < 5; ++i)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}
void mergeSort(int * arr, int low, int high){
  if(low < high){
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, high, mid);
  }
  return;
}

void merge(int arr[], int low, int high, int mid){
  int i, j, k, c[50];
  i = k = low;
  j = mid + 1;
  while (i <= mid && j <= high){
    if(arr[i] <= arr[j]){
      c[k] = arr[i];
      i++;
    }
    else{
      c[k] = arr[j];
      j++;
    }
    k++;
  }
  while(i <= mid){
    c[k] = arr[i];
    k++;
    i++;
  }
  while(j <= high){
    c[k] = arr[j];
    j++;
    k++;
  }
  for(i = low ; i <= high; i++){
    arr[i] = c[i];
  }
}


