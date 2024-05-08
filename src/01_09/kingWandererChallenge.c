//program chess board 2 by 2 matrix
//chessboard is 8 by 8 
// place king in the center
// fifth column fourth row
// randomly move the king: 9 possible options including no movement
//output number of moves before the king wanders off the board
#define rows 8
#define columns 8

#include<stdio.h>

char chessboard[rows][columns];
char horizontalAxis[columns + 1] = {' ', '1', '2', '3', '4', '5', '6', '7', '8'}; 
char verticalAxis[rows]= {'1', '2', '3', '4', '5', '6', '7', '8'};
char *King;

int main(void)
{
  int i = 0, j = 0;
  char grid;
  King = &chessboard[3][4];
  
  printf( "Start: \n");
  
  for( j=0; j < columns + 1; j++)
      printf(" %c ", horizontalAxis[j]);

  puts("\n");

  for(i= 0; i< rows; i++)
  {
    printf(" %c ", verticalAxis[i]);

    for(j= 0; j< columns; j++)
    {
      if(&chessboard[i][j]== King)
      {
          grid = 'K';
      }
      else
      {
          grid = '.';
      }
      chessboard[i][j] = grid;
      printf(" %c ", chessboard[i][j]);
    }
    puts("\n");
  }
  puts( "\n End \n");

  return 0;
}