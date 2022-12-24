/*
Write a function that generates the Fibonacci sequence using recursion.
*/
#include <stdio.h>

void fibinocci_generator(int num, int term1, int term2) {
    if (num == 0) {
        return;
    } else {
        printf("%d ", term1);
        fibinocci_generator(num-1, term2, term1+term2);
    }
}

int main() {
    int num;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    printf("Fibinocci Series of %d terms is: ", num);
    fibinocci_generator(num, 0, 1);
    return 0;
}
