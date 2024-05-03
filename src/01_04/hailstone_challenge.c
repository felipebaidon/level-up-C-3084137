#include <stdio.h>

void hailstone(void)
{
  int n=0;
  int hailstoneLength = 1;

  printf("Enter a number greater that 0\n");
  scanf("%d", &n);
  printf("number is: %d" , n);

  while(n>1)
  {
    if(n%2 == 0)
    {
      n = n/2;
    }
    else
    {
      n = (n*3) + 1;
    }

    printf(" %d ", n);
    hailstoneLength++;
  }

  printf("\n hailstone length is: %d\n", hailstoneLength );
}


int main(void)
{
  hailstone();

  printf("\n");
  return 0;
}