#include <stdbool.h>
#include <stdio.h>

int leapyear(int year)
{
  int isLeapYear = false;

  if((year%4 == 0))
  {
    isLeapYear = true;

    if((year%100 == 0))
    {
      isLeapYear = false;

      if(year%400 == 0)
      {
        isLeapYear == true;
      }
    }
  }

  return isLeapYear;

}


int main(void)
{

  int year=1582;

  printf("These are the leap years\n");

  while(year != 2101)
  {
    if(leapyear(year))
    {
      printf("%d\n ", year);
    }

    year++;
  }

  return 0;
}