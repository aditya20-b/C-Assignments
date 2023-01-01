## AIM:
The aim of this code is to transpose a matrix and then cube the transposed matrix.

## ALGORITHM:
1. Read the dimensions of the matrix from the user and allocate dynamic memory for the matrix and two transpose matrices.
2. Read the elements of the matrix from the user.
3. Create pointers to the rows of the matrix and the two transpose matrices.
4. Call a function to transpose the matrix using the pointers.
5. Iterate through the transpose matrix and cube each element.
6. Print the transposed matrix and the cubed transposed matrix.
7. Free the dynamically allocated memory for the matrix and the two transpose matrices.

## CODE:
```c
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
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc transpose_matrix_cube.c -o transpose_matrix_cube
aditya@LAPTOP:~$ ./transpose_matrix_cube
Enter the dimension of the matrix: 2 2
Enter the elements of the matrix:
    matrix[0][0]: 1
    matrix[0][1]: 2
    matrix[1][0]: 3
    matrix[1][1]: 4
Transposed matrix:
1.00 3.00
2.00 4.00
Transposed matrix cubed:
1.00 27.00
8.00 64.00
```
## RESULT:
The result of this code will be the original matrix, the transposed matrix, and the cubed transposed matrix, printed in the format specified in the code. The dynamically allocated memory for the matrices will also be freed.
