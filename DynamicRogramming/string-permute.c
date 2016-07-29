#include <string.h>
#include <stdio.h>

void permute(char *, int, int);
void swap(char*,  char *);

int main(void){
  char arr[] = "dub";
  int len = strlen(arr);
  permute(arr, 0, len - 1);

  return 0;
}

void permute(char * arr, int i , int len){
  if(i == len){
    printf("%s\n", arr);
    return;
  }

  for(int j = i; j <= len; j++){
    swap((arr + i), (arr + j));
    permute(arr, i + 1, len);
    swap((arr + i), (arr + j));
  }
}

void swap(char * a, char * b){
  char temp = *a;
  *a = *b;
  *b = temp;
}
