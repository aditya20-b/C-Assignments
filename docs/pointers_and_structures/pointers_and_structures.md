# POINTERS AND STRUCTURES

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
<div style="page-break-after: always"></div>

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

<div style="page-break-after: always"></div>

## AIM:
To create an array of numbers in various formats and store them in a union named 'Number' with fields char[] number, int num, float fnum, double dnum.

## ALGORITHM:

1. Declare variables `size`, `choice`, `number_counter`, `num_counter`, `fnum_counter`, and `dnum_counter` to store the size of the array, the type of number entered by the user, and the counters for the number of numbers entered in each format.
2. Get the size of the array from the user and create an array of type `Number` with the given size.
3. Read `size` number of numbers from the user.
4. For each number, ask the user to choose the type of number they want to enter.
5. Based on the user's choice, read the number and store it in the corresponding field of the union.
6. Increment the counter for the corresponding field of the union.
7. Repeat steps 4-6 until all the numbers have been entered.
8. Print the numbers entered in each format by iterating through the array and printing the values stored in the corresponding fields of the union.

## CODE:
```c
#include <stdio.h>
#include <stdlib.h>
union Number {
    char number[100];
    int num;
    float fnum;
    double dnum;
};


int main() {
    int size,choice;
    int number_counter = 0, num_counter = 0, fnum_counter = 0, dnum_counter = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    union Number numbers[size];
    printf("Enter %d numbers: \n", size);
    for (int i=0; i<size; i++) {
        printf("Enter the type of number you want to store:\n");
        printf("1. String\n2. Integer\n3. Float\n4. Double\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the number: ");
                scanf("%s",numbers[i].number);
                number_counter++;
                break;
            case 2:
                printf("Enter the number: ");
                scanf("%d",&numbers[i].num);
                num_counter++;
                break;
            case 3:
                printf("Enter the number: ");
                scanf("%f",&numbers[i].fnum);
                fnum_counter++;
                break;
            case 4:
                printf("Enter the number: ");
                scanf("%lf",&numbers[i].dnum);
                dnum_counter++;
                break;
            default:
                printf("Invalid choice");
                break;
        }
    }
    printf("The numbers are:\n");
    if (number_counter > 0) {
        printf("The string numbers are: ");
        for (int i = 0; i < number_counter; i++) {
            printf("%s\n ", numbers[i].number);
        }
    }
    if (num_counter > 0) {
        printf("The integer numbers are: ");
        for (int i = number_counter; i < number_counter+num_counter; i++) {
            printf("\n%d ", numbers[i].num);
        }
    }
    if (fnum_counter > 0) {
        printf("The float numbers are: ");
        for (int i = num_counter+number_counter; i < num_counter+number_counter+fnum_counter; i++) {
            printf("\n%f ", numbers[i].fnum);
        }
    }
    if (dnum_counter > 0) {
        printf("The double numbers are: ");
        for (int i = num_counter+number_counter+fnum_counter; i < num_counter+number_counter+fnum_counter+dnum_counter; i++) {
            printf("\n%lf ", numbers[i].dnum);
        }
    }
    return 0;
}
```
<div style="page-break-after: always"></div>

## OUTPUT:
```
aditya@LAPTOP:~$ gcc union.c -o union
aditya@LAPTOP:~$ ./union
Enter the size of the array: 2
Enter 2 numbers:
Enter the type of number you want to store:
1. String
2. Integer
3. Float
4. Double
Enter your choice: 1
Enter the number: one
Enter the type of number you want to store:
1. String
2. Integer
3. Float
4. Double
Enter your choice: 2
Enter the number: 2
The numbers are: 
The string numbers are: one
The integer numbers are: 2
```

## RESULT:
An array of numbers in various formats will be created and stored in a union. The numbers will be printed in the corresponding formats.

<div style="page-break-after: always"></div>


## AIM:
The aim of this code is to concatenate the first half of one string with the second half of another string, and store the result in a new dynamically allocated string.

## ALGORITHM:
1. Read the lengths of two strings from the user and allocate dynamic memory for each string.
2. Read the two strings from the user.
3. Calculate the length of the new string using the given formula: length3 = (length1 / 2) + (length2 / 2).
4. If either of the lengths is odd, add 1 to the length of the new string.
5. Allocate dynamic memory for the new string.
6. Iterate through the new string and fill it with the appropriate characters from the two input strings.

