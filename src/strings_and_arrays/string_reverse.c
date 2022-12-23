/*
Write a program to reverse a string without using the library function. No
extra string should be used and the source string itself should be modified to
store the reversed string. Number of exchanges should be minimum.
*/

#include <stdio.h>

int string_reverse(char *string_input) {
    int string_length = 0;
    for (int i=0; string_input[i] != '\0'; i++) {
        string_length++;
    }
    for (int i=0; i<string_length/2; i++) {
        char temp = string_input[i];
        string_input[i] = string_input[string_length-i-1];
        string_input[string_length-i-1] = temp;
    }
    return 0;
}

int main() {
    char string_input[100];
    printf("Enter the string: ");
    scanf(" %[^\n]s", string_input);
    string_reverse(string_input);
    printf("The reversed string is: %s", string_input);
}
