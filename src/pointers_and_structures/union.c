/*
Write a program to create an array of numbers.
The numbers may be of any format (number name, whole number, floating point number, etc.). 
For this, create a union named 'Number' with fields char[] number, int num, float fnum, double dnum. 
Each number may be stored and retrieved in any of the above formats depending on the choice of the us
*/

#include <stdio.h>

union Number {
    char number[100];
    int num;
    float fnum;
    double dnum;
};


int main() {
    int size;
    printf("Enter the size of  the array: ");
    scanf("%d", &size);
    union Number numbers[size];
    printf("Enter %d numbers: ", size);
    for (int i=0; i<size; i++) {
        scanf("%s", numbers[i].number);
    }
    printf("The numbers are: ");
    for (int i=0; i<size; i++) {
        printf("%s ", numbers[i].number);
    }
    return 0;
}