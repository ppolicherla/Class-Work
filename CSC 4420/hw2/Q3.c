#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char *argv[]){
	pid_t child;

	printf("Parent id before termination = %d\n" , getppid());
	child = fork();

	if(child < 0){
		printf("error!!!");
		exit(1);
	}
	else if(child == 0){
		printf("You're in the child now\n");
		exit(0);
	}
	else{
		printf("I am the parent!\n");
	
	}
	printf("parent has died now, so sad\n");
	printf("parent id after termination = %d\n", getppid());
	return 0;
}
