# LOOPS

## AIM:
To calculate the total number of currency notes of denominations 10, 50, and 100 that a cashier will have to give to a withdrawer when the amount to be withdrawn is input through the keyboard in hundreds.


## ALGORITHM:
1. Get the amount to be withdrawn in hundreds from the user through the keyboard.
2. Initialize counters for each denomination, i.e., count10, count50, and count100 to 0.
3. Use a while loop to distribute the amount in denominations of 10, 50, and 100.
4. Inside the while loop, check if the amount is greater than or equal to 100. If it is, subtract 100 from the amount and increment the count100 counter by 1.
5. If the amount is not greater than or equal to 100, check if it is greater than or equal to 50. If it is, subtract 50 from the amount and increment the count50 counter by 1.
6. If the amount is not greater than or equal to 50, check if it is greater than or equal to 10. If it is, subtract 10 from the amount and increment the count10 counter by 1.
7. Repeat the above steps until the amount becomes less than 10.
8. Print the number of currency notes of each denomination.

## CODE:
```c
#include <stdio.h>
int main() {
    printf("Enter the amount to be withdrawn (in hundreds): ");
    int amount;
    scanf("%d", &amount);
    int count10 = 0;
    int count50 = 0;
    int count100 = 0;
    while (amount > 10) {
        if (amount >= 100) {
            amount -= 100;
            count100++;
        } else if (amount >= 50) {
            amount -= 50;
            count50++;
        } else if (amount >= 10) {
            amount -= 10;
            count10++;
        }
    }
    printf("Total number of currency notes:\n");
    printf("The number of 100 rupee notes is %d\n", count100);
    printf("The number of 50 rupee notes is %d\n", count50);
    printf("The number of 10 rupee notes is %d\n", count10);
    return 0;
}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc denominations.c -o denominations
aditya@LAPTOP:~$ ./denominations
Enter the amount to be withdrawn (in hundreds): 500
Total number of currency notes:
The number of 100 rupee notes is 5
The number of 50 rupee notes is 0
The number of 10 rupee notes is 0
```

## FLOWCHART:
<img src="https://cdn.discordapp.com/attachments/1027218472675069962/1058725967801098240/ybFR31.png" alt="FLOWCHART" height="800px"/>

## RESULT:
The program will print the total number of currency notes of denominations 10, 50, and 100 that the cashier will have to give to the withdrawer.


