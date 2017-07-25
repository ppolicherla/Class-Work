#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int *output = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    pid_t pid;
    int x = 19530;
    int status;
    *output = x;
    int i;

    printf("\nx = %d\n", x);

    for (i = 1; i < 6; i++)
    {
        printf("\nITERATION %d\n", i);
        pid = fork();
        switch (pid)
        {
        case 0:
            while (wait(&status) != pid)
            {
                *output = *output / 5;
                printf("Parent: x = %d\n", *output);
                break;
            }
            break;

        case -1:

            perror("error");
            break;

        default:

            *output = *output - 5;
            printf("Child: x = %d\n", *output);
            exit(0);
        }
    }
    return 0;
}

