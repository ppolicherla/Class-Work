#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int readX();
void writeX(int);
void action(int);
void action(int dummy)
{
    usleep(100);
}

int main(int argc, char *argv[])
{
    pid_t pid;
    int x = 19530;
    int itcount = 0;
    writeX(x);
    printf("x = %d\n", x);

    if ((pid = fork()) > 0)
    { //parent
        usleep(100);
        while (1)
        {
            if (itcount>=5)
            {
                exit(1);
            }
            itcount++;
            printf("\nITERATION %d\n", itcount);
            x = readX();
            x -= 5;
            writeX(x);
            printf("Parent: x = %d\n", x);
            kill(pid, SIGUSR1);
            signal(SIGUSR1, action);
            pause();
        }
    }
    else if (pid == 0)
    {

        while (1)
        { //child
            signal(SIGUSR1, action);
            pause();
            x = readX();
            x /= 5;
            writeX(x);
            printf("Child: x = %d\n", x);
            kill(getppid(), SIGUSR1);
        }
    }
}
int readX()
{
    char xChar[10]; // xChar: our value as a char
    int fd;         // fd: file descriptor

    // open to read and store x
    if ((fd = open(".shareX.dat", O_RDONLY)) == -1)
    {
        perror("Error opening file");
        exit(2);
    }

    // read xChar from the file
    if (read(fd, xChar, 10) == -1)
    {
        perror("Error reading file");
        exit(3);
    }

    // close file for reading
    close(fd);

    // convert xChar to int and return
    return atoi(xChar);
}

/// Writes the writeX value to the file .shareX.dat
void writeX(int writeX)
{
    char xChar[10]; // xChar: our value as a char
    int fd;         // fd: file descriptor
    int xBytes;     // how much to write

    // open, clear, and create file if not createdi
    if ((fd = open(".shareX.dat", O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
    {
        perror("Error opening file");
        exit(4);
    }

    // convert x to char
    xBytes = sprintf(xChar, "%d", writeX);

    // put xChar in file
    if (write(fd, xChar, xBytes) == -1)
    {
        perror("Error writing to file");
        exit(5);
    }

    // close the file for writing
    close(fd);

    return;
}