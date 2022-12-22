/*
Check if the input string is a palindrome
*/

#include <stdio.h>

int main() {
    char str[100];
    int i, length;
    int flag = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    // Find the length of the string
    length = 0;
    while (str[length] != '\0')
        length++;

    // Check if the string is a palindrome
    for (i = 0; i < length; i++) {
        if (str[i] != str[length - i - 1]) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("%s is not a palindrome", str);
    } else {
        printf("%s is a palindrome", str);
    }
    return 0;
}

/*
================================================================
This can be alternatively implemented using string functions like this: 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(const char *string) {
    /// Reverse the string
    char reversed_string[strlen(string) + 1];
    strcpy(reversed_string, string);
    strrev(reversed_string);

    /// Check if the string is a palindrome
    return strcmp(string, reversed_string) == 0;
}

*/