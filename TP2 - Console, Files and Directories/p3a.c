#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
  int file_desc, nr;
  unsigned char buffer[BUFFER_SIZE];
  struct stat buf;

  if (argc != 2) //Wrong usage
  {
    printf("Usage: %s <file>\n", argv[0]);
    exit(1);
  }

  file_desc = open(argv[1], O_RDONLY); //Opening file in reading mode

  if(file_desc == -1) //There was an error opening the file
  {
    perror(argv[1]);
    exit(2);
  }

  fstat(file_desc, &buf);

  nr = read(file_desc, &buffer, buf.st_size);

  write(STDOUT_FILENO, &buffer, buf.st_size);
    
  close(file_desc);

  exit(0);
}

