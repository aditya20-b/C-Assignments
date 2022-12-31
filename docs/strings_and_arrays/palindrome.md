## AIM:
To check if the given string is a palindrome or not.

## ALGORITHM:
1. Get a string from the user and store it in a variable.
2. Find the length of the string.
3. Check if the string is a palindrome by comparing the first character with the last character, second character with the second last character and so on.
4. If all the characters match, print the string is a palindrome. If any character does not match, print the string is not a palindrome.

## CODE:
```c
#include <stdio.h>

int main() {
    char str[100];
    int i, length;
    int flag = 0;
    printf("Enter a string: ");
    scanf("%s", str);
    length = 0;
    while (str[length] != '\0')
        length++;
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
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc palindrome.c -o palindrome
aditya@LAPTOP:~$ ./palindrome
Enter a string: aditya
aditya is not a palindrome
```

## RESULT:
The program will check if the given string is a palindrome or not and print the result accordingly.