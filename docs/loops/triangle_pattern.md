## AIM:
To print a triangle shaped pattern using *, where the number of rows is determined by the user

## ALGORITHM:
1. Prompt the user to enter the number of rows for the pattern
2. Use two for loops to iterate through the rows and columns of the pattern
3. The outer for loop will iterate through the rows, while the inner for loop will iterate through the columns
4. For each row, print spaces in the first part of the row using the outer for loop
5. For each row, print * in the second part of the row using the inner for loop
6. After each row is printed, move to the next line
7. Repeat the process until all rows have been printed

## CODE:
```c
#include<stdio.h>


int main()  {
    int i, j, rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    for(i=1; i<=rows; i++)  {
        for(j=1; j<=rows-i; j++) {
            printf(" ");
        }
        for(j=1; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
```
## OUTPUT:
```
aditya@LAPTOP:~$ gcc triangle_pattern.c -o triangle_pattern
aditya@LAPTOP:~$ ./triangle_pattern
Enter the number of rows: 5
    *
   * *
  * * *
 * * * *
* * * * *
```

## FLOWCHART:
<img src="https://cdn.discordapp.com/attachments/1027218472675069962/1058731314448183326/EGRFRE.png" alt="FLOWCHART" height="800px"/>

## RESULT:
A triangle shaped pattern is printed using *, with the number of rows determined by the user