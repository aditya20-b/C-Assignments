## AIM:
Reverse a string using minimum number of exchanges without using any library function.

## ALGORITHM:
1. Take a string as input from the user
2. Find the length of the string
3. Initialize a for loop with index i and iterate it until i<(string_length/2)
4. Inside the for loop, swap the characters at the index i and string_length-i-1
5. Print the reversed string

## CODE:
```c
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
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc string_reverse.c -o string_reverse
aditya@LAPTOP:~$ ./string_reverse
Enter the string: Hello World
The reversed string is: dlroW olleH
```

## RESULT:
The given string is reversed and printed on the screen.
