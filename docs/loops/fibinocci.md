## AIM:
To find the Fibonacci series of n natural numbers

## ALGORITHM:
1. Initialize variables t1 and t2 to 0 and 1 respectively. Initialize a loop variable i to 1.
2. Read in the value of n from the user.
3. Print the value of t1.
4. Set the value of nextTerm to the sum of t1 and t2.
4. Set the value of t1 to the value of t2 and the value of t2 to the value of nextTerm.
5. Increment the value of i.
6. Repeat steps 3 to 6 until the value of i is greater than n.

## CODE:
```c
#include <stdio.h>

int main() {
    int i, n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibinocci Series of %d terms ", n);
    for (i = 1; i <= n; i++) {
        printf("\n%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return 0;
}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc fibinocci.c -o fibinocci
aditya@LAPTOP:~$ ./fibinocci
Enter the number of terms: 5
Fibinocci Series of 5 terms
0
1
1
2
3
```
## FLOWCHART:
<img src="https://cdn.discordapp.com/attachments/1027218472675069962/1058723088533049414/cRlSKE.png" alt="FLOWCHART" height="800px"/>

## RESULT:
The program will print the Fibonacci series of n natural numbers.