#include <stdio.h>
#include <stdlib.h>

int checkWin(int board[][3], int size);
int checkHorz(int board[][3], int size);
int checkVert(int board[][3], int size);
int checkDiag(int board[][3], int size);


int main(void){
  // Initialize a 3 by 3 game
  int board[3][3] = {0,1,2, 1,1,2,1,1,2};
  printf("The winner is player %d", checkWin(board, 3));

  return 0;
}

// Nieve implementaiton for N by N board. Takes O(n) time and no extra space.
int checkWin(int board[][3], int size){
  int winner;
  winner = checkHorz(board, size);
  if (winner)
    return winner;

  winner = checkVert(board, size);
  if (winner)
    return winner;

  winner = checkVert(board, size);
  if (winner)
    return winner;

  return 0;
}

// Check horizontal runs on board
int checkHorz(int board[][3], int size){

  for(int i = 0; i < size; i++ ){

    int horz_check = board[0][i];
    for (int j= 0; j < size; j++){
      if (board[j][i] != horz_check)
        horz_check = 0;
    }
    if (horz_check)
      return horz_check;
  }
  return 0;
}

// Check vertical runs on board
int checkVert(int board[][3], int size){

  for (int i = 0; i < size; i++){
    int vert_check = board[i][0];

    for(int j = 0; j < size; j++){
      if(board[i][j] != vert_check)
        vert_check = 0;
    }
    if (vert_check)
     return vert_check;
  }
  return 0;
}
int checkDiag(int board[][3], int size){

  int diag_check = board[0][0];
  for (int i = 0; i < size; i++){
    if(board[i][i] != diag_check)
      diag_check = 0;
  }
  if (diag_check)
    return diag_check;

  diag_check = board[0][size- 1];
  for(int i = 0; i < size; i++){
    if (board[i][size - i - 1] != diag_check)
      diag_check = 0;
  }
  if(diag_check)
    return diag_check;

  return 0;
}
