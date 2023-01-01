## AIM:
To write a function that calculates the factorial of a given number using recursion.

## ALGORITHM:
1. Take a number as input from the user
2. Define a function `factorial` that takes an integer as argument
3. In the function, check if the number is 0 or 1. If it is, return 1
4. If the number is not 0 or 1, return the product of the number and the factorial of the number-1
5. In the main function, call the `factorial` function with the input number as argument and print the result


## CODE:
```c
/*
Write a function that calculates the factorial of a given number using recursion.
*/

#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d", n, factorial(n));
    return 0;
}
```
## OUTPUT
```
aditya@LAPTOP:~$ gcc factorial.c -o factorial
aditya@LAPTOP:~$ ./factorial
Enter a number: 5
Factorial of 5 is 120
```

## RESULT:
The factorial of the given number will be printed on the screen
