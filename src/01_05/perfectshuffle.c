#include <stdio.h>
#include <string.h>

//Uppercase alphabet takes ASCII values from 65(A) to 90(Z)
char alphabet[26];
char shuffledAlphabet[26];

void generateAphabet(void)
{
  int A = 65;
  for(int i= 0; i<26 ; i++)
  {
    alphabet[i] = A + i;
    //printf(" %c ", alphabet[i]);
  }

  printf("\n\n");

}

void PerfectShuffle(void)
{
  char firstHalf[13];
  char secondHalf[13];
  int ShufflesNumber = 0;
  static int j = 0;

  memcpy(&firstHalf,&alphabet[0],13);
  memcpy(&secondHalf, &alphabet[13], 13);

  while((memcmp(&alphabet,&shuffledAlphabet,26) != 0))
  {
    for (int i = 0; i < 26; i = i + 2)
    {
      shuffledAlphabet[i] = firstHalf[j];
      shuffledAlphabet[i + 1] = secondHalf[j++];
      printf(" %c %c", shuffledAlphabet[i], shuffledAlphabet[i + 1]);
    }

    memcpy(&firstHalf, &shuffledAlphabet[0], 13);
    memcpy(&secondHalf, &shuffledAlphabet[13], 13);
    ShufflesNumber++;
    printf("\n");
    j = 0;
  }

  printf("\n number of shuffles is: %d\n", ShufflesNumber);
}

int main(void)
{
  generateAphabet();

  PerfectShuffle();

  printf("\n\n");
  return 0;
  }