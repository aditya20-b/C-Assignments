/*
Get a given string input from the user and a substring that you need to find inside the given string input. 
In the end print If the given substring is present in the main string and if the substring is present,
find the number of occurrences the substring has  
*/


#include <stdio.h>

int string_length(char string[]) {
    int string_length = 0;
    for (int i=0; string[i] != '\0'; i++) {
        string_length++;
    }
    return string_length;
}

int substring_counter(char string[], char substring[]) {
    int substring_counter = 0;
    int length = string_length(string);
    int substring_length = string_length(substring);
    for (int i=0; i<length; i++) {
        if (string[i] == substring[0]) {
            for (int j=0; j<substring_length; j++) {
                if (string[i+j] == substring[j]) {
                    if (j == substring_length-1) {
                        substring_counter++;
                    }
                }
                else {
                    break;
                }
            }
        }
    }
    return substring_counter;
}

int main() {
    char string[100], substring[100];
    printf("Enter the string: ");
    scanf("%[^\n]d", string);
    printf("Enter the substring: ");
    scanf("%s", substring);
    int substrings = substring_counter(string, substring);
    if (substrings == 0) {
        printf("The substring is not present in the string");
    }
    else {
        printf("The substring is present in the string %d times", substrings);
    }
    return 0;
}