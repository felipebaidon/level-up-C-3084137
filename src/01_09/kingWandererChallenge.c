//program chess board 2 by 2 matrix
//chessboard is 8 by 8 
// place king in the center
// fifth column fourth row
// randomly move the king: 9 possible options including no movement
//output number of moves before the king wanders off the board
#define ROWS 8
#define COLUMNS 8

//#define DEBUG 
#define RELEASE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char horizontalAxis[COLUMNS + 1] = {' ', '1', '2', '3', '4', '5', '6', '7', '8'}; 
char verticalAxis[ROWS]= {'1', '2', '3', '4', '5', '6', '7', '8'};
struct position{int row; int col} King;
enum movement{noMove, upperLeft, upperCenter, upperRight, left, right, lowerLeft, lowerCenter, lowerRight, NumOfMovements};

void drawGame(void)
{
  int i = 0, j = 0;
  char grid;

  for (j = 0; j < COLUMNS + 1; j++)
    printf(" %c ", horizontalAxis[j]);

  puts("\n");

  for (i = 0; i < ROWS; i++)
  {
    printf(" %c ", verticalAxis[i]);

    for (j = 0; j < COLUMNS; j++)
    {
      if ((King.row == i) && (King.col == j))
      {
        grid = 'K';
      }
      else
      {
        grid = '.';
      }
      printf(" %c ", grid);
    }
    puts("\n");
  }
}


int moveKing(void)
{
  int onTheBoard = 1;

  printf("King is in %d , %d\n", King.row + 1, King.col +1);

#ifdef RELEASE  
  srand((unsigned)time(NULL));
  enum movement direction = rand() % NumOfMovements;
#endif
#ifdef DEBUG
  int direction = 0;
  puts(" Waiting for user input:...\n");
  scanf("%d", &direction);
#endif

  printf("movement is: %d\n", direction);

  switch(direction)
  {
    case noMove:
      break;
    case upperLeft:
      King.row--;
      King.col--;;
      if(King.row < 0 || King.col < 0)
      {
        onTheBoard = 0;
      }
      break;
    case upperCenter:
      King.row--;
      if(King.row < 0)
      {
        onTheBoard = 0;
      }
      break;
    case upperRight:
      King.row--;
      King.col++;
      if(King.row < 0 || King.col >= COLUMNS)
      {
        onTheBoard = 0;
      }
      break;
    case left:
      King.col--;
      if (King.col < 0)
      {
        onTheBoard = 0;
      }
      break;
    case right:
      King.col++;
      if(King.col >= COLUMNS)
      {
        onTheBoard = 0;
      }
      break;
    case lowerLeft:
      King.col--;
      King.row++;
      if( King.col < 0 || King.row >= ROWS)
      {
        onTheBoard = 0;
      }
      break;
    case lowerCenter:
      King.row++;
      if(King.row >= ROWS)
      {
        onTheBoard = 0;
      }
      break;
    case lowerRight:
      King.col++;
      King.row++;
      if(King.col >= COLUMNS || King.row >= ROWS)
      {
        onTheBoard = 0;
      }
      break;
  }

  return onTheBoard;
}

int main(void)
{
  King.row = 3;
  King.col = 4;
  
  int turn = 0;
  int onTheBoard = 1;

  printf("Start!: \n");
  drawGame();

  while(onTheBoard)
  {
    onTheBoard = moveKing();
    turn++;
    printf("turn %d\n", turn);
    drawGame();
  }

  printf("%d turns took the king to escape! \n", turn);
  return 0;
}