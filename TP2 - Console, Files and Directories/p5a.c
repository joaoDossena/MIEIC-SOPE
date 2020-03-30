#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
  int fd;
  char *text1="AAAAA";
  char *text2="BBBBB";

  if((fd = open("f1.txt", O_CREAT|O_TRUNC|O_WRONLY|O_SYNC, 0600)) == -1)
  {
    perror("Error opening f1.txt");
    exit(1);
  }

  getchar();

  if(write(fd,text1,5) < 0)
  {
  	perror("Error writing text1 to file f1.txt");
  	close(fd);
  	exit(2);
  }
  
  getchar();

  if(write(fd,text2,5) < 0)
  {
  	perror("Error writing text2 to file f1.txt");
  	close(fd);
  	exit(2);
  }
  
  close(fd);
  
  exit(0);
}

