
#define _POSIX_SOURCE 1
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>

float power(float x, int n)
{
    if (n == 0)
        return 1.0f;

    int descr[2];
    pid_t pid;

    pipe(descr);
    pid = fork();
    if (pid != 0) // Parent process
    {
        close(descr[1]); // Close write end
        wait(NULL);

        float result;
        read(descr[0], &result, sizeof(float));
        close(descr[0]);

        return result;
    }
    else if (pid == 0) // Child process
    {
        close(descr[0]); // Close read end

        float result;
        if (n % 2 == 0)
        {
            result = power(x, n / 2);
            result = result * result;
        }
        else
        {
            result = power(x, (n - 1) / 2);
            result = x * result * result;
        }

        write(descr[1], &result, sizeof(float));
        close(descr[1]);
        exit(EXIT_SUCCESS);
    }
    return 1.0f;
}

int main(void)
{
    float x;
    int n;
    printf("Calculate x^n --\n");

    printf("\nEnter a float value (x): ");
    scanf("%f", &x);
    printf("\nEnter an integer value (n): ");
    scanf("%d", &n);

    printf("\nResults : %f\n", power(x, n));

    return EXIT_SUCCESS;
}
