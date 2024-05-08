//program chess board 2 by 2 matrix
//chessboard is 8 by 8 
// place king in the center
// fifth column fourth row
// randomly move the king: 9 possible options including no movement
//output number of moves before the king wanders off the board
#define rows 8
#define columns 8

//#define DEBUG 
#define RELEASE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char chessboard[rows][columns];
char horizontalAxis[columns + 1] = {' ', '1', '2', '3', '4', '5', '6', '7', '8'}; 
char verticalAxis[rows]= {'1', '2', '3', '4', '5', '6', '7', '8'};
char *King;
enum movement{noMove, upperLeft, upperCenter, upperRight, left, right, lowerLeft, lowerCenter, lowerRight, NumOfMovements};

void drawGame(void)
{
  int i = 0, j = 0;
  char grid;

  for (j = 0; j < columns + 1; j++)
    printf(" %c ", horizontalAxis[j]);

  puts("\n");

  for (i = 0; i < rows; i++)
  {
    printf(" %c ", verticalAxis[i]);

    for (j = 0; j < columns; j++)
    {
      if (&chessboard[i][j] == King)
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
}


int moveKing(void)
{
  int i, j;
  int kingIsFound = 0;
  int onTheBoard = 1;

  for(i= 0; i< rows; i++)
  {
    for(j=0; j< columns; j++)
    {
      if(&chessboard[i][j]== King)
      {
        kingIsFound = 1;
        break;
      }
    }

          if(kingIsFound)
        break;
  }

  printf("King is in %d , %d\n",i + 1,j +1);

#ifdef RELEASE  
  srand((unsigned)time(NULL));
  enum movement direction = rand() % NumOfMovements;
#endif
#ifdef DEBUG
  int direction = 0;
  puts(" Waiting for user input:...\n");
  scanf("%d", &direction);
#endif

  switch(direction)
  {
    case noMove:
      break;
    case upperLeft:
      King = &chessboard[i-1][j-1];
      if(j == 0 || i == 0)
      {
        onTheBoard = 0;
        *King = '.';
      }
      break;
    case upperCenter:
      King  = &chessboard[i-1][j];
      if(i==0)
      {
        onTheBoard = 0;
        *King = '.';
      }
      break;
    case upperRight:
      King = &chessboard[i-1][j+1];
      if(j==7 || i==0 )
      {
        onTheBoard = 0;
        *King = '.';
      }
      break;
    case left:
      King =  &chessboard[i][j-1];
      if (j == 0)
      {
        onTheBoard = 0;
        King = '.';
      }
      break;
    case right:
      King = &chessboard[i][j+1];
      if(j == 7)
      {
        onTheBoard = 0;
        King = '.';
      }
      break;
    case lowerLeft:
      King = &chessboard[i+1][j-1];
      if( j==0 || i == 7)
      {
        onTheBoard = 0;
        King = '.';
      }
      break;
    case lowerCenter:
      King = &chessboard[i+1][j];
      if(i == 7)
      {
        onTheBoard = 0;
        King = '.';
      }
      break;
    case lowerRight:
      King = &chessboard[i + 1][j+1];
      if(j==7 || i == 7)
      {
        onTheBoard = 0;
        King = '.';
      }
      break;
  }

  return onTheBoard;
}

int main(void)
{
  King = &chessboard[3][4];
  int count = 0;
  int onTheBoard = 1;

  printf("Start!: \n");
  drawGame();

  while(onTheBoard)
  {
    onTheBoard = moveKing();
    count++;
    printf("%d Movement performed!\n", count);
    drawGame();
  }

  printf("Number of movements to wander: %d\n", count);
  return 0;
}