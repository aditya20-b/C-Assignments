## AIM:
To display the corresponding ASCII characters for a given string.

## ALGORITHM:
1. Declare a character array called string_input to store the string input by the user.
2. Prompt the user to enter a string and use the scanf function to store the input in the string_input array.
3. Initialize a loop to iterate through the elements of the string_input array.
4. Inside the loop, print the ASCII value of each character in the string using the printf function.
5. Repeat the process for each character in the string until the end of the string is reached.

## CODE:
```c
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
```


## OUTPUT:
```
aditya@LAPTOP:~$ gcc string_to_ascii.c -o string_to_ascii
aditya@LAPTOP:~$ ./string_to_ascii
Enter the string: Hello
The ascii characters are:
The ascii value of character H in the string is: 72
The ascii value of character e in the string is: 101
The ascii value of character l in the string is: 108
The ascii value of character l in the string is: 108
The ascii value of character o in the string is: 111
```

## RESULT:
The program will output the ASCII values of each character in the given string.