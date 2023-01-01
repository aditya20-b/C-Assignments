# STRINGS AND ARRAYS

## AIM:
To check if the given string is a palindrome or not.

## ALGORITHM:
1. Get a string from the user and store it in a variable and then find the length of the string.
2. Check if the string is a palindrome by comparing the first character with the last character, second character with the second last character and so on.
3. If all the characters match, print the string is a palindrome. If any character does not match, print the string is not a palindrome.

## CODE:
```c
#include <stdio.h>
int main() {
    char str[100];
    int i, length = 0, flag = 0;
    printf("Enter a string: ");
    scanf("%s", str);
    while (str[length] != '\0')
        length++;
    for (i = 0; i < length; i++) {
        if (str[i] != str[length - i - 1]) {
            flag = 1;
            break;
        }
    }
    if (flag) 
        printf("%s is not a palindrome", str);
    else 
        printf("%s is a palindrome", str);
    return 0;
}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc palindrome.c -o palindrome
aditya@LAPTOP:~$ ./palindrome
Enter a string: aditya
aditya is not a palindrome
```

## RESULT:
The program will check if the given string is a palindrome or not and print the result accordingly.


<div style="page-break-after: always"></div>

## AIM:
To get two matrixes as input from the user and perform matrix addition and matrix multiplication on them

## ALGORITHM:
1. Get the number of rows and columns for the first matrix from the user and store them in variables row_input1 and column_input1
2. Create a 2D array called matrix1 with row_input1 rows and column_input1 columns
3. Create a pointer array called matrix_ptr with row_input1 elements
4. Assign the address of each row in matrix1 to each element in matrix_ptr
5. Call the function get_matrix_input() to get the values for each element in matrix1 from the user
6. Get the number of rows and columns for the second matrix from the user and store them in variables row_input2 and column_input2
7. Create a 2D array called matrix2 with row_input2 rows and column_input2 columns
8. Create a pointer array called matrix2_ptr with row_input2 elements
9. Assign the address of each row in matrix2 to each element in matrix2_ptr
10. Call the function get_matrix_input() to get the values for each element in matrix2 from the user
11. Get the choice of operation from the user
12. If the choice is 1, perform matrix addition by calling the function matrix_addition() and passing it the required parameters
13. If the choice is 2, perform matrix multiplication by calling the function matrix_multiplication() and passing it the required parameters

