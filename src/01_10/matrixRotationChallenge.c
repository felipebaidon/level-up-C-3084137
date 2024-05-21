#include <stdlib.h>
#include <time.h>
#include <stdio.h>

char Matrix[5][5];

struct grid{int rows; int columns;};
struct grid Matrix_1grid = {5,5};
struct grid Matrix_2grid = {8,3};
struct grid Matrix_3grid = {4,6};

void fillInMatrix(struct grid* grid_info)
{
  char lower_bound = 'a';
  char upper_bound = 'z';

  srand((unsigned int)time(NULL));

  for(int i= 0; i < grid_info ->rows ; i++)
  {
    for(int j = 0; j < grid_info -> columns; j++)
    {
      Matrix[i][j] = rand() % (int)((upper_bound - lower_bound + 1)) + (int)lower_bound;
      printf(" %c ", Matrix[i][j]);
    }
    puts("\n");
  }

}

void rotateMatrix(struct grid* grid_info)
{
  char element;

  for(int i = 0; i< grid_info->columns ; i++)
  {
    for( int j = 0; j< grid_info->rows; j++)
    {
      element = Matrix[grid_info->rows - 1 - j][i];
      printf(" %c ", element);
    }
    puts("\n");
  }
}

int main(void)
{ 
  printf(" Original Matrix \n");
  fillInMatrix(&Matrix_1grid);
  printf("\n");

  printf("Rotated Matrix\n");
  rotateMatrix(&Matrix_1grid);
  printf("\n");

  printf(" Original Matrix \n");
  fillInMatrix(&Matrix_2grid);
  printf("\n");

  printf("Rotated Matrix\n");
  rotateMatrix(&Matrix_2grid);
  printf("\n");

  printf(" Original Matrix \n");
  fillInMatrix(&Matrix_3grid);
  printf("\n");

  printf("Rotated Matrix\n");
  rotateMatrix(&Matrix_3grid);
  printf("\n");

  return 0;  
}