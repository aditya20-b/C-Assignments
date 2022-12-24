/*
Write a function that calculates the sum of all the elements in a given array using recursion.
*/

#include <stdio.h>

int sum_of_all_elements(int array[], int length) {
    if (length == 0) {
        return 0;
    } else {
        return array[length - 1] + sum_of_all_elements(array, length - 1);
    }
}


int main() {
    int array[100], length;
    printf("Enter the length of the array: ");
    scanf(" %d", &length);
    printf("Enter the elements of the array: \n");
    for (int i=0; i<length; i++) {
        printf("Enter the element %d: ", i+1);
        scanf(" %d", &array[i]);
    }
    int sum = sum_of_all_elements(array, length);
    printf("The sum of all the elements in the array is: %d", sum);
}
