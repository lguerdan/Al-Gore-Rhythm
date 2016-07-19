#include <stdlib.h>
#include <stdio.h>

void quickSort(int arr[], int, int);

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
  quickSort(arr,0,4);
  puts("array sorted");
  for (int i = 0; i < 5; ++i)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}
void quickSort(int arr[], int left, int right){
  int i = left;
  int j = right;
  int pivot = arr[(left + right) / 2];

  while(i <= j){
    while(arr[i] < pivot){
      i++;
    }
    while(arr[j] > pivot){
      j--;
    }
    if(i <= j){
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
    i++;
    j--;
  }

  if(left < j){
    quickSort(arr, left, j);
  }
  if(right > i){
    quickSort(arr, i, right);
  }
}



