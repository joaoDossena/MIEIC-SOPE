#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define BUF_LENGTH 256 
int main(int argc, char* argv[])
{
    FILE *src, *dst;
    char buf[BUF_LENGTH];
    if ( ( src = fopen( argv[1], "r" ) ) == NULL )
	{     
		printf("Error: %s\n", strerror(errno));
		printf("usage: %s file1 file2", argv[0]);
		exit(errno);
	}

	if ( ( dst = fopen( argv[2], "w" ) ) == NULL )
	{
		printf("Error: %s\n", strerror(errno));
		printf("usage: %s file1 file2", argv[0]);
	    exit(errno);
    }   
    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )   
    {     
    	fputs( buf, dst );   
    }   
    fclose( src );   
    fclose( dst );   
    exit(0);  // zero é geralmente indicativo de "sucesso" 
}