## CODE:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int estimateLength(int length1, int length2) {
    return (length1 / 2) + length2 - (length2 / 2);
}
int main() {
    char *string1, *string2, *string3;
    int length1, length2, length3, first_half, second_half;
    printf("Enter the length of string 1: ");
    scanf("%d", &length1);
    string1 = (char *)malloc(length1 * sizeof(char));
    printf("Enter the length of string 2: ");
    scanf("%d", &length2);
    string2 = (char *)malloc(length2 * sizeof(char));
    printf("Enter string 1: ");
    scanf("%s", string1);
    printf("Enter string 2: ");
    scanf("%s", string2);
    length1 = strlen(string1);
    length2 = strlen(string2);
    length3 = estimateLength(length1, length2);
    string3 = (char *)malloc((length3 + 1) * sizeof(char));  
    for (int i=0; i<length3; i++) {
        if (i < length1 / 2) {
            string3[i] = string1[i];
        } else {
            string3[i] = string2[i];
        }
    }
    printf("String 3 is: %s", string3);
}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc string_concatination.c -o string_concatination
aditya@LAPTOP:~$ ./string_concatination
Enter the length of string 1: 5
Enter the length of string 2: 4
Enter string 1: hello
Enter string 2: world
String 3 is: herld
```

## RESULT:
The result of this code will be a new string that is a concatenation of the first half of one string with the second half of the other string. The size of the new string will be sufficient to hold the relevant parts of the input strings.

<div style="page-break-after: always"></div>


## AIM:
The aim of this code is to manage data related to waiters, items, and bills in a restaurant. It allows the user to add new waiters, items, and bills, and also provides functionality to print the list of waiters, items, and bills, and a summary of sales made by each waiter for each item.

## ALGORITHM:
1. Initialize structs for waiters, items, and bills, and corresponding sizes for each struct.
2. Implement functions to add new waiters, items, and bills, and update the corresponding sizes.
3. Implement functions to print the list of waiters, items, and bills.
4. Implement a function to print the summary of sales made by each waiter for each item. This function will iterate through the bills array and update a summary array with the sales made by each waiter for each item. It will then print the summary array along with the names of the waiters and items.

## CODE:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define WAITERS 5
#define ITEMS 5



struct waiter {
    int id;
    char name[100];
};

struct Bill {
    int waiter_id;
    int item_id;
    float cost;
};

struct Item {
    int id;
    char name[100];
    float price;
};

void addWaiter(struct waiter *waiters, int *size) {
    printf("Enter the name of the waiter: ");
    scanf("%s", waiters[*size].name);
    waiters[*size].id = *size + 1;
    *size += 1;
    printf("Waiter added successfully\n\n");
}

void addItem(struct Item *items, int *size) {
    printf("Enter the name of the item: ");
    scanf("%s", items[*size].name);
    items[*size].id = *size + 1;
    *size += 1;
    printf("Item added successfully\n\n");
}

void addBill(struct Bill *bills, int *size) {
    printf("Enter the waiter id: ");
    scanf("%d", &bills[*size].waiter_id);
    printf("Enter the item id: ");
    scanf("%d", &bills[*size].item_id);
    printf("Enter the cost of the item: ");
    scanf("%f", &bills[*size].cost);
    *size += 1;
    printf("Bill added successfully\n\n");
}

void printWaiters(struct waiter *waiters, int size) {
    printf("The waiters are:\n");
    for (int i=0; i<size; i++) {
        printf("%d. %s\n", i+1, waiters[i].name);
    }
    printf("\n\n");
}

void printItems(struct Item *items, int size) {
    printf("The items are:\n");
    for (int i=0; i<size; i++) {
        printf("%d. %s - %frs\n", i+1, items[i].name, items[i].price);
    }
    printf("\n\n");
}

void printBills(struct Bill *bills, int size) {
    printf("The bills are:\n");
    for (int i=0; i<size; i++) {
        printf("The waiter id is: %d\n", bills[i].waiter_id);
        printf("The item id is: %d\n", bills[i].item_id);
        printf("The cost of the item is: %0.2f\n", bills[i].cost);
        printf("\n");
    }
    printf("\n");
}

void line() {
    printf("\n------------------------------------------------------------------\n"); 
    
}

void printSummary(struct Bill *bills, int size, struct waiter *waiters, int waiter_size, struct Item *items, int item_size) {
    float summary[item_size][waiter_size];
    line();
    for (int i=0; i<item_size; i++) {
        for (int j=0; j<waiter_size; j++) {
            summary[i][j] = 0;
        }
    }
    
    for (int i=0; i<size; i++) {
        summary[bills[i].item_id-1][bills[i].waiter_id-1] += bills[i].cost;
    }
    
    printf("\tWaiter\t");
    for (int i=0; i<waiter_size; i++) {
        printf("\t%s\t", waiters[i].name);
    }
    line();
    
    for (int i=0; i<item_size; i++) {
        printf("\t%s\t", items[i].name);
        float total = 0;
        for (int j=0; j<waiter_size; j++) {
            printf("\t%0.2f\t", summary[i][j]);
            total += summary[i][j];
        }
        printf("\t%0.2f\n", total);
    }
    printf("\tTotal\t");
    for (int i=0; i<waiter_size; i++) {
        float total = 0;
        for (int j=0; j<item_size; j++) {
            total += summary[j][i];
        }
        printf("\t%0.2f\t", total);
    }
    printf("\n");
}


int main() {
    struct waiter waiters[WAITERS];
    int waiter_size = 0;
    struct Item items[ITEMS];
    int item_size = 0;
    struct Bill bills[100];
    int bill_size = 0;
    int choice;
    while (true) {
        printf("1. Add a waiter\n");
        printf("2. Add an item\n");
        printf("3. Add a bill\n");
        printf("4. Display waiters\n");
        printf("5. Display items\n");
        printf("6. Display bills\n");
        printf("7. Display summary\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addWaiter(waiters, &waiter_size);
                break;
            case 2:
                addItem(items, &item_size);
                break;
            case 3:
                addBill(bills, &bill_size);
                break;
            case 4:
                printWaiters(waiters, waiter_size);
                break;
            case 5:
                printItems(items, item_size);
                break;
            case 6:
                printBills(bills, bill_size);
                break;
            case 7:
                printSummary(bills, bill_size, waiters, waiter_size, items, item_size);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
```

