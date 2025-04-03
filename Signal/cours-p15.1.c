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
    char buffer[256];
    pipe(descr);

    int somme = 0;
    int count = 0;
    pid = fork();
    if (pid != 0) // Parent process
    {
        close(descr[1]);
        printf("Parent process\n");
        bool running = true;
        while (running)
        {
            read(descr[0], buffer, 256);
            if (!strcmp(buffer, "END"))
            {
                running = false;
            }
            else
            {
                int nb = atoi(buffer);
                somme += nb;
                count++;
                printf("\n(Received : %d) \n", nb);
            }
        }
        wait(NULL);
        printf("Mean = %.2f\n", (float)somme / count);
    }
    else if (pid == 0) // Child process
    {
        printf("Child process\n");
        bool choosing = true;
        int nb;
        while (choosing)
        {
            printf("\nChoose a number : ");
            scanf("%d", &nb);

            sprintf(buffer, "%d", nb);
            write(descr[1], buffer, 256);

            printf("\nDo you want to continue (1 for yes, 0 for no): ");
            scanf("%d", &choosing);

            if (!choosing)
            {
                choosing = false;
                sprintf(buffer, "END");
                write(descr[1], buffer, 256);
            }
        }
        close(descr[1]);
    }
    return EXIT_SUCCESS;
}

/*
int NB_THREADS = 10000;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Variable globale = partagee par tous les threads.
int somme = 0;
int count = 0;
bool choosing = true;

// Run by each thread
void *Fils(void *t)
{
    pthread_mutex_lock(&mutex);
    int nb;
    int i = (long)t;
    printf("\nChoose a number : ");
    scanf("%d", &nb);

    somme += nb;
    count++;

    pthread_mutex_unlock(&mutex);

    printf("Fils %d : somme = %d \n", i, somme);

    // ends the thread so that it doesn't come back in the main
    pthread_exit(0);
}

int main(int argc, char **argv)
{
    pthread_t tid;
    pthread_t Threads_id[NB_THREADS];
    int i = 0;

    printf("Père : somme = %d\n", somme);
    while (choosing)
    {
        if (pthread_create(&tid, NULL, Fils, NULL) != 0)
        {
            printf("pthread_create\n");
            exit(1);
        }
        else
        {
            Threads_id[i] = tid;
        }

        pthread_join(Threads_id[i], NULL);

        printf("\nDo you want to continue (1 for yes, 0 for no): ");
        scanf("%d", &choosing);
        i++;
    }
    printf("Mean = %.2f\n", (float)somme / count);

    return EXIT_SUCCESS;
}
*/