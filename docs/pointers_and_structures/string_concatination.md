## AIM:
The aim of this code is to concatenate the first half of one string with the second half of another string, and store the result in a new dynamically allocated string.

## ALGORITHM:
1. Read the lengths of two strings from the user and allocate dynamic memory for each string.
2. Read the two strings from the user.
3. Calculate the length of the new string using the given formula: length3 = (length1 / 2) + (length2 / 2).
4. If either of the lengths is odd, add 1 to the length of the new string.
5. Allocate dynamic memory for the new string.
6. Iterate through the new string and fill it with the appropriate characters from the two input strings.

## CODE:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int estimateLength(int length1, int length2) {
    return (length1 / 2) + length2 - (length2 / 2);
}

int main() {
    char *string1, *string2, *string3;
    int length1, length2, length3, first_half, second_half;
    printf("Enter the length of string 1: ");
    scanf("%d", &length1);
    string1 = (char *)malloc(length1 * sizeof(char));
    printf("Enter the length of string 2: ");
    scanf("%d", &length2);
    string2 = (char *)malloc(length2 * sizeof(char));
    printf("Enter string 1: ");
    scanf("%s", string1);
    printf("Enter string 2: ");
    scanf("%s", string2);
    length1 = strlen(string1);
    length2 = strlen(string2);
    length3 = estimateLength(length1, length2);
    string3 = (char *)malloc((length3 + 1) * sizeof(char));  
    for (int i=0; i<length3; i++) {
        if (i < length1 / 2) {
            string3[i] = string1[i];
        } else {
            string3[i] = string2[i];
        }
    }
    printf("String 3 is: %s", string3);
}

```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc string_concatination.c -o string_concatination
aditya@LAPTOP:~$ ./string_concatination
Enter the length of string 1: 5
Enter the length of string 2: 4
Enter string 1: hello
Enter string 2: world
String 3 is: herld
```

## RESULT:
The result of this code will be a new string that is a concatenation of the first half of one string with the second half of the other string. The size of the new string will be sufficient to hold the relevant parts of the input strings.
