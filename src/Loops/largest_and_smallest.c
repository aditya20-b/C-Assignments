/*
Get an input of n numbers and find the largest and smallest out of the entered array
*/

#include <stdio.h>

int main() {
    int array[100], i, n, largest, smallest;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the array: ");
    for (i = 0; i < n; i++) {
        printf("\nEnter the element %d: ", i);
        scanf("%d", &array[i]);
    }
    largest = array[0];
    smallest = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }

    printf("\nThe largest element in the array is %d", largest);
    printf("\nThe smallest element in the array is %d", smallest);
}
