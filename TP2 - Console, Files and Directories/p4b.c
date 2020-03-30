#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>

#define MAX_NAME_SIZE   50
#define MAX_GRADE_SIZE  2
#define MAX_STUDENTS    30

typedef struct student
{
  char name[MAX_NAME_SIZE+1];
  int grade;
} student_t;

int main(int argc, char* argv[])
{
	int file_desc;
	student_t s;
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
      memset(s.name,0,sizeof(s.name)); //Clears string "name"
      memset(grade,0,sizeof(grade)); //Clears string "grade"

      printf("Student %d: ", i+1);
      fgets(s.name, MAX_NAME_SIZE+1, stdin);

      if(s.name[strlen(s.name)-1] == '\n')
       	s.name[strlen(s.name)-1] = '\0';
      else
       	getchar();

      if(s.name[0] == '\0') 
       	break;

      printf("Grade %d: ", i+1);
      fgets(grade,MAX_GRADE_SIZE+1,stdin);

      if(grade[strlen(grade)-1] == '\n')
       	grade[strlen(grade)-1] = '\0';
		  else
			  getchar();

      s.grade = atoi(grade);

		  if(write(file_desc, &s, sizeof(student_t)) != sizeof(student_t))
      {
         perror("Error writing student!\n");
         close(file_desc);
         exit(3);
      }

    	i++;
  }

  close(file_desc);



  if((file_desc = open(argv[1], O_RDONLY)) < 0)
  {
      perror("Error opening file for reading");
      exit(4);
  }

  printf("Showing students entered:\n");

  while(read(file_desc, &s, sizeof(student_t)) != 0)
  {
    printf("Name: %s  Grade: %d\n", s.name, s.grade);
  }

  close(file_desc);

	exit(0);
}