#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char *argv[]){

	FILE *file;
	int id;
	char hold[128];
	int index =1;

	printf("pid=%d\n", getpid());
	printf("ppid=%d\n", getppid());

	id=getppid();

	while(id>1){
		sprintf(hold, "/proc/%d/stat", id);
	        file=fopen(hold, "r");
	        if(file == NULL){
	       	   break;
		}

	        fscanf(file, "%*d %*s %*s %d", &id);
	        fclose(file);
	        printf("gp%d id=%d\n", index++, id);
	 }
	return 0;
}
