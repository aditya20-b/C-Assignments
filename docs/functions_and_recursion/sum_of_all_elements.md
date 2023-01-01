## AIM:
To write a function that calculates the factorial of a given number using recursion.

## ALGORITHM:
1. Define the function `sum_of_all_elements()` which takes in an array and its length as input.
2. In the function, check if the length of the array is zero. If it is, return zero.
3. If the length of the array is not zero, return the value of the last element in the array plus the sum of all elements in the array, excluding the last element.
4. In the main function, get the length of the array and the elements of the array as input from the user.
5. Call the `sum_of_all_elements()` function with the array and its length as arguments.
6. Print the sum of all elements in the array.
## CODE:
```c
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
```

## OUTPUT
```
aditya@LAPTOP:~$ gcc sum_of_all_elements.c -o sum_of_all_elements
aditya@LAPTOP:~$ ./sum_of_all_elements
Enter the length of the array: 5
Enter the elements of the array:
Enter the element 1: 1
Enter the element 2: 2
Enter the element 3: 3
Enter the element 4: 4
Enter the element 5: 5
The sum of all the elements in the array is: 15
```

## RESULT:
The sum of all the elements in the array will be printed on the screen