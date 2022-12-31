## AIM
To find the sum of digits of a five-digit number input by the user

## ALGORITHM:
1. Declare variables for storing the number, remainder and sum
2. Prompt the user to enter a five-digit number
3. Store the number in the variable 'number'
4. Begin a while loop that will run until the value of 'number' is not 0
5. Within the while loop, store the remainder of 'number' when divided by 10 in the variable 'remainder'
6. Add 'remainder' to the variable 'sum'
7. Divide 'number' by 10
8. Repeat steps 4-7 until the value of 'number' is 0
9. Print the value of 'sum'
## CODE:
```c
#include <stdio.h>

int main() {
    int number, sum = 0, remainder;
    printf("Enter a five digit number: ");      scanf("%d", &number);                   
    while (number != 0) {                    
        remainder = number % 10;             
        sum = sum + remainder;                              
        number = number / 10;               
    }                                       
    printf("The sum of digits is: %d", sum);    
    return 0;
}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc sum_of_digits.c -o sum_of_digits
aditya@LAPTOP:~$ ./sum_of_digits
Enter a five digit number: 12345
The sum of digits is: 15
```

## FLOWCHART:
<img src = "https://cdn.discordapp.com/attachments/1027218472675069962/1058729353866915860/code2flow_GAWk3l.png" alt="FLOWCHART" size="800px">

## RESULT:      
The program will take a five-digit number input by the user and print the sum of its digits.