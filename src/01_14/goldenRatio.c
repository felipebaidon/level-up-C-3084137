#include <stdio.h>
double getGoldenRatio(int n)
{
  if(n==0)
  {
    return 1;
  }

  double res = 1 + (double)(1/getGoldenRatio(n-1));
  return res;

}

int main(void)
{
  int iterations = 0; 

  puts("Enter number of iterations!:");
  scanf("%d", &iterations);
  printf("number of iterations is: %d\n", iterations);
  printf("approximate golden ratio is: %1.10lf\n", getGoldenRatio(iterations));
  
  return 0;
}