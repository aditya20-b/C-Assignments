## AIM:
The aim of the program is to print the numbers from N to 0 using a recursive function.

## ALGORITHM:
1. Declare a function named `printTillZero` that takes an integer `num` as an argument.
2. Inside the function, check if `num` is equal to 0. If it is, return 0.
3. If `num` is not equal to 0, print `num` and call the `printTillZero` function with `num - 1` as the argument.
4. In the `main` function, get the number `num` from the user and call the `printTillZero` function with `num` as the argument.
## CODE:
``` c
#include <stdio.h>

int printTillZero(int num) {
    if (num == 0) {
        return 0;
    } else {
        printf("%d ", num);
        return printTillZero(num - 1);
    }
}

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printTillZero(num);
    return 0;
}
```

## OUTPUT
```
aditya@LAPTOP:~$ gcc print_till_zero.c -o print_till_zero
aditya@LAPTOP:~$ ./print_till_zero
Enter the number: 5
5 4 3 2 1
```

## RESULT:
The program will take an number input from the user and print the numbers from that number to 0 using a recursive function.
