/*
Generate the salary slip of a single employee using structure and functions. 
Use separate functions for getting input, computing and displaying output. 
Pass the structure by reference. Display the pay slip with proper formatting.
Use pointer notation. (Hint: Take the required data from Ex. 1)
*/

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

int getInput(struct salary *s1) {
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
    return 0;
}

int compute(struct salary *s1) {
    s1->gross = s1->basic + s1->da + s1->hra;   // Gross Salary is the sum of Basic salary dearness allowance and house rent allowance
    s1->net = s1->gross - s1->pf;      // Net Salary is the gross salary minus the provident fund
    return 0;
}

int display(struct salary *s1) {
    printf("The salary slip of %s is as follows: ", s1->name);
    printf("\n--------------------------------------------");
    printf("\n Name: %s", s1->name);
    printf("\n ID: %d", s1->id);
    printf("\n---------------------------------");
    printf("\n| Basic: %d | DA: %d | HRA: %d |", s1->basic, s1->da, s1->hra);
    printf("\n---------------------------------");
    printf("\n| Gross: %d | PF: %d | Net: %d |", s1->gross, s1->pf, s1->net);
    printf("\n---------------------------------");
    return 0;
}

int main() {
    struct salary s1;
    getInput(&s1);
    compute(&s1);
    display(&s1);
    return 0;

}