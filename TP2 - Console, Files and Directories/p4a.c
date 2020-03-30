#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>

#define MAX_NAME_SIZE   60
#define MAX_GRADE_SIZE  2
#define MAX_STUDENTS    30

int main(int argc, char* argv[])
{
	int file_desc;
	char name[MAX_NAME_SIZE + 1];
	char grade[MAX_GRADE_SIZE + 1];

	if(argc != 2)
	{
		printf("Usage: %s <destination>\n", argv[0]);
		exit(1);
	}


	if((file_desc = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0)
	{
		printf("Error opening file %s!\n", argv[1]);
		exit(2);
	}

	printf("Press ENTER to stop reading!\n");
	printf("Write students' names and grades:\n");

	unsigned int i = 0;

	while(i < MAX_STUDENTS)
	{
		memset(name,0,sizeof(name)); //Clears string "name"
      	memset(grade,0,sizeof(grade)); //Clears string "grade"

      	printf("Student %d: ", i+1);
      	fgets(name, MAX_NAME_SIZE+1, stdin);

      	if(name[strlen(name)-1] == '\n')
        	name[strlen(name)-1] = '\0';
        else
        	getchar();

        if(name[0] == '\0') 
        	break;

        printf("Grade %d: ", i+1);
      	fgets(grade,MAX_GRADE_SIZE+1,stdin);

      	if(grade[strlen(grade)-1] == '\n')
        	grade[strlen(grade)-1] = '\0';
		else
			getchar();


		if(write(file_desc, name, strlen(name)) != strlen(name))
		{
        	perror("Error writing name!\n");
        	close(file_desc);
        	exit(3);
      	}

      	if(write(file_desc, " ", 1) != 1)
      	{
        	perror("Error writing space!\n");
        	close(file_desc);
        	exit(3);
      	}

      	if(write(file_desc, grade, strlen(grade)) != strlen(grade))
      	{
        	perror("Error writing grade!\n");
         	close(file_desc);
         	exit(3);
      	}

       	if(write(file_desc, "\n", 1)!=1)
       	{
        	perror("Error writing new line!\n");
         	close(file_desc);
         	exit(3);
      	}

    	i++;
   	}

   	close(file_desc);

	exit(0);
}