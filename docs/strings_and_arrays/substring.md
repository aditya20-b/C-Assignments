## AIM:
To find if a given substring is present in a given string and if it is present, to find the number of occurrences of the substring in the string.

## ALGORITHM
1. Initialize two variables: `string_length` to store the length of the given string and `substring_counter` to store the number of occurrences of the substring in the string. Initialize `length` to the length of the given string and `substring_length` to the length of the given substring.
2. Use a loop to iterate through the characters of the given string.
3. If the current character of the string is equal to the first character of the substring, use another loop to check if the characters following the current character in the string match the characters of the substring.
4. If all the characters match, increment the `substring_counter` by 1 and continue the loop. If the characters do not match, break the loop and continue with the outer loop.
5. After the loops, check if the `substring_counter` is equal to 0. If it is, print that the substring is not present in the string. If it is not equal to 0, print that the substring is present in the string and the number of occurrences.

## CODE
```c
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
```

## OUTPUT
```
aditya@LAPTOP:~$ gcc substring.c -o substring
aditya@LAPTOP:~$ ./substring
Enter the string: HelloThere
Enter the substring: llo
The substring is present in the string 1 times
```

## RESULT
The program will find if a given substring is present in a given string and if it is present, the number of occurrences of the substring in the string.