<div style="page-break-after: always"></div>

## OUTPUT:
```
aditya@LAPTOP:~$ gcc -o restaurant_bill restaurant_bill.c
aditya@LAPTOP:~$ ./restaurant_bill
1. Add a waiter
2. Add an item
3. Add a bill
4. Display waiters
5. Display items
6. Display bills
7. Display summary
8. Exit
Enter your choice: 1
Enter the name of the waiter: aditya
Enter your choice: 1
Enter the name of the waiter: vishal
Waiter added successfully
Enter your choice: 2
Enter the name of the item: pizza
Item added successfully
Enter your choice: 2
Enter the name of the item: burger
Item added successfully
Enter your choice: 3
Enter the waiter id: 1
Enter the item id: 1
Enter the cost of the item: 100
Bill added successfully
Enter your choice: 3
Enter the waiter id: 1
Enter the item id: 2
Enter the cost of the item: 50
Bill added successfully
Enter your choice: 3
Enter the waiter id: 2
Enter the item id: 1
Enter the cost of the item: 200
Bill added successfully
Enter your choice: 7
------------------------------------------------------------------
        Waiter           aditya           vishal        
------------------------------------------------------------------
        pizza           100.00           200.00           300.00
        burger          50.00            0.00            50.00
        Total           150.00           200.00           350.00
```
## RESULT:
Hence, a restaurant bill management system is designed.

<div style="page-break-after: always"></div>


## AIM:
To generate the salary slip of an employee using a structure and functions.

## ALGORITHM:
1. Declare a structure `salary` with the following members: name, id, basic salary, dearness allowance, house rent allowance, provident fund, gross salary, net salary.
2. Define the `getInput()` function to get the input from the user. This function takes a pointer to the salary structure as an argument.
3. Define the `compute()` function to calculate the gross salary and net salary. This function also takes a pointer to the salary structure as an argument.
4. Define the `display()` function to display the salary slip. This function also takes a pointer to the salary structure as an argument.
5. In the main function, create an object of the salary structure and call the `getInput()` function to get the input from the user.
6. Call the `compute()` function to calculate the gross salary and net salary.
7. Call the `display()` function to display the salary slip.

