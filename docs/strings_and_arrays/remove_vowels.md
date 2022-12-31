## AIM:
To remove all the vowels from a given string using an array.
## ALGORITHM:
1. Create a function called `string_length` that takes a string as input and returns the length of the string.
2. Create a function called `remove_vowels` that takes a string as input and removes all the vowels from the string. 
3. Initialize an array of vowels and iterate through the string. For each character in the string, check if it is a vowel by comparing it to each element in the array of vowels. If it is a vowel, remove it from the string by shifting all the subsequent characters in the string one position to the left.
4. In the main function, get a string from the user and call the `remove_vowels` function with the string as input. Print the resulting string.
## CODE:
```c
#include <stdio.h>

int string_length(const char *string) {
    int string_length = 0;
    for (int i=0; string[i] != '\0'; i++) {
        string_length++;
    }
    return string_length;
}

void remove_vowels(char *string) {
    int length = string_length(string);
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i=0; i<length; i++) {
        for (int j=0; j<10; j++) {
            if (string[i] == vowels[j]) {
                for (int k=i; k<length; k++) {
                    string[k] = string[k+1];
                }
                i--;
                break;
            }
        }
    }
}

int main() {
    char string[100];
    printf("Enter a string: ");
    scanf(" %[^\n]s", string);
    remove_vowels(string);
    printf("The string after removing vowels is: %s", string);
}
```
## OUTPUT:
```
aditya@LAPTOP:~$ gcc remove_vowels.c -o remove_vowels
aditya@LAPTOP:~$ ./remove_vowels
Enter a string: aditya
The string after removing vowels is: dty
```

## RESULT:
The program will remove all the vowels from the given string and print the resulting string to the screen.
