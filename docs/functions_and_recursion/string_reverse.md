## AIM:
To write a function that reverses a string using recursion.

## ALGORITHM:

1. Define a function called `string_length` that takes in a string as an argument. Initialize a variable called `length` to 0.
2. Iterate over the string with a for loop. For each iteration, increment the `length` by 1 and return the `length` when the loop ends.
3. Define a function called `string_reverse` that takes in a string, a reversed string, a string length, a reversed string index, and a boolean as arguments.
4. If the `length` is equal to 0, return 0, if the boolean is true, print the string at the index length-1.
5. Assign the value of the string at the index `length-1` to the reversed string at the index `reversed_string_index`.
6. Call `string_reverse` again with the string, reversed string, string_length-1, reversed_string_index+1, and the boolean as arguments.
7. In main, define a string called string and another called reversed_string and then get the string from the user.
8. Get the length of the string using the string_length function.
9. Call the `string_reverse` function with the string, reversed string, length, 0, and false as arguments.
10. Print the reversed string.


## CODE:
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int string_length(const char *string) {
    int length = 0;
    for (int i=0; string[i] != '\0'; i++) {
        length++;
    }
    return length;
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
```
## OUTPUT
```
aditya@LAPTOP:~$ gcc string_reverse.c -o string_reverse
aditya@LAPTOP:~$ ./string_reverse
Enter a string: Hello World
The reversed string is: dlroW olleH
```

## RESULT:
The reversed string is printed to the console.