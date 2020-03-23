#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE *source, *destination;
	source = fopen(argv[1], "r"); 
	destination = fopen(argv[2], "w");
	char* line;

	if(argc != 3)
	{
		printf("Usage: %s [source] [destination]", argv[0]);
		return 1;
	}


	while(fgets(line, 256, source))
	{
		printf("Here!\n");

		fputs(line, destination);
	}
	fclose(source);
	fclose(destination);


	return 0;
}