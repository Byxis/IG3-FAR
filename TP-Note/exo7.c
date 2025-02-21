#include <stdio.h>

int main(int argc, char** argv)
{
    for (int i = 10; i >= 0; i--) 
    {
        printf("%d -- %f \n", i, ((float)(i))/2);
    }
    return 0;
}