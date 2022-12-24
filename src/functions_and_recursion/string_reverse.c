/*
Write a function that reverses a string using recursion.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int string_length(const char *string) {
    int string_length = 0;
    for (int i=0; string[i] != '\0'; i++) {
        string_length++;
    }
    return string_length;
}

int string_reverse(const char *string, char *reversed_string, int string_length, int reversed_string_index, bool print_string) {
    if (string_length == 0) {
        return 0;
    } else {
        if (print_string) {
            printf("%c", string[string_length-1]);
        }
        reversed_string[reversed_string_index] = string[string_length-1];
        return string_reverse(string, reversed_string, string_length-1, reversed_string_index+1, print_string);
    }
}

int main() {
    char string[100];
    char reversed_string[100];
    printf("Enter a string: ");
    scanf(" %[^\n]s", string);
    int length = string_length(string);
    string_reverse(string, reversed_string, length, 0, false);
    printf("The reversed string is: %s", reversed_string);
    return 0;
}