## CODE:
```c
#include <stdio.h>

int get_matrix_input(int rows, int cols, int *array_val[]) {
    for (int i=0; i<rows; i++) {         
        for (int j = 0; j<cols; j++) {   
            printf("\nEnter the element %d %d: ", i+1, j+1);
            scanf("%d", &array_val[i][j]);
        }
    }
    return 0;
}

void print_matrix(int rows, int cols, int *array_val[]) {
    for (int i=0; i<rows; i++) {         
        for (int j = 0; j<cols; j++) {   
            printf("%d ", array_val[i][j]);
        }
        printf("\n");
    }
}

void matrix_addition(int row1, int col1, int row2, int col2, int *array_val1[], int *array_val2[], int *array_val3[]) {
    if (row1 != row2 || col1 != col2) {
        printf("Addition operation cannot be performed on the given two matrices\n");
        return;
    }
    for (int i=0; i<row1; i++) {         
        for (int j = 0; j<col1; j++) {   
            array_val3[i][j] = array_val1[i][j] + array_val2[i][j];
        }
    }
}

void matrix_multiplication(int row1, int col1, int row2, int col2, int *array_val1[], int *array_val2[], int *array_val3[]) {
    if (col1 != row2) {
        printf("Multiplication operation cannot be performed on the given two matrices\n");
        return;
    }
    for (int i=0; i<row1; i++) {         
        for (int j = 0; j<col2; j++) {   
            array_val3[i][j] = 0;
            for (int k=0; k<col1; k++) {
                array_val3[i][j] = array_val3[i][j] + array_val1[i][k] * array_val2[k][j];
            }
        }
    }
}

int main() {
    int row_input1, column_input1, row_input2, column_input2;
    printf("Enter the number of rows for the first matrix: ");
    scanf(" %d", &row_input1);
    printf("Enter the number of columns for the first matrix: ");
    scanf(" %d", &column_input1);
    int matrix1[row_input1][column_input1];
    int choice;
    int *matrix_ptr[row_input1];
    for (int i=0; i<row_input1; i++) {  
        matrix_ptr[i] = matrix1[i];
    }
    get_matrix_input(row_input1, column_input1, matrix_ptr);
    printf("Enter the number of rows for the second matrix: ");
    scanf(" %d", &row_input2);
    printf("Enter the number of columns for the second matrix: ");
    scanf(" %d", &column_input2);
    int matrix2[row_input2][column_input2];
    int *matrix2_ptr[row_input2];
    for (int i=0; i<row_input2; i++) {
        matrix2_ptr[i] = matrix2[i];
    }
    get_matrix_input(row_input2, column_input2, matrix2_ptr);
    printf("What operations do you want to perform on the two matrices? \n");
    printf("1. Addition \n");
    printf("2. Multiplication \n");
    printf("Enter your choice: ");
    scanf(" %d", &choice);
    if (choice == 1) {
        int matrix3[row_input2][column_input2];
        int *matrix3_ptr[row_input2];
        for (int i=0; i<row_input2; i++) {
            matrix3_ptr[i] = matrix3[i];
        }
        matrix_addition(row_input1, column_input1, row_input2, column_input2, matrix_ptr, matrix2_ptr, matrix3_ptr);
        printf("The matrix is: \n");
        print_matrix(row_input1, column_input1, matrix3_ptr);
    }
    else if (choice == 2) {
        int matrix3[row_input1][column_input2];
        int *matrix3_ptr[row_input1];
        for (int i=0; i<row_input1; i++) {
            matrix3_ptr[i] = matrix3[i];
        }
        matrix_multiplication(row_input1, column_input1, row_input2, column_input2, matrix_ptr, matrix2_ptr, matrix3_ptr);
        printf("The matrix is: \n");
        print_matrix(row_input1, column_input2, matrix3_ptr);
    }
    else {
        printf("Invalid choice");
    }
}
```

<div style="page-break-after: always"></div>

## OUTPUT:
```
aditya@LAPTOP:~$ gcc matrix_operations.c -o matrix_operations
aditya@LAPTOP:~$ ./matrix_operations
Enter the number of rows for the first matrix: 2
Enter the number of columns for the first matrix: 2
Enter the element 1 1: 1
Enter the element 1 2: 2
Enter the element 2 1: 3
Enter the element 2 2: 4
Enter the number of rows for the second matrix: 2
Enter the number of columns for the second matrix: 2
Enter the element 1 1: 5
Enter the element 1 2: 6
Enter the element 2 1: 7
Enter the element 2 2: 8
What operations do you want to perform on the two matrices?
1. Addition
2. Multiplication
Enter your choice: 1
The matrix is:
6 8
10 12
```

## RESULT:
The user will be able to get two matrixes as input and perform matrix addition and matrix multiplication on them. The result of the operation will be printed to the screen.

<div style="page-break-after: always"></div>

## AIM:
To get an array of elements, reverse it and print it to the user.
## ALGORITHM:
1. Get the length of the array from the user and then get the elements of the array from the user.
2. Reverse the array by storing each element of the original array at the corresponding position in the 4.reversed array starting from the last element.
3. Print the reversed array to the user.

## CODE:
```c
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
    for (int i=0; i<array_length; i++) 
        printf("%d ", array_reverse[i]);
    return 0;
}
```
## OUTPUT:
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

## RESULT:
An array of elements will be obtained from the user, reversed and printed to the user.

<div style="page-break-after: always"></div>

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

<div style="page-break-after: always"></div>

## AIM:
To find if a given substring is present in a given string and if it is present, to find the number of occurrences of the substring in the string.

## ALGORITHM:
1. Initialize two variables: `string_length` to store the length of the given string and `substring_counter` to store the number of occurrences of the substring in the string. Initialize `length` to the length of the given string and `substring_length` to the length of the given substring.
2. Use a loop to iterate through the characters of the given string.
3. If the current character of the string is equal to the first character of the substring, use another loop to check if the characters following the current character in the string match the characters of the substring.
4. If all the characters match, increment the `substring_counter` by 1 and continue the loop. If the characters do not match, break the loop and continue with the outer loop.
5. After the loops, check if the `substring_counter` is equal to 0. If it is, print that the substring is not present in the string. If it is not equal to 0, print that the substring is present in the string and the number of occurrences.

