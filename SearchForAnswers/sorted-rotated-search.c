#include <stdio.h>
#include <stdlib.h>

int search(int * arr, int low, int high, int key);


int main(void){
  int arr[] = {9, 11, 12, 15, 18, 19, 25, 1, 3,5};
  int n = sizeof(arr)/ sizeof(arr[0]);

  printf("Number found id %d\n", search(arr, 0, n, 2));

}


int search(int * arr, int low, int high, int key){
  if (low > high) return -1;
  int mid = (low + high ) / 2;
  if (key == arr[mid]) return key;

  if (arr[low] <= arr[mid]){
    if(key <= arr[mid] && key >= arr[low])
      return search(arr,low, mid - 1, key);
    return search(arr, mid + 1, high, key);
  }

  if(arr[mid] <= key && arr[high] >= key){
    return search(arr, mid + 1, high, key);
  }
  return search(arr, low, mid - 1, high);
}