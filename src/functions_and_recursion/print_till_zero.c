/*
Write a recursive function that reads N and prints from N to 0.
*/

#include <stdio.h>

int printTillZero(int num) {
    if (num == 0) {
        return 0;
    } else {
        printf("%d ", num);
        return printTillZero(num - 1);
    }
}

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printTillZero(num);
    return 0;
}
