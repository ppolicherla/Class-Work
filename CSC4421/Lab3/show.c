#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
 int fd;
 char buffer[100];
 ssize_t num;

 if ((fd = open(argv[1], O_RDONLY)) == -1){
  perror("error encountered");
  exit(1);
 }

 while ((num=read(fd, buffer, 100))>0){
  if (write(STDOUT_FILENO,buffer, num) != num){
   perror ("more errors");
   exit(3);
  }
 }

 if (num == -1){
  perror("Reading error");
  exit(2);
 }
 close(fd);
 exit(0);
}