## CODE:
```c
#include <stdio.h>
#include <string.h>

struct salary {
    char name[100]; // Employee name
    int id;     // Employee ID
    int basic;  // Basic Salary
    int da;     // Dearness Allowance
    int hra;    // House Rent Allowance
    int pf;     // Provident Fund
    int gross;  // Gross Salary
    int net;    // Net Salary
};
void getInput(struct salary *s1) {
    printf("Enter the name of the employee: ");
    scanf("%s", s1->name);
    printf("Enter the ID of the employee: ");
    scanf("%d", &s1->id);
    printf("Enter the basic salary of the employee: ");
    scanf("%d", &s1->basic);
    printf("Enter the DA of the employee: ");
    scanf("%d", &s1->da);
    printf("Enter the HRA of the employee: ");
    scanf("%d", &s1->hra);
    printf("Enter the PF of the employee: ");
    scanf("%d", &s1->pf);
}
void compute(struct salary *s1) {
    s1->gross = s1->basic + s1->da + s1->hra;   // Gross Salary is the sum of Basic salary dearness allowance and house rent allowance
    s1->net = s1->gross - s1->pf;      // Net Salary is the gross salary minus the provident fund
}
void display(struct salary *s1) {
    printf("The salary slip of %s is as follows: ", s1->name);
    printf("\n--------------------------------------------");
    printf("\n Name: %s", s1->name);
    printf("\n ID: %d", s1->id);
    printf("\n---------------------------------");
    printf("\n| Basic: %d | DA: %d | HRA: %d |", s1->basic, s1->da, s1->hra);
    printf("\n---------------------------------");
    printf("\n| Gross: %d | PF: %d | Net: %d |", s1->gross, s1->pf, s1->net);
    printf("\n---------------------------------");
}

int main() {
    struct salary s1;
    getInput(&s1);
    compute(&s1);
    display(&s1);
    return 0;
}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc salary_slip.c -o salary_slip
aditya@LAPTOP:~$ ./salary_slip
Enter the name of the employee: Aditya
Enter the ID of the employee: 1
Enter the basic salary of the employee: 10000
Enter the DA of the employee: 1000
Enter the HRA of the employee: 500
Enter the PF of the employee: 500
The salary slip of Aditya is as follows:
--------------------------------------
 Name: Aditya
 ID: 1
-------------------------------------
| Basic: 10000 | DA: 1000 | HRA: 500 |
-------------------------------------
| Gross: 11500 | PF: 500 | Net: 11000 |
-------------------------------------

```

## RESULT:
The salary slip of the employee is generated and displayed on the screen with the required formatting.

<div style="page-break-after: always"></div>


## AIM:
The aim of this code is to create a program that can store and manipulate data about students, including their name, roll number, marks in various subjects, total marks, rank, date of birth, age, and gender.

## ALGORITHM:
1. Define a struct and an enum to store data about a student.
2. Define a function `totalMarks` to calculate the total marks of a student.
3. Define a function `getData` to input data about multiple students.
4. Define a function `printData` to print data about multiple students.
5. In the `main` function, ask the user for the number of students and call the `getData` and `printData` functions to input and display the data about the students.

## CODE:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUBJECTS 5

typedef struct date {
    int day;
    int month;
    int year;
} date;

typedef enum gender {
    MALE, FEMALE, TRANSGENDER
} gender;

typedef struct student {
    int rollnum;
    char name[100];
    int marks[SUBJECTS];
    int totalMarks;
    int rank;
    date dateofbirth;
    int age;
    gender genderOfStudent;
} student;

int totalMarks(student *s) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum = sum + s->marks[i];
    }
    return sum;
}


void getData(student *s, int n) {
    int input;
    for (int i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", s[i].name);
        printf("Enter the roll number of the student: ");
        scanf("%d", &s[i].rollnum);
        printf("\nEnter the marks of %s: ", s[i].name);
        for (int j = 0; j < 5; j++) {
            printf("\nEnter the marks of subject %d: ", j+1);
            scanf("%d", &s[i].marks[j]);
        }
        s[i].totalMarks = totalMarks(&s[i]);
        printf("Enter the date of birth of the student  (dd mm yyyy) : ");
        scanf("%d %d %d", &s[i].dateofbirth.day, &s[i].dateofbirth.month, &s[i].dateofbirth.year);
        printf("Enter the age of the student: ");
        scanf("%d", &s[i].age);
        printf("Enter the gender: \n1. MALE\n2. FEMALE\n3. TRANSGENDER\n");
        scanf("%d", &input);
        /*
        if (input == 1 ) {
            s[i].genderOfStudent = MALE
        }
        else if (input == 2) {
            s[i].genderOfStudent = FEMALE
        }
        else if (input == 3) {
            s[i].genderOfStudent
        
        */
        s[i].genderOfStudent = (input == 1) ? MALE : (input == 2) ? FEMALE : TRANSGENDER;

    }
}

