#define _POSIX_SOURCE 1
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    pid_t pid;
    int descr[2];
    int descr2[2];
    int buffer;

    pipe(descr);
    pipe(descr2);

    srand(time(NULL));

    const int NB_OF_SEND = 5;

    pid = fork();
    if (pid != 0) // Parent process
    {
        int received = 0;
        printf("Parent process\n");

        close(descr[0]);  // Close read end of pipe 1
        close(descr2[1]); // Close write end of pipe 2

        printf("\nSended : ");
        for (int i = 0; i < NB_OF_SEND; i++)
        {
            buffer = rand() % 100;
            if (i == NB_OF_SEND - 1)
            {
                printf("%d", buffer);
            }
            else
            {
                printf("%d, ", buffer);
            }
            write(descr[1], &buffer, sizeof(buffer));
        }

        printf("\nResults : ");
        while (received < NB_OF_SEND)
        {
            read(descr2[0], &buffer, sizeof(buffer));
            if (received == NB_OF_SEND - 1)
                printf("%d\n", buffer);
            else
                printf("%d, ", buffer);
            received++;
        }

        close(descr2[0]); // Close read end of pipe 2
        close(descr[1]);  // Close write end of pipe 1
    }
    else if (pid == 0) // Child process
    {
        printf("Child process\n");

        close(descr[1]);  // Close write end of pipe 1
        close(descr2[0]); // Close read end of pipe 2

        for (int i = 0; i < NB_OF_SEND; i++)
        {
            read(descr[0], &buffer, sizeof(buffer));

            printf("Child received %d, sending back %d\n", buffer, buffer + 1);
            buffer++;
            write(descr2[1], &buffer, sizeof(buffer));
        }

        close(descr[0]);  // Close read end of pipe 1
        close(descr2[1]); // Close write end of pipe 2
    }
    return EXIT_SUCCESS;
}