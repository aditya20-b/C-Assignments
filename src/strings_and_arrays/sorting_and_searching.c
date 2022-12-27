/*
Get an array input from the user and then apply bubble sort to the array and
store it in a variable called sorted_array[] then after sorting the array, ask the
user to enter the element that they wish to search in it and search through
the sorted array to find out which element the input element corresponds to
*/

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
