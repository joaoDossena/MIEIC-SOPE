#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 2


int main(int argc, char* argv[], char* envp[])
{

	FILE *src;
	char str[256]; 
	char* token;
	char* array[ARRAY_SIZE];

	src = fopen(argv[1], "r");

	if(src == NULL)
	{
		printf("Error opening file!\n");
		return 1;
	}

	fgets(str, 256, src);

	token = strtok(str, ";|");
	array[0] = token;


	int counter = 1;
	while(token != NULL)
	{
      token = strtok(NULL, ";|");
    	

      if(token == NULL)
      	break;
      array[counter] = token;
      counter++;
    }

	for(unsigned int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%s\n", array[i]);
	}

	return 0;
}