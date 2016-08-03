#include <stdio.h>
#include <stdlib.h>

void printHeap(int * heap);
void insertHeap(int * heap, int new);
int removeHeap(int * heap);
int getMin(int * heap);

int main(void){

  int heap[100] = {0};
  heap[0] = 6;
  heap[1] = 3;
  heap[2] = 9;
  heap[3] = 11;
  heap[4] = 20;
  heap[5]= 12;
  heap[6] = 15;

  //Print initialized heap
  printHeap(heap);

  // Insert some elements
  insertHeap(heap, 5);
  insertHeap(heap, 14);

  // Remove some elements
  removeHeap(heap);
  removeHeap(heap);
  removeHeap(heap);
  removeHeap(heap);
}

void printHeap(int * heap){
  for(int i = 0; i < 100; i++){
    if (heap[i] == 0){
      break;
    }
    printf("%d ", heap[i]);
  }
  puts("\n");
}

void insertHeap(int * heap, int new){

  // Make space for new element at end of array
  int maxsize = ++heap[0];
  heap[maxsize] = new;
  int index = maxsize;

  // Restore heap property by allowing min to percolate up
  while(heap[index] < heap[index /2]){
    int temp = heap[index];
    heap[index] = heap[index/2];
    heap[index/2] = temp;
    index/=2;
  }

  printf("\n======================\nAfter inserting %d\n", new);
  printHeap(heap);
}

int removeHeap(int * heap){
  //Get smallest element, reassign min, decrement max index

  int smallest = heap[1];
  heap[1] = heap[heap[0]];
  heap[heap[0]--] = 0;

  int parent = 1;
  int child = parent * 2;

  // Allow max value to percolate down heap

  while((heap[parent] > heap[child] && heap[child] != 0) || (heap[parent] > heap[child + 1] && heap[child + 1] != 0)){

    if((heap[child + 1] < heap[child]) && (heap[child + 1] != 0)){
      child += 1;
    }

    int temp = heap[parent];
    heap[parent] = heap[child];
    heap[child] = temp;

    parent = child;
    child = parent * 2;

  }

  printf("\n======================\nAfter removing %d\n", smallest);
  printHeap(heap);
  return smallest;
}

