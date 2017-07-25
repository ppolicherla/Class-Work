#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	int PID;
	char lineGot[256];
	char *cmd;
	char *arg[3];
	while (1){
		printf("cmd: ");
		fgets(lineGot, 256, stdin); // Get a string from user (includes \n)
		cmd = strtok(lineGot, "\n"); // Get the string without the \n		
		if(strcmp(cmd, "e") == 0 ) // loop terminates when "e" is typed
			exit (0);
		// creates a new process. Parent gets the child’s process ID. Child gets 0.
		arg[0]=strtok(cmd, " ");
		arg[1]=strtok(NULL," ");
		arg[2]=strtok(NULL," ");
		arg[3]=strtok(NULL,"\n"); 
		if ((PID=fork()) > 0)
		{
			wait(NULL);
		}
		else if (PID == 0) /* child process */
		{
			execvp (arg[0], arg);
			/* exec cannot return. If so do the following */
			fprintf (stderr, "Cannot execute %s\n", cmd);
			exit(1); /* exec failed */
		}
		else if (PID == -1)
		{
			fprintf (stderr, "Cannot create a new process\n");
			exit (2);
		}
	}
}
