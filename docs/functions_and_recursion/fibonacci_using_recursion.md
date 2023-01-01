## AIM:
To write a function that generates the Fibonacci sequence using recursion.

## ALGORITHM:
1. Create a function named `fibinocci_generator` that takes in three integer arguments: `num`, `term1` and `term2`
2. If `num` is equal to 0, return from the function
3. Otherwise, print `term1` and call the function again with the arguments `num-1`, `term2` and `term1+term2`
4. In `main`, declare a variable `num` to store the number of terms in the Fibonacci sequence
5. Get the value of `num` from the user and store it in the variable
6. Print the message "Fibinocci Series of %d terms is: " and call the function `fibinocci_generator` with the arguments "num", "0" and "1"
## CODE:
```c
#include <stdio.h>

void fibinocci_generator(int num, int term1, int term2) {
    if (num == 0) {
        return;
    } else {
        printf("%d ", term1);
        fibinocci_generator(num-1, term2, term1+term2);
    }
}

int main() {
    int num;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    printf("Fibinocci Series of %d terms is: ", num);
    fibinocci_generator(num, 0, 1);
    return 0;
}
```
## OUTPUT:
```
aditya@LAPTOP:~$ gcc fibonacci.c -o fibonacci
aditya@LAPTOP:~$ ./fibonacci
Enter the number of terms: 10
Fibinocci Series of 10 terms is: 0 1 1 2 3 5 8 13 21 34
```

## RESULT:
The function will generate the Fibonacci sequence of the given number of terms and print it to the screen.