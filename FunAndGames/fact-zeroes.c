
// Find the number of trailing zeroes in n factorial

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int multsFive(int);
int factorsFive(int);

int main(int argc, char ** argv){

  int num = atoi(argv[1]);
  printf("The number of trailing zeroes are: %d", multsFive(num));

}

int multsFive(int num){
  int fives = 0;
  for (int i = 2; i <= num; i++){
    fives += factorsFive(i);
  }
  return fives;
}

int factorsFive(int n){
  int count = 0;
  while (n % 5 == 0){
    count++;
    n /=5;
  }
  return count;
}

