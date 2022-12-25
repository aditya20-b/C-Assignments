/*
Write a program to get an array of elements and then reverse the array and store it in a different variable, 
Then print out the array to the end user 
*/

#include <stdio.h>

int main() {
    int array[100], array_reverse[100], array_length;
    printf("Enter the length of the array: ");
    scanf("%d", &array_length);
    printf("Enter the elements of the array: \n");
    for (int i=0; i<array_length; i++) {
        printf("Enter the element at index %d: ", i); 
        scanf("%d", &array[i]);
    }
    for (int i=0; i<array_length; i++) {
        array_reverse[i] = array[array_length-i-1];
    }
    printf("The reversed array is: ");
    for (int i=0; i<array_length; i++) {
        printf("%d ", array_reverse[i]);
    }
    return 0;
}