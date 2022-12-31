## AIM
To get two matrixes as input from the user and perform matrix addition and matrix multiplication on them

## ALGORITHM
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

## CODE
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
        printf("Multiplication not implemented yet");
    }
    else {
        printf("Invalid choice");
    }
}
```
## OUTPUT
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

## RESULT
The user will be able to get two matrixes as input and perform matrix addition and matrix multiplication on them. The result of the operation will be printed to the screen.