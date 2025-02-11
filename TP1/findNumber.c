#include <stdio.h>

void findNumber() {
    int ram[1];
    int i = 1;
    int maxIt = 1000000;
    while (ram[i] != 10 && i > -maxIt) {
        i--;
    }
    if(i == -maxIt) {
        printf("Number not found\n");
    } else {
        printf("Number found at adress %p = %d\n", &ram[i], ram[i]);
    }
}

int main(void){
    int a = 2024;
    findNumber();
    return 0;
}