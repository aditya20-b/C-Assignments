## AIM:
Write a program to input an array, apply bubble sort and search for an element in the sorted or unsorted array
## ALGORITHM:
1. Declare an array and get its input from the user
2. Ask the user if they want to sort the array
3. If the user wants to sort the array, apply bubble sort and store the sorted array in a new array
4. If the user does not want to sort the array, use the original unsorted array
5. Ask the user to enter the element that they want to search for in the array
6. Search for the element in the array using a search function
7. If the element is not found, print a message saying it is not present in the array
8. If the element is found, print a message saying it is present in the array and its index
## CODE:
```c
#include <stdio.h>

void get_array_input(int array_length, int array_val[]) {
    for (int i=0; i<array_length; i++) {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &array_val[i]);
    }
}

void print_array(int array_length, int array_val[]) {
    for (int i=0; i<array_length; i++) {
        printf("%d ", array_val[i]);
    }
    printf("\n");
}

int array_length(int array_val[]) {
    int array_length = 0;
    for (int i=0; array_val[i] != '\0'; i++) {
        array_length++;
    }
    return array_length;
}

void bubble_sort(int array_length, int array_val[], int sorted_array[]) {
    int temp;
    // Store the contents in the sorted array
    for (int i=0; i<array_length; i++) {
        sorted_array[i] = array_val[i];
    }
    // Sort the array
    for (int i=0; i<array_length; i++) {
        for (int j=0; j<array_length-i-1; j++) {
            if (sorted_array[j] > sorted_array[j+1]) {
                temp = sorted_array[j];
                sorted_array[j] = sorted_array[j+1];
                sorted_array[j+1] = temp;
            }
        }
    }
}

int search_array(int array_length, int array_val[], int search_val) {
    int search_index = -1;
    for (int i=0; i<array_length; i++) {
        if (array_val[i] == search_val) {
            search_index = i;
            break;
        }
    }
    return search_index;
}

void search_or_sort(int array[], int array_length) {
    int search_input;
    printf("Enter the number that you want to search in the array: ");
    scanf("%d", &search_input);
    int search_index = search_array(array_length, array, search_input);
    if (search_index == -1) {
        printf("The element %d is not present in the array\n", search_input); 
    } else {
        printf("The element %d is present in the array at index %d\n", search_input, search_index);
    }
    printf("The array is: ");
    print_array(array_length, array);
}

int main() {
    int array_length_input;
    printf("Enter the length of the array: ");
    scanf("%d", &array_length_input);
    int array_val[array_length_input];
    char sort_input;
    int sorted_array[array_length_input];
    get_array_input(array_length_input, array_val);
    printf("Do you want to sort the array? (y/n): ");
    scanf(" %c", &sort_input);
    if (sort_input == 'y') {
        bubble_sort(array_length_input, array_val, sorted_array);
        search_or_sort(sorted_array, array_length_input);
    } else {
        search_or_sort(array_val, array_length_input);
    }

}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc sorting_and_searching.c -o sorting_and_searching
aditya@LAPTOP:~$ ./sorting_and_searching
Enter the length of the array: 5
Enter the element 1: 3
Enter the element 2: 2
Enter the element 3: 1
Enter the element 4: 5
Enter the element 5: 4
Do you want to sort the array? (y/n): y
Enter the number that you want to search in the array: 3
The element 3 is present in the array at index 2
```

## RESULT:
The program will take an array as input from the user, apply bubble sort if requested, and search for an element in the sorted or unsorted array. It will then print a message indicating whether the element was found and its index in the array.
