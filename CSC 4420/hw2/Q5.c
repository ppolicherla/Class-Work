#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc,char *argv[]){

	pid_t bork;
	int i =0;
	for (i =0; ;i++){
		bork = fork();
		if (bork<0){
			perror("errors for days@@@!!!!");
			exit(1);
		}
	        if(bork == 0){
			printf("this is a child #%d: pid=%d\n ", i+1, getpid() );
		}	
		else{
			wait(NULL);
		}
		
	}

}
