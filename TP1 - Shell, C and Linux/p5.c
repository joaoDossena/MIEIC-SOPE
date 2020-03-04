#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])  
{
	int i = 0;
	char *str;

	while(envp[i] != NULL) //Exercise a
	{
		printf("%s\n", envp[i]);
		i++;
	}


	i = 0;
	while(strncmp(envp[i], "USER=", 5) != 0) //Exercise b
	{
		if (envp[i] == NULL)
			break;
		i++;
	}
	str = envp[i];

	printf("Hello %s!\n", str + 5);

	printf("Hello %s!\n", getenv("USER")); //Exercise c

	printf("Hello %s!\n", getenv("USER_NAME")); //Exercise d

   return 0;
} 