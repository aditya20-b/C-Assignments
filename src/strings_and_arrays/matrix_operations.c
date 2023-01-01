/*
Write a program to get two matrixes from the user and apply matrix addition
and matrix multiplication on them
*/

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
