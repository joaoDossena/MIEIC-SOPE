#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_LENGTH 256

int main(int argc, char* argv[])
{
	FILE *src, *dest;
	char buf[BUF_LENGTH];

	if(argc != 3)
	{
		printf("Error: %s\n", strerror(errno));
		printf("Usage: %s <source> <destination>\n", argv[0]);
		exit(errno);
	}

	if((src = fopen(argv[1], "r")) == NULL)
	{
		printf("Error: %s\n", strerror(errno));
		printf("Usage: %s <source> <destination>\n", argv[0]);
		exit(errno);
	}

	if((dest = fopen(argv[2], "w")) == NULL)
	{
		printf("Error: %s\n", strerror(errno));
		printf("Usage: %s <source> <destination>\n", argv[0]);
		exit(errno);
	}

	while(fgets(buf, BUF_LENGTH, src) != NULL)
	{
		fputs(buf, dest);
	}

	fclose(src);
	fclose(dest);

	exit(0);
}