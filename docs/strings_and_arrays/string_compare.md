## AIM
To implement a function that compares two strings ignoring case sensitivity and returns 1 if the strings are equal.

## ALGORITHM
1. Define a function `string_compare(char *string1, char *string2)` that takes in two strings as input also initialize a variable i to 0.
2. Using a `while` loop, iterate through the characters of the two strings and compare them using the `tolower()` function.
3. If the characters at the `i`th position in both strings are equal, increment `i` and continue the loop.
4. If the characters at the `i`th position in either string is a null character, break the loop.
5. If the strings are equal, return 0. If the first string is shorter than the second string, return -1. Otherwise, return 1.
6. In the `main()` function, prompt the user to enter two strings and store them in variables `string1` and `string2`.
7. Call the `string_compare()` function with `string1` and `string2` as arguments and store the result in a variable `result`.
8. Based on the value of `result`, print the appropriate message indicating the comparison result.

## CODE
```c
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
```
## OUTPUT
```
aditya@LAPTOP:~$ gcc string_compare.c -o string_compare
aditya@LAPTOP:~$ ./string_compare
Enter the first string: aditya
Enter the second string: ADITYA
The strings are equal
```

## RESULT
The function `string_compare()` will compare the two input strings ignoring case sensitivity and return 1 if they are equal, 0 if the first string is shorter than the second string, and -1 if the second string is shorter than the first string.