## CODE:
```c
#include <stdio.h>

int string_length(char string[]) {
    int string_length = 0;
    for (int i=0; string[i] != '\0'; i++) {
        string_length++;
    }
    return string_length;
}

int substring_counter(char string[], char substring[]) {
    int substring_counter = 0;
    int length = string_length(string);
    int substring_length = string_length(substring);
    for (int i=0; i<length; i++) {
        if (string[i] == substring[0]) {
            for (int j=0; j<substring_length; j++) {
                if (string[i+j] == substring[j]) {
                    if (j == substring_length-1) {
                        substring_counter++;
                    }
                }
                else {
                    break;
                }
            }
        }
    }
    return substring_counter;
}

int main() {
    char string[100], substring[100];
    printf("Enter the string: ");
    scanf("%[^\n]d", string);
    printf("Enter the substring: ");
    scanf("%s", substring);
    int substrings = substring_counter(string, substring);
    if (substrings == 0) {
        printf("The substring is not present in the string");
    }
    else {
        printf("The substring is present in the string %d times", substrings);
    }
    return 0;
}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc substring.c -o substring
aditya@LAPTOP:~$ ./substring
Enter the string: HelloThere
Enter the substring: llo
The substring is present in the string 1 times
```

## RESULT:
The program will find if a given substring is present in a given string and if it is present, the number of occurrences of the substring in the string.

<div style="page-break-after: always"></div>

## AIM:
Find the mean, mode, range, variance and the standard deviation of a set of N integers, and also make the elements of the array unique.

## ALGORITHM:
1. Initialize variables for mean, range, variance, standard deviation, and mode.
2. Declare an integer called `length` to store the size of the array and then based on the `length` create the array
3. Declare a function called `get_input` to get the input values for the array. The function takes in three arguments: the array, the length of the array, and a boolean value to indicate if the elements in the array should be unique or not.
4. Declare a function called `print_array` to print the elements of the array. The function takes in two arguments: the array and its length. Use a for loop to iterate through the array and print each element.
5. Declare the functions called `compute_mean`, `compute_mode`, and `compute_range` to calculate the mean, mode, and range of the array respectively. The functions take in two arguments: the array and its length. Use a for loop to iterate through the array and calculate the mean, mode, and range.
6. Declare a function called `compute_variance` and `compute_std_deviation` to calculate the variance and standard deviation of the array respectively. The functions take in two arguments: the array and its length. Use the functions `compute_mean` and `compute_range` to calculate the variance and standard deviation.
7. In the main function call the function `get_input` to get the input values for the array. Then compute the mean, mode, range, variance, and standard deviation of the array. Finally, print the mean, mode, range, variance, and standard deviation of the array.


