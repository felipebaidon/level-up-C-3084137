#define MATRIX1ROWS 5
#define MATRIX1COLUMNS 5

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

char Matrix_1[5][5];
char NewMatrix_1[5][5];

void fillInMatrix(void)
{
  char lower_bound = 'a';
  char upper_bound = 'z';

  srand((unsigned int)time(NULL));

  for(int i= 0; i < MATRIX1ROWS ; i++)
  {
    for(int j = 0; j < MATRIX1COLUMNS; j++)
    {
      Matrix_1[i][j] = rand() % (int)((upper_bound - lower_bound + 1)) + (int)lower_bound;
      printf(" %c ", Matrix_1[i][j]);
    }
    puts("\n");
  }

}

void rotateMatrix(void)
{
  for(int i = 0; i< MATRIX1COLUMNS ; i++)
  {
    for( int j = 0; j< MATRIX1ROWS; j++)
    {
      NewMatrix_1[i][j] = Matrix_1[MATRIX1ROWS - 1 - j][i];
      printf(" %c ", NewMatrix_1[i][j]);
    }
    puts("\n");
  }
}

int main(void)
{
  printf(" Original Matrix \n");
  fillInMatrix();
  printf("\n");

  (printf("Rotated Matrix\n"));
  rotateMatrix();
  printf("\n");

  return 0;  
}