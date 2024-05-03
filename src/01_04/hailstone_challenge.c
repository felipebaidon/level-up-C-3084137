#include <stdio.h>

void hailstone(void)
{
  int n=0;

  printf("Enter a number greater that 0\n");
  scanf("%d", &n);
  printf("number is: %d" , n);
}


int main(void)
{
  hailstone();

  printf("\n");
  return 0;
}