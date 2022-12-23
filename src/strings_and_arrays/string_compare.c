/*
Implement strcmpi(str1, str2) function without using the strings library (the
function compares str1 and str2 ignoring case sensitivity and returns 1 if the
strings are equal)
*/


// strcmp(str1, str2) 
// Compares string 1 and 2 and returns

// 0 if they are equal
// < 0 if str1 is less than str2
// > 0 if str1 is greater than str2

// strcmp(str1, str2)

#include <stdio.h>
#include <ctype.h>

int string_compare(char *string1, char *string2) {
    int i = 0;
    while (tolower(string1[i]) == tolower(string2[i])) {
        if (string1[i] == '\0' || string2[i] == '\0') {
            break;  // If any one of the string ends, break the loop
        }
        i++;
    }
    if (string1[i] == '\0' && string2[i] == '\0') {
        return 0;   // if both strings are equal then return 0
    } else if (string1[i] == '\0' && string2[i] != '\0') {
        return -1;  // if string1 is less than string2 then return -1
    } else {
        return 1;   // if string1 is greater than string2 then return 1
    }
}

int main() {
    char string1[100];
    char string2[100];
    printf("Enter the first string: ");
    scanf("%s", string1);
    printf("Enter the second string: ");
    scanf("%s", string2);
    int result = string_compare(string1, string2);
    if (result == 0) {
        printf("The strings are equal");
    } else if (result == -1) {
        printf("The second string is greater tha the first string");
    } else {
        printf("The first string is greater than the second string");
    }

}
