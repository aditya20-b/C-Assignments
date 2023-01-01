/*
Write a program to create an array of numbers.
The numbers may be of any format (number name, whole number, floating point number, etc.). 
For this, create a union named 'Number' with fields char[] number, int num, float fnum, double dnum. 
Each number may be stored and retrieved in any of the above formats depending on the choice of the us
*/

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
    printf("Enter the size of  the array: ");
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
        printf("The integer numbers are:");
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