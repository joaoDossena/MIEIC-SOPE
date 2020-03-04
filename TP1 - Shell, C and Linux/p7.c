#include <stdio.h>      
#include <stdlib.h>     

void exitHandler1()
{
	printf("Executing exit handler 1\n");
}

void exitHandler2()
{
	printf("Executing exit handler 2\n");
	//exit(2); //I think this doesn't affect the handler
}

int main()
{
	atexit(exitHandler1);
	atexit(exitHandler2);

	//abort(); //Doesn't let the program finish

	printf("Main done!\n");

	return 0;
}