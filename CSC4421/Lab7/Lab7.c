#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int x = 19530;
    pid_t childpid;
    int child[2], parent[2];
    int i, j;

    printf("x = %d\n\n", x);

    if (pipe(parent) == -1 || pipe(child) == -1)
    {
        perror("failed to pipe");
        exit(-1);
    }

    if ((childpid = fork()) <= -1)
    {
        perror("failed to fork");
        exit(-1);
    }
    if (childpid==0)
    {
        close(parent[1]);
        close(child[0]);
    }
    else
    {
        close(parent[0]);
        close(child[1]);
    }
    for (i = 0; i < 5; i++)
    {
        if (childpid == 0)
        {
            usleep(100);
            printf("ITERATION %d\n", i+1);

            if (read(parent[0], &x, sizeof(x)) <= 0)
            {
                perror("Child failed to read from the pipe.");
                exit(-1);
            }
            x -= 5;

            if (write(child[1], &x, sizeof(x)) <= 0)
            {
                perror("Child: failed to write to the pipe");
                exit(-1);
            }
            printf("Child : x = %d\n", x);
        }

        else
        {
            if (write(parent[1], &x, sizeof(x)) <= 0)
            {
                perror("parent: failed");
                exit(-1);
            }

            if (read(child[0], &x, sizeof(x)) <= 0)
            {
                perror("Parent: failed to read from the pipe");
                exit(-1);
            }

            x /= 5;
            printf("Parent : x = %d\n\n", x);
        }
    }

    return 0;
}
