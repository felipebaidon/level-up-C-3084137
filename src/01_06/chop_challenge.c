#include <stdio.h>
#include <stdlib.h>

char *left(char *s,int len)
{
	char *newArray = (char *)malloc(sizeof(char)* (len+1));

	for(int i  = 0; i < len ; i++)
	{
		*(newArray + i)= *(s+i);
	}

	newArray[len]  = '\0'; 

	return newArray;
}

char *right(char *s,int len)
{

	char *newArray = (char *)malloc(sizeof(char)*(len+1));
	int completeLen = 0;

	if (newArray== NULL)
	{
		exit(1);
	}

	while(*s != '\0')
	{
		s++;
		completeLen;
	}

	for(int i = 0; i < len; i++)
	{
		*(newArray + i) = s[completeLen - len + i];
	}
	newArray[len] = '\0';

	return newArray;
}

char *mid(char *s,int offset, int len)
{
	char *newArray =  (char *)malloc(sizeof(char)*(len + 1));

	if(newArray == NULL)
	{
		exit(1);
	}

	for(int i=0; i < len; i++)
	{
		*(newArray + i) = *(s + offset + i);
	}

	newArray[len] = '\0';
	return newArray;
}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n",string);
	printf("Left %d characters: %s\n",16,left(string,16));
	printf("Right %d characters: %s\n",18,right(string,18));
	printf("Middle %d characters: %s\n",11,mid(string,13,11));

	return(0);
}
