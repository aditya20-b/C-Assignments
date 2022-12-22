/*
If a five-digit number is input through the keyboard, write a program to calculate the sum of its digits.
*/

#include <stdio.h>

int main() {
    int number, sum = 0, remainder;
    printf("Enter a five digit number: ");  // Get a five digit number from the user
    scanf("%d", &number);                   // Store the number in the variable number
    while (number != 0) {                   // Read the number until it is not equal to 0
        remainder = number % 10;             // Get the remainder of the number
        sum = sum + remainder;               // Add the remainder to the sum               
        number = number / 10;               // Divide the number by 10
    }                                       // Repeat the process until the number is 0
    printf("The sum of digits is: %d", sum);
    return 0;
}

