#include <stdio.h>
#include <stdbool.h>

int is_prime(int iter, int num) {
    // Use recursion to check if a number is prime
    if (num == iter) {
        return false;
    }
    else if (num % iter == 0) {
        return true;
    }
    else {
        return is_prime(iter+1, num);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf(" %d", &num);
    if (is_prime(2, num)) {
        printf("The number is not a prime number");
    }
    else {
        printf("The number is a prime number");
    }
}
