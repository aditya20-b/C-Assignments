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

void bubble_sort(int array_length, int array_val[]) {
    int temp;
    for (int i=0; i<array_length; i++) {
        for (int j=0; j<array_length-i-1; j++) {
            if (array_val[j] > array_val[j+1]) {
                temp = array_val[j];
                array_val[j] = array_val[j+1];
                array_val[j+1] = temp;
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

int main() {
    printf("Enter the length of the array: ");
    int array_length_input;
    scanf("%d", &array_length_input);
    int array_val[array_length_input];
    get_array_input(array_length_input, array_val);
    printf("Do you want to sort the array? (y/n): ");
    char sort_input;
    scanf(" %c", &sort_input);
    if (sort_input == 'y') {
        bubble_sort(array_length_input, array_val);
    }
    printf("Enter the number that you want to search in the array: ");
    int search_input;
    scanf("%d", &search_input);
    int search_index = search_array(array_length_input, array_val, search_input);
    if (search_index == -1) {
        printf("The element %d is not present in the array\n", search_input); 
    } else {
        printf("The element %d is present in the array at index %d\n", search_input, search_index);
    }
    printf("The array is: ");
    print_array(array_length_input, array_val);

}