void printData(student *s, int n) {
    for (int i = 0; i < n; i++) {
        char gender[100];
        printf("The details of student %d are: ", i+1);
        printf("\nName: %s", s[i].name);
        switch (s[i].genderOfStudent) {
            case MALE:
                snprintf(gender, sizeof(gender), "\nGender: MALE");
                break;
            case FEMALE:
                snprintf(gender, sizeof(gender), "\nGender: FEMALE");
                break;
            case TRANSGENDER:
                snprintf(gender, sizeof(gender), "\nGender: TRANSGENDER");
                break;
        };
        
        printf(gender);
        printf("\nRoll number: %d", s[i].rollnum);
        printf("\nMarks: ");
        for (int j = 0; j < 5; j++) {
            printf("\n\tSubject %d: %d", j+1, s[i].marks[j]);
        }
        printf("\nTotal marks: %d", s[i].totalMarks);
        printf("\nRank: %d", s[i].rank+1);
        printf("\nDate of birth: %d/%d/%d", s[i].dateofbirth.day, s[i].dateofbirth.month, s[i].dateofbirth.year);
        printf("\nAge: %d", s[i].age);
        printf("\n\n\n");       
    }
}


void computeRank(student *students, int n) {
    // sort students in descending order of total marks
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].totalMarks < students[j + 1].totalMarks) {
                student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            };
        };
    };

    // assign ranks to students
    for (int i=0; i<n; i++) {
        students[i].rank = i;        
    };
    
    // if total marks of two students are same, assign the same rank to both of them
    for (int i=0; i<n; i++) {
        if (students[i].totalMarks == students[i+1].totalMarks) {
            students[i+1].rank = students[i].rank;
        };
    };

}


int main() {
    int n;
    printf("\nEnter the number of students: ");
    scanf("%d", &n);
    student s[n];
    getData(s, n);
    computeRank(s, n);
    printData(s, n);
    return 0;   
}
```
## OUTPUT:
```
aditya@LAPTOP:~$ gcc -o marksheet marksheet.c
aditya@LAPTOP:~$ ./marksheet
Enter the number of students: 2
Enter the name of student 1: Aditya
Enter the roll number of the student: 1

Enter the marks of Aditya:
Enter the marks of subject 1: 90
Enter the marks of subject 2: 80
Enter the marks of subject 3: 70
Enter the marks of subject 4: 80
Enter the marks of subject 5: 90
Enter the date of birth of the student  (dd mm yyyy) : 21 10 2004
Enter the age of the student: 18
Enter the gender: 
1. MALE
2. FEMALE
3. TRANSGENDER
1
Enter the name of student 2: Vishal
Enter the roll number of the student: 2

Enter the marks of Vishal:
Enter the marks of subject 1: 80
Enter the marks of subject 2: 90
Enter the marks of subject 3: 90
Enter the marks of subject 4: 70
Enter the marks of subject 5: 70

Enter the date of birth of the student  (dd mm yyyy) : 01 01 2000
Enter the age of the student: 23
Enter the gender: 
1. MALE
2. FEMALE
3. TRANSGENDER
1
The details of student 1 are: 
Name: Aditya
Gender: MALE
Roll number: 1
Marks:
        Subject 1: 90
        Subject 2: 80
        Subject 3: 70
        Subject 4: 80
        Subject 5: 90
Total marks: 410
Rank: 1
Date of birth: 21/10/2004
Age: 18


The details of student 2 are:
Name: Vishal
Gender: MALE
Roll number: 2
Marks:
        Subject 1: 80
        Subject 2: 90
        Subject 3: 90
        Subject 4: 70
        Subject 5: 70
Total marks: 400
Rank: 2
Date of birth: 1/1/2000
Age: 23

```

## RESULT:
The program will get data for n students, compute and display their ranks, and print the mark sheet of a particular student with all their details.
