#include <stdio.h>
#include <string.h>

#define LettersinAlphabet 26
#define ASCIIUpperCaseA   65

//Uppercase alphabet takes ASCII values from 65(A) to 90(Z)
char alphabet[LettersinAlphabet];
char shuffledAlphabet[LettersinAlphabet];

void generateAphabet(void)
{
  int A = ASCIIUpperCaseA;
  printf("Initial Alphabet: \n");
  for (int i = 0; i < LettersinAlphabet; i++)
  {
    alphabet[i] = A + i;
    printf(" %c ", alphabet[i]);
  }

  printf("\n\n");

}

void PerfectShuffle(void)
{
  char firstHalf[LettersinAlphabet/2];
  char secondHalf[LettersinAlphabet/2];
  int ShufflesNumber = 0;
  static int j = 0;

  memcpy(&firstHalf, &alphabet[0], LettersinAlphabet/2);
  memcpy(&secondHalf, &alphabet[LettersinAlphabet / 2], LettersinAlphabet/2);

  printf("Performing shuffle...\n");

  while ((memcmp(&alphabet, &shuffledAlphabet, LettersinAlphabet) != 0))
  {
    for (int i = 0; i < LettersinAlphabet; i = i + 2)
    {
      shuffledAlphabet[i] = firstHalf[j];
      shuffledAlphabet[i + 1] = secondHalf[j++];
      printf(" %c %c", shuffledAlphabet[i], shuffledAlphabet[i + 1]);
    }

    memcpy(&firstHalf, &shuffledAlphabet[0], LettersinAlphabet/2);
    memcpy(&secondHalf, &shuffledAlphabet[LettersinAlphabet / 2], LettersinAlphabet/2);
    ShufflesNumber++;
    printf("\n");
    j = 0;
  }

  printf("\n Perfect Shuffle!\n Number of shuffles is: %d\n", ShufflesNumber);
}

int main(void)
{
  generateAphabet();
  PerfectShuffle();

  printf("\n\n");
  return 0;
  }