## CODE:

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool is_unique(float *array, int length, float val) {
    for (int i=0; i<length; i++) {
        if (array[i] == val) {
            return false;
        }
    }
    return true;
}
void get_input(float *array, int length, bool unique) {
    float _temp[length]; 
    for (int i=0; i<length; i++) {
        printf("Enter the element %d: ", i+1);
        scanf("%f", &_temp[i]);
        if (is_unique(_temp, i, _temp[i] && unique)) {
            array[i] = _temp[i];
        } else {
            i--;
        }
        // Can also be minfied as
        // is_unique(_temp, i, _temp[i]) ? array[i] = _temp[i] : i--; 
    }
}
void print_array(float *array_val, int array_length) {
    for (int i=0; i<array_length; i++) {
        printf("%0.2f ", array_val[i]);
    }
    printf("\n");
}
float compute_mean(float *array, int length) {
    float sum = 0;
    for (int i=0; i<length; i++) {
        sum = sum + array[i];
    }
    return sum/length;
}
int compute_mode(float *array, int length) {
    float mode = array[0];
    int mode_count = 1;
    for (int i=0; i<length; i++) {
        int count = 1;
        for (int j=i+1; j<length; j++) {
            if (array[i] == array[j]) {
                count++;
            }
        }
        if (count > mode_count) {
            mode = array[i];
            mode_count = count;
        }
    }
    return mode;
}
float compute_range(float *array, int length) {
  float min = array[0];
  float max = array[0];
  for (int i = 1; i < length; i++) {
    if (array[i] < min) {
      min = array[i];
    }
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max - min;
}
float compute_variance(float *array, int length) {
  float mean_val = compute_mean(array, length);
  float variance = 0;
  for (int i = 0; i < length; i++) {
    variance += (array[i] - mean_val) * (array[i] - mean_val);
  }
  return variance / length;
}
float compute_std_deviation(float *array, int length) {
  return sqrt(compute_variance(array, length));
}

int main() {
    float mean, range, variance, std_deviation;
    int mode;
    int length;
    printf("Enter the size of the array: ");
    scanf("%d", &length);
    float *array = (float *) malloc(length * sizeof(float)); 
    get_input(array, length, false);
    print_array(array, length);
    mean = compute_mean(array, length);
    mode = compute_mode(array, length);
    range = compute_range(array, length);
    variance = compute_variance(array, length);
    std_deviation = compute_std_deviation(array, length);
    printf("\nThe mean of the array is %0.3f", mean);
    printf("\nThe mode of the array is %d", mode);
    printf("\nThe range of the array is %0.3f", range);
    printf("\nThe variance of the array is %0.3f", variance);
    printf("\nThe standard deviation of the array is %0.3f", std_deviation);
}
```
## OUTPUT:
```
aditya@LAPTOP:~$ gcc mean_median_mode.c -o mean_median_mode
aditya@LAPTOP:~$ ./mean_median_mode
Enter the size of the array: 5
Enter the element 1: 1
Enter the element 2: 2
Enter the element 3: 3
Enter the element 4: 4
Enter the element 5: 5
1.00 2.00 3.00 4.00 5.00

The mean of the array is 3.000
The mode of the array is 1
The range of the array is 4.000
The variance of the array is 2.000
The standard deviation of the array is 1.414
```
## RESULT:
The mean, mode, range, variance and standard deviation of the array will be printed.

<div style="page-break-after: always"></div>

## AIM:
To display the corresponding ASCII characters for a given string.

## ALGORITHM:
1. Declare a character array called string_input to store the string input by the user.
2. Prompt the user to enter a string and use the scanf function to store the input in the string_input array.
3. Initialize a loop to iterate through the elements of the string_input array.
4. Inside the loop, print the ASCII value of each character in the string using the printf function.
5. Repeat the process for each character in the string until the end of the string is reached.

## CODE:
```c
#include <stdio.h>

int main() {
    char string_input[100];
    printf("Enter the string: ");
    scanf(" %[^\n]s", string_input);
    printf("The ascii characters are: ");
    for (int i=0; string_input[i] != '\0'; i++) {
        printf("\nThe ascii value of character %c in the string is: %d", string_input[i], string_input[i]);
    }
    printf("\n");
}
```


## OUTPUT:
```
aditya@LAPTOP:~$ gcc string_to_ascii.c -o string_to_ascii
aditya@LAPTOP:~$ ./string_to_ascii
Enter the string: Hello
The ascii characters are:
The ascii value of character H in the string is: 72
The ascii value of character e in the string is: 101
The ascii value of character l in the string is: 108
The ascii value of character l in the string is: 108
The ascii value of character o in the string is: 111
```

## RESULT:
The program will output the ASCII values of each character in the given string.

<div style="page-break-after: always"></div>

## AIM:
Reverse a string using minimum number of exchanges without using any library function.

## ALGORITHM:
1. Take a string as input from the user
2. Find the length of the string
3. Initialize a for loop with index i and iterate it until i<(string_length/2)
4. Inside the for loop, swap the characters at the index i and string_length-i-1
5. Print the reversed string

## CODE:
```c
#include <stdio.h>

int string_reverse(char *string_input) {
    int string_length = 0;
    for (int i=0; string_input[i] != '\0'; i++) {
        string_length++;
    }
    for (int i=0; i<string_length/2; i++) {
        char temp = string_input[i];
        string_input[i] = string_input[string_length-i-1];
        string_input[string_length-i-1] = temp;
    }
    return 0;
}

int main() {
    char string_input[100];
    printf("Enter the string: ");
    scanf(" %[^\n]s", string_input);
    string_reverse(string_input);
    printf("The reversed string is: %s", string_input);
}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc string_reverse.c -o string_reverse
aditya@LAPTOP:~$ ./string_reverse
Enter the string: Hello World
The reversed string is: dlroW olleH
```

## RESULT:
The given string is reversed and printed on the screen.

<div style="page-break-after: always"></div>

## AIM:
To implement a function that compares two strings ignoring case sensitivity and returns 1 if the strings are equal.

## ALGORITHM:
1. Define a function `string_compare(char *string1, char *string2)` that takes in two strings as input also initialize a variable i to 0.
2. Using a `while` loop, iterate through the characters of the two strings and compare them using the `tolower()` function.
3. If the characters at the `i`th position in both strings are equal, increment `i` and continue the loop.
4. If the characters at the `i`th position in either string is a null character, break the loop.
5. If the strings are equal, return 0. If the first string is shorter than the second string, return -1. Otherwise, return 1.
6. In the `main()` function, prompt the user to enter two strings and store them in variables `string1` and `string2`.
7. Call the `string_compare()` function with `string1` and `string2` as arguments and store the result in a variable `result`.
8. Based on the value of `result`, print the appropriate message indicating the comparison result.

## CODE:
```c
#include <stdio.h>
#include <ctype.h>

int string_compare(char *string1, char *string2) {
    int i = 0;
    while (tolower(string1[i]) == tolower(string2[i])) {
        if (string1[i] == '\0' || string2[i] == '\0') {
            break;  // If any one of the string ends, break the loop
        }
        i++;
    }
    if (string1[i] == '\0' && string2[i] == '\0') {
        return 0;   // if both strings are equal then return 0
    } else if (string1[i] == '\0' && string2[i] != '\0') {
        return -1;  // if string1 is less than string2 then return -1
    } else {
        return 1;   // if string1 is greater than string2 then return 1
    }
}

int main() {
    char string1[100];
    char string2[100];
    printf("Enter the first string: ");
    scanf("%s", string1);
    printf("Enter the second string: ");
    scanf("%s", string2);
    int result = string_compare(string1, string2);
    if (result == 0) {
        printf("The strings are equal");
    } else if (result == -1) {
        printf("The second string is greater tha the first string");
    } else {
        printf("The first string is greater than the second string");
    }

}
```
## OUTPUT:
```
aditya@LAPTOP:~$ gcc string_compare.c -o string_compare
aditya@LAPTOP:~$ ./string_compare
Enter the first string: aditya
Enter the second string: ADITYA
The strings are equal
```

## RESULT:
The function `string_compare()` will compare the two input strings ignoring case sensitivity and return 1 if they are equal, 0 if the first string is shorter than the second string, and -1 if the second string is shorter than the first string.


<div style="page-break-after: always"></div>

## AIM:
To remove all the vowels from a given string using an array.
## ALGORITHM:
1. Create a function called `string_length` that takes a string as input and returns the length of the string.
2. Create a function called `remove_vowels` that takes a string as input and removes all the vowels from the string. 
3. Initialize an array of vowels and iterate through the string. For each character in the string, check if it is a vowel by comparing it to each element in the array of vowels. If it is a vowel, remove it from the string by shifting all the subsequent characters in the string one position to the left.
4. In the main function, get a string from the user and call the `remove_vowels` function with the string as input. Print the resulting string.
## CODE:
```c
#include <stdio.h>

int string_length(const char *string) {
    int string_length = 0;
    for (int i=0; string[i] != '\0'; i++) {
        string_length++;
    }
    return string_length;
}

void remove_vowels(char *string) {
    int length = string_length(string);
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i=0; i<length; i++) {
        for (int j=0; j<10; j++) {
            if (string[i] == vowels[j]) {
                for (int k=i; k<length; k++) {
                    string[k] = string[k+1];
                }
                i--;
                break;
            }
        }
    }
}

int main() {
    char string[100];
    printf("Enter a string: ");
    scanf(" %[^\n]s", string);
    remove_vowels(string);
    printf("The string after removing vowels is: %s", string);
}
```
## OUTPUT:
```
aditya@LAPTOP:~$ gcc remove_vowels.c -o remove_vowels
aditya@LAPTOP:~$ ./remove_vowels
Enter a string: aditya
The string after removing vowels is: dty
```

## RESULT:
The program will remove all the vowels from the given string and print the resulting string to the screen.

