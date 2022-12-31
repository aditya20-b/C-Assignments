## AIM:
To find the largest and smallest elements in an array of numbers

## ALGORITHM:
1. Declare and initialize variables for the array, its size, and two variables to store the largest and smallest element
2. Prompt the user to enter the size of the array and then get the elements of the array from the user
3. Set the largest and smallest elements to the first element in the array
4. Iterate through the array with a loop starting from the second element
5. For each element in the array, compare it to the largest and smallest elements. If it is larger than the largest element, set the largest element to this element. If it is smaller than the smallest element, set the smallest element to this element
6. After the loop ends, print the largest and smallest elements

## CODE:
```c
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
```
## OUTPUT:
```
aditya@LAPTOP:~$ gcc largest_and_smallest.c -o largest_and_smallest
aditya@LAPTOP:~$ ./largest_and_smallest
Enter the number of elements in the array: 5
Enter the elements of the array:
Enter the element 0: 1
Enter the element 1: 2
Enter the element 2: 3
Enter the element 3: 4
Enter the element 4: 5
The largest element in the array is 5
The smallest element in the array is 1
```

## FLOWCHART:
<img src="https://cdn.discordapp.com/attachments/1027218472675069962/1058724133178982531/C4E5Xj.png" alt="FLOWCHART" height="800px"/>

## RESULT:
The largest and smallest elements in the array are printed to the screen