## AIM:
To determine whether a given number is prime or not using recursion.

## ALGORITHM:
1. Accept an integer as input from the user
2. Define a function is_prime with two integer arguments, iter and num
3. In the function, check if num is equal to iter. If it is, return false
4. If num is not equal to iter, check if num is divisible by iter. If it is, return true
5. If num is not divisible by iter, call the is_prime function again with the arguments iter+1 and num
5. In the main function, if the is_prime function returns true, print "The number is not a prime number"
6. If the is_prime function returns false, print "The number is a prime number"
## CODE:
```c
#include <stdio.h>
#include <stdbool.h>

int is_prime(int iter, int num) {
    if (num == iter) {
        return false;
    }
    else if (num % iter == 0) {
        return true;
    }
    else {
        return is_prime(iter+1, num);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf(" %d", &num);
    if (is_prime(2, num)) {
        printf("The number is not a prime number");
    }
    else {
        printf("The number is a prime number");
    }
}
```

## OUTPUT
```
aditya@LAPTOP:~$ gcc is_prime.c -o is_prime
aditya@LAPTOP:~$ ./is_prime
Enter a number: 5
The number is a prime number
```

## RESULT:
The program will determine whether the input number is a prime number or not using recursion.