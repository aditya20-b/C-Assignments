## AIM:
To calculate the sum of all the even numbers between a given range of numbers.


## ALGORITHM:
1. Take two integers start and end as input from the user, representing the starting and ending numbers of the range.
2. Define a function `sum_of_even_numbers()` that takes `start` and `end` as arguments.
3. Inside the function, check if `start` is greater than `end`. If it is, return 0.
4. If `start` is not greater than `end`, check if it is an even number. If it is, return the sum of `start` and the result of the function called with `start+1` and `end` as arguments.
5. If `start` is not an even number, return the result of the function called with `start+1` and `end` as arguments.
6. In the `main` function, call the `sum_of_even_numbers()` function with `start` and `end` as arguments and print the result.
## CODE:
```c
#include <stdio.h>

int sum_of_even_numbers(int start, int end) {
    if (start > end) {
        return 0;
    }
    else if (start % 2 == 0) {
        return start + sum_of_even_numbers(start+1, end);
    }
    else {
        return sum_of_even_numbers(start+1, end);
    }
}

int main() {
    int start, end;
    printf("Enter the starting number: ");
    scanf(" %d", &start);
    printf("Enter the ending number: ");
    scanf(" %d", &end);
    printf("The sum of all the even numbers between %d and %d is %d", start, end, sum_of_even_numbers(start, end));
}
```

## OUTPUT
```
aditya@LAPTOP:~$ gcc sum_of_even_numbers.c -o sum_of_even_numbers
aditya@LAPTOP:~$ ./sum_of_even_numbers
Enter the starting number: 1
Enter the ending number: 10
The sum of all the even numbers between 1 and 10 is 30
```

# RESULT:
The sum of all the even numbers between start and end will be printed on the screen.