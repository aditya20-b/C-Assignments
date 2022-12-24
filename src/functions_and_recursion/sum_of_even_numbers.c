/*
Write a function that calculates the sum of all the even numbers between two given numbers using recursion.
*/

#include <stdio.h>

int sum_of_even_numbers(int start, int end) {
    if (start > end) {
        return 0;
    }
    else if (start % 2 == 0) {
        return start + sum_of_even_numbers(start+1, end);
    }
    else {
        return sum_of_even_numbers(start+1, end);
    }
}

int main() {
    int start, end;
    printf("Enter the starting number: ");
    scanf(" %d", &start);
    printf("Enter the ending number: ");
    scanf(" %d", &end);
    printf("The sum of all the even numbers between %d and %d is %d", start, end, sum_of_even_numbers(start, end));
}
