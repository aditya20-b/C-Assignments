/*
Write a program to display n natural numbers and find them sum of them
*/


#include <stdio.h>

int main() {
    int i, n, sum = 0;
    printf("Enter the number of natural numbers: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
        sum = sum + i;
    }
    printf("\nThe sum of natural numbers is: %d", sum);
    return 0;
}
