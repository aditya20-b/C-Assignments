/*
Write a c program to to display the corresponding ascii characters for the given string
*/

#include <stdio.h>


int main() {
    char string_input[100];
    printf("Enter the string: ");
    scanf(" %[^\n]s", string_input);
    printf("The ascii characters are: ");
    for (int i=0; string_input[i] != '\0'; i++) {
        printf("\nThe ascii value of character %c in the string is: %d", string_input[i], string_input[i]);
    }
    printf("\n");
}
