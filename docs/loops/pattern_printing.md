## AIM:
To print a pattern of increasing number of asterisks in each row based on the number of rows entered by the user

## ALGORITHM:
1. Get the number of rows from the user as input
2. Use a nested loop to print the pattern. The outer loop will iterate through the rows, and the inner loop will iterate through the number of asterisks in each row.
3. In each iteration of the inner loop, print an asterisk.
4. After the inner loop completes, print a newline character to move to the next row.
5. Continue this process until the outer loop completes.

## CODE:
```c
#include<stdio.h>

int main()  {
    int i, j, rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    for(i=1; i<=rows; i++)  {
        for(j=1; j<=i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc pattern.c -o pattern
aditya@LAPTOP:~$ ./pattern
Enter the number of rows: 5
*
**
***
****
*****
```
## FLOWCHART:
<img src="https://cdn.discordapp.com/attachments/1027218472675069962/1058728962227961876/EAmOhp.png" alt="FLOWCHART" height="800px"/>

## RESULT:
The program will print a pattern of asterisks as per the number of rows entered by the user. 