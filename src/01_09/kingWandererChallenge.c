//program chess board 2 by 2 matrix
//chessboard is 8 by 8 
// place king in the center
// fifth column fourth row
// randomly move the king: 9 possible options including no movement
//output number of moves before the king wanders off the board
#define rows 8
#define columns 8

#define DEBUG 
//#define RELEASE

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


void moveKing(void)
{
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
      King = King - 9;
      break;
    case upperCenter:
      King  = King - 8;
      break;
    case upperRight:
      King = King - 7;
      break;
    case left:
      King = King - 1;
      break;
    case right:
      King = King + 1;
      break;
    case lowerLeft:
      King = King + 7;
      break;
    case lowerCenter:
      King = King + 8;
      break;
    case lowerRight:
      King = King + 9;
      break;
  }
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
    moveKing();
    if((King <  &chessboard[0][0]) || (King > &chessboard[7][7]))
      onTheBoard = 0;
    count++;
    printf("%d Movement performed!\n", count);
    drawGame();
  }

  printf("Number of movements to wander: %d\n", count);
  return 0;
}