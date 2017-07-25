#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

int fd;
int head = atoi(argv[1]);
int tail = atoi(argv[2]);
int linecount = 0;
char buffer[1];
ssize_t num;

 if ((fd = open(argv[3], O_RDONLY)) == -1){
  perror("error encountered");
  exit(1);
 }

while ((num=read(fd, buffer, 1))>0){
  if (*buffer=='\n'){
   linecount ++;
   }
   if (linecount >= head && linecount <= tail){
    if (write(STDOUT_FILENO, buffer, 1)!= num){
     perror("error");
     exit(3);
     }
    }

   }	


if (num==-1){
 perror("reading error");
 exit(2);
}

close(fd);
exit(0);

}
