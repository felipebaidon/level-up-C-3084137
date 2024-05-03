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

  memcpy(&firstHalf,&alphabet[0],13);
  memcpy(&secondHalf, &alphabet[13], 13);

  for(int i = 0; i < 26; i=i + 2)
  {
    static int j=0;
    shuffledAlphabet[i] = firstHalf[j];
    shuffledAlphabet[i+1] = secondHalf[j++];
    printf(" %c %c", shuffledAlphabet[i], shuffledAlphabet[i+1]);
  }

}

int main(void)
{
  generateAphabet();

  PerfectShuffle();

  printf("\n\n");
  return 0;
  }