#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 12

int main()
{
	int values[10] = {
		123, 1899, 48266, 123456, 9876543,
		10100100, 5, 500000, 99000111, 83
	};

	char *str, *formatedOutput;
	char length;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if(str ==  NULL)
	{
		puts("Could not allocate memory for str!");
		exit(1);
	}
	formatedOutput = (char*)malloc(sizeof(char)*BUFFER_SIZE);
	if (str == NULL)
	{
		puts("Could not allocate memory for formatedOutput!");
		exit(1);
	}

	for(int i = 0; i < 10; i++)
	{
	/*convert integers to strings */
	sprintf(str,"%d",values[i]);
  
	/* Get length*/
	length =  strlen(str);
	/*Move buffers to null character*/
	str = str + length;
	formatedOutput = formatedOutput + length;

	while(length > 3)
	{
		/*Move buffers to last three digits position*/
		str = str - 3;
		formatedOutput = formatedOutput - 3;

		// take last 3 digits //
		memcpy(formatedOutput, str , 3);
		// append coma //
		formatedOutput--;
		*formatedOutput = ',';

		length= length - 3;
}
  str= str - length;
	formatedOutput= formatedOutput - length;

  memcpy(formatedOutput, str , length);
	puts(formatedOutput);
	}

	return(0);
}
