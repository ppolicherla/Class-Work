#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[]){

	struct timeval timer1, timer2;
	double totalTime;
	pid_t borky;

	gettimeofday(&timer1, NULL);
	
	borky = fork();
	
	gettimeofday(&timer2, NULL);

	if (borky == 0){
		exit(0);
	}


        totalTime = (timer2.tv_sec - timer1.tv_sec) * 1000.0;
	totalTime +=(timer2.tv_usec - timer1.tv_usec) / 1000.0;

	printf("%f ms\n", totalTime);

	return 0;
	

}
