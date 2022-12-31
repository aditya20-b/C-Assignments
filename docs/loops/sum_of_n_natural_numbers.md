## AIM:
To display the first n natural numbers and find the sum of them.

## ALGORITHM:
1. Initialize variables i, n, and sum. Set sum to 0.
2. Read in the value of n from the user.
3. Use a for loop to iterate from 1 to n.
4. Inside the for loop, print the value of i and add it to the sum.
5. After the for loop, print the sum of the natural numbers.

## CODE:
```c
#include <stdio.h>

int main() {
    int i, n, sum = 0;
    printf("Enter the number of natural numbers: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
        sum = sum + i;
    }
    printf("\nThe sum of natural numbers is: %d", sum);
    return 0;
}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc sum_of_n_natural_numbers.c -o sum_of_n_natural_numbers
aditya@LAPTOP:~$ ./sum_of_n_natural_numbers
Enter the number of natural numbers: 10
1 2 3 4 5 6 7 8 9 10
The sum of natural numbers is: 55
```


## FLOWCHART:
<img src="https://cdn.discordapp.com/attachments/1027218472675069962/1058730512593727508/uoDrrE.png" alt="FLOWCHART" size="80px">

## RESULT:
The first n natural numbers are printed and their sum is calculated and displayed.