# LOOPS:
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
<div style="page-break-after: always"></div>

## FLOWCHART:
<img src="https://cdn.discordapp.com/attachments/1027218472675069962/1058728962227961876/EAmOhp.png" alt="FLOWCHART" height="800px"/>

## RESULT:
The program will print a pattern of asterisks as per the number of rows entered by the user. 

<div style="page-break-after: always"></div>

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
<div style="page-break-after: always"></div>

## FLOWCHART:
<img src="https://cdn.discordapp.com/attachments/1027218472675069962/1058731314448183326/EGRFRE.png" alt="FLOWCHART" height="800px"/>

## RESULT:
A triangle shaped pattern is printed using *, with the number of rows determined by the user

<div style="page-break-after: always"></div>

## AIM:
To find the largest and smallest elements in an array of numbers

## ALGORITHM:
1. Declare and initialize variables for the array, its size, and two variables to store the largest and smallest element
2. Prompt the user to enter the size of the array and then get the elements of the array from the user
3. Set the largest and smallest elements to the first element in the array
4. Iterate through the array with a loop starting from the second element
5. For each element in the array, compare it to the largest and smallest elements. If it is larger than the largest element, set the largest element to this element. If it is smaller than the smallest element, set the smallest element to this element
6. After the loop ends, print the largest and smallest elements

## CODE:
```c
#include <stdio.h>

int main() {
    int array[100], i, n, largest, smallest;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the array: ");
    for (i = 0; i < n; i++) {
        printf("\nEnter the element %d: ", i);
        scanf("%d", &array[i]);
    }
    largest = array[0];
    smallest = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }
    printf("\nThe largest element in the array is %d", largest);
    printf("\nThe smallest element in the array is %d", smallest);
}
```

<div style="page-break-after: always"></div>

## OUTPUT:
```
aditya@LAPTOP:~$ gcc largest_and_smallest.c -o largest_and_smallest
aditya@LAPTOP:~$ ./largest_and_smallest
Enter the number of elements in the array: 5
Enter the elements of the array:
Enter the element 0: 1
Enter the element 1: 2
Enter the element 2: 3
Enter the element 3: 4
Enter the element 4: 5
The largest element in the array is 5
The smallest element in the array is 1
```
<div style="page-break-after: always"></div>

## FLOWCHART:
<img src="https://cdn.discordapp.com/attachments/1027218472675069962/1058724133178982531/C4E5Xj.png" alt="FLOWCHART" height="800px"/>

## RESULT:
The largest and smallest elements in the array are printed to the screen

<div style="page-break-after: always"></div>

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
<div style="page-break-after: always"></div>

## FLOWCHART:
<img src = "https://cdn.discordapp.com/attachments/1027218472675069962/1058729353866915860/code2flow_GAWk3l.png" alt="FLOWCHART" size="800px">

## RESULT:      
The program will take a five-digit number input by the user and print the sum of its digits.

<div style="page-break-after: always"></div>

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
<div style="page-break-after: always"></div>

## FLOWCHART:
<img src="https://cdn.discordapp.com/attachments/1027218472675069962/1058725967801098240/ybFR31.png" alt="FLOWCHART" height="800px"/>

## RESULT:
The program will print the total number of currency notes of denominations 10, 50, and 100 that the cashier will have to give to the withdrawer.

<div style="page-break-after: always"></div>

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

<div style="page-break-after: always"></div>

## FLOWCHART:
<img src="https://cdn.discordapp.com/attachments/1027218472675069962/1058730512593727508/uoDrrE.png" alt="FLOWCHART" size="80px">

## RESULT:
The first n natural numbers are printed and their sum is calculated and displayed.

<div style="page-break-after: always"></div>

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
<div style="page-break-after: always"></div>

## FLOWCHART:
<img src="https://cdn.discordapp.com/attachments/1027218472675069962/1058723088533049414/cRlSKE.png" alt="FLOWCHART" height="800px"/>

## RESULT:
The program will print the Fibonacci series of n natural numbers.
