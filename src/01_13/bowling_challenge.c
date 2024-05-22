#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
  int availablePins = 10;
  int knockeddownPins = 0;
  int throws =  2;
  int isfirstThrow = 1;
  char Output[2] = "- ";
  int score = 0;

  time_t t;
  srand((unsigned)time(&t));


  while(throws > 0)
  {
    puts("Throwing ball!");
    knockeddownPins = rand()%(availablePins + 1);
    printf("Knocked down %d pins!\n", knockeddownPins);
    availablePins -= knockeddownPins;
    throws--;
    if((availablePins == 0) && (isfirstThrow))
    {
      Output[0] = 'X';
      score = 10;
      puts("Strike!!");
      break;
    }
    else if(availablePins == 0)
    {
      Output[0] = '/';
      score = 10;
      puts("Spaare!!");
    }
    else if(availablePins != 10)
    {
      score += knockeddownPins;
      snprintf(Output,sizeof(char) + 1,"%d",score);
    }

    isfirstThrow = 0;
  }

  if(Output[0] == 'X')
  {
    throws = 2;
    availablePins = 10;
    isfirstThrow = 1;
  }
  else if(Output[0] == '/')
  {
    throws = 1;
    availablePins = 10;
    isfirstThrow = 1;
  }

  while(throws > 0)
  {
    knockeddownPins = rand() % (availablePins + 1);
    printf("Knocked down %d pins!\n", knockeddownPins);
    availablePins -= knockeddownPins;
    score += knockeddownPins;
    if ((availablePins == 0))
    {
      availablePins =  10;
    }
    throws--;
  }

  printf("1st frame: %c\n Score: %d\n", Output[0], score);

}