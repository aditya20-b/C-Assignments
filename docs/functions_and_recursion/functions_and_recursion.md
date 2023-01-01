# FUNCTIONS AND RECURSION

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

<div style="page-break-after: always"></div>

## AIM:
To determine whether a given number is prime or not using recursion.

## ALGORITHM:
1. Accept an integer as input from the user
2. Define a function `is_prime` with two integer arguments, iter and num
3. In the function, check if num is equal to iter. If it is, return false
4. If num is not equal to iter, check if num is divisible by iter. If it is, return true
5. If num is not divisible by iter, call the `is_prime` function again with the arguments iter+1 and num
5. In the main function, use the `is_prime` function to determine whether the input number is prime or not

## CODE:
```c
#include <stdio.h>
#include <stdbool.h>
int is_prime(int iter, int num) {
    if (num == iter) 
        return false;
    else if (num % iter == 0) 
        return true;
    else 
        return is_prime(iter+1, num);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf(" %d", &num);
    if (is_prime(2, num)) 
        printf("The number is not a prime number");
    else 
        printf("The number is a prime number");
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

<div style="page-break-after: always"></div>

## AIM:
To write a function that calculates the factorial of a given number using recursion.

## ALGORITHM:
1. Define the function `sum_of_all_elements()` which takes in an array and its length as input.
2. In the function, check if the length of the array is zero. If it is, return zero.
3. If the length of the array is not zero, return the value of the last element in the array plus the sum of all elements in the array, excluding the last element.
4. In the main function, get the length of the array and the elements of the array as input from the user.
5. Call the `sum_of_all_elements()` function with the array and its length as arguments.
6. Print the sum of all elements in the array.
## CODE:
```c
#include <stdio.h>

int sum_of_all_elements(int array[], int length) {
    if (length == 0) {
        return 0;
    } else {
        return array[length - 1] + sum_of_all_elements(array, length - 1);
    }
}

int main() {
    int array[100], length;
    printf("Enter the length of the array: ");
    scanf(" %d", &length);
    printf("Enter the elements of the array: \n");
    for (int i=0; i<length; i++) {
        printf("Enter the element %d: ", i+1);
        scanf(" %d", &array[i]);
    }
    int sum = sum_of_all_elements(array, length);
    printf("The sum of all the elements in the array is: %d", sum);
}
```

<div style="page-break-after: always"></div>

## OUTPUT
```
aditya@LAPTOP:~$ gcc sum_of_all_elements.c -o sum_of_all_elements
aditya@LAPTOP:~$ ./sum_of_all_elements
Enter the length of the array: 5
Enter the elements of the array:
Enter the element 1: 1
Enter the element 2: 2
Enter the element 3: 3
Enter the element 4: 4
Enter the element 5: 5
The sum of all the elements in the array is: 15
```

## RESULT:
The sum of all the elements in the array will be printed on the screen

<div style="page-break-after: always"></div>

## AIM:
To write a function that reverses a string using recursion.

## ALGORITHM:

1. Define a function called `string_length` that takes in a string as an argument. Initialize a variable called `length` to 0.
2. Iterate over the string with a for loop. For each iteration, increment the `length` by 1 and return the `length` when the loop ends.
3. Define a function called `string_reverse` that takes in a string, a reversed string, a string length, a reversed string index, and a boolean as arguments.
4. If the `length` is equal to 0, return 0, if the boolean is true, print the string at the index length-1.
5. Assign the value of the string at the index `length-1` to the reversed string at the index `reversed_string_index`.
6. Call `string_reverse` again with the string, reversed string, string_length-1, reversed_string_index+1, and the boolean as arguments.
7. In main, define a string called string and another called reversed_string and then get the string from the user.
8. Get the length of the string using the string_length function.
9. Call the `string_reverse` function with the string, reversed string, length, 0, and false as arguments.
10. Print the reversed string.


## CODE:
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int string_length(const char *string) {
    int length = 0;
    for (int i=0; string[i] != '\0'; i++) {
        length++;
    }
    return length;
}

int string_reverse(const char *string, char *reversed_string, int string_length, int reversed_string_index, bool print_string) {
    if (string_length == 0) {
        return 0;
    } else {
        if (print_string) {
            printf("%c", string[string_length-1]);
        }
        reversed_string[reversed_string_index] = string[string_length-1];
        return string_reverse(string, reversed_string, string_length-1, reversed_string_index+1, print_string);
    }
}

int main() {
    char string[100];
    char reversed_string[100];
    printf("Enter a string: ");
    scanf(" %[^\n]s", string);
    int length = string_length(string);
    string_reverse(string, reversed_string, length, 0, false);
    printf("The reversed string is: %s", reversed_string);
    return 0;
}
```
## OUTPUT
```
aditya@LAPTOP:~$ gcc string_reverse.c -o string_reverse
aditya@LAPTOP:~$ ./string_reverse
Enter a string: Hello World
The reversed string is: dlroW olleH
```

## RESULT:
The reversed string is printed to the console.

<div style="page-break-after: always"></div>

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

<div style="page-break-after: always"></div>

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
<div style="page-break-after: always"></div>


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