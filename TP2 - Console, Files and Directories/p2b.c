#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
  int fd1, fd2, nr, nw;
  unsigned char buffer[BUFFER_SIZE];

  if (argc != 3) //Wrong usage
  {
    printf("Usage: %s <source> <destination>\n", argv[0]);
    exit(1);
  }

  fd1 = open(argv[1], O_RDONLY); //Opening source file in reading mode

  if(fd1 == -1) //There was an error opening the source file
  {
    perror(argv[1]);
    exit(2);
  }

  fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644); //Opening destination file in writing mode

  if(fd2 == -1) //There was an error opening the destination file
  {
    perror(argv[2]);
    close(fd1);
    exit(3);
  }

  while((nr = read(fd1, buffer, BUFFER_SIZE)) > 0) //While it doesn't get to the end of the file
  {
      if((nw = write(fd2, buffer, nr)) <= 0 || nw != nr) //If there's an error writing
      {
        perror(argv[2]);
        close(fd1);
        close(fd2);
        exit(4);
      }
  }
    
  close(fd1);
  close(fd2);
  
  exit(0);
}

