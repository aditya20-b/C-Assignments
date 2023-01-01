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