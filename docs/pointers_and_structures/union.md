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