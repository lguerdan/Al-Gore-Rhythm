#include <stdlib.h>
#include <stdio.h>

void mergeSort(int *, int low, int high);
void merge(int *, int, int,int);
int smallestDiff(int *, int *, int, int);

int main(void){
  int a[] = {7,2, 13, 4, 87, 6, 89};
  int b[] = {18, 73, 38, 17, 5};

  printf("The smallest difference between arrays is: %d", smallestDiff(a, b, sizeof(a) / sizeof(int), sizeof(b) / sizeof(int)));

}



int smallestDiff(int * arr_a, int * arr_b, int len_a, int len_b){
  int diff, s_diff, a_scan = 0, b_scan = 0;

  if (len_a == 0 || len_b == 0 )
    return -1;

  mergeSort(arr_a, 0, len_a - 1);
  mergeSort(arr_b, 0, len_b - 1);

  s_diff = abs(arr_a[0] - arr_b[0]);

  do{
    diff = arr_a[a_scan] - arr_b[b_scan];

    if(diff == 0)
      return 0;
    if(abs(diff) < s_diff)
      s_diff = abs(diff);

    diff > 0 ? b_scan++ : a_scan++;

  }while(a_scan < len_a && b_scan < len_b);

return s_diff;
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