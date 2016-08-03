#include <stdio.h>
#include <stdlib.h>

// Given an array of integers, sort the array into alternating sequence of peaks and valleys


void pv_merge(int * arr, int len);
void q_sort(int * arr, int , int);
void swap(int * , int , int);
void pv_merge_optimized(int * arr, int len);

int main(void){
  int arr[] = {5,8,9,2,2,0,63,18, 91,24};
  int len = sizeof(arr) / sizeof(int);
  pv_merge_optimized(arr, len);

  puts("==============================\nArray with peaks and valleys:");
  for(int i = 0; i < len; i++){
    printf("%d ", arr[i]);
  }
}


// Sort array then swap i and i - 1 elements. O(nlogn)
void pv_merge(int * arr, int len){
  q_sort(arr, 0, len - 1);

  for (int i =  1; i < len; i+=2)
    swap(arr, i, i - 1);

  return;
}

// Moving frame of three elements, find peek and swap with middle. O(N)
void pv_merge_optimized(int * arr, int len){

  for(int i = 1; i < len ; i+=2){

    if(arr[i - 1] > arr[i])
      swap(arr, i - 1, i);
    if(arr[i + 1] > arr[i])
      swap(arr, i + 1, i);

  }
}





void q_sort(int * arr, int low, int high){
  int i = low;
  int j = high;
  int pivot = arr[(low + high) / 2];

  while(i <= j){
    while(arr[i] < pivot){
      i++;
    }
    while(arr[j] > pivot){
      j--;
    }

    if(i <= j){
      swap(arr, i, j);
    }
    i++;
    j--;

    if (j > low)
      q_sort(arr, low, j);

    if (i < high)
      q_sort(arr, i, high);
  }
}

void swap(int * arr, int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}