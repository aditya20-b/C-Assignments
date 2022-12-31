## AIM
To get an array of elements, reverse it and print it to the user.

## ALGORITHM
1. Get the length of the array from the user.
2. Get the elements of the array from the user.
3. Reverse the array by storing each element of the original array at the corresponding position in the 4.reversed array starting from the last element.
4. Print the reversed array to the user.

## CODE
```c
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
```
## OUTPUT
```
aditya@LAPTOP:~$ gcc array_reverse.c -o array_reverse
aditya@LAPTOP:~$ ./array_reverse
Enter the length of the array: 5
Enter the elements of the array:
Enter the element at index 0: 1
Enter the element at index 1: 2
Enter the element at index 2: 3
Enter the element at index 3: 4
Enter the element at index 4: 5
The reversed array is: 5 4 3 2 1
```

## RESULT
An array of elements will be obtained from the user, reversed and printed to the user.