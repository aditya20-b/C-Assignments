/*
Write a C program to find the transpose of a given matrix. Dynamically create a 2-D array of type double. 
The dimension of the array should be read from the user. The data should be also read from the user.
The 2-D array for storing the transpose matrix should be dynamically created. Write a function swap()
that takes two arguments to perform the transpose operation by using pass by reference.
The individual elements of the transposed matrix should be cubed and stored. Print the final result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void transpose_operation(double *matrix_ptr[], double *transpose_ptr[], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose_ptr[j][i] = matrix_ptr[i][j];
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the dimension of the matrix: ");   
    scanf("%d %d", &rows, &cols);
    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
    }
    double **transpose = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        transpose[i] = (double *)malloc(cols * sizeof(double));
    }
    double **transpose_cube = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        transpose_cube[i] = (double *)malloc(cols * sizeof(double));
    }
    printf("Enter the elements of the matrix:\n ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
    double *matrix_ptr[rows];
    double *transpose_ptr[rows];
    for (int i = 0; i < rows; i++) {
        matrix_ptr[i] = matrix[i];
    }
    for (int i = 0; i < rows; i++) {
        transpose_ptr[i] = transpose[i];
    }
    transpose_operation(matrix_ptr, transpose_ptr, rows, cols);
    printf("Transposed matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%0.2lf ", transpose[i][j]);
        }
        printf("\n");
    }
    printf("Transposed matrix cubed: \n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            transpose_cube[i][j] = transpose[i][j] * transpose[i][j] * transpose[i][j];
            printf("%0.2lf ", transpose_cube[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < rows; i++) {
        free(transpose[i]);
    }
    free(transpose);
    for (int i = 0; i < rows; i++) {
        free(transpose_cube[i]);
    }
    free(transpose_cube);
    return 0;
}
