/*
A cashier has currency notes of denominations 10, 50 and 100. If the
amount to be withdrawn is input through the keyboard in hundreds, find the
total number of currency notes of each denomination the cashier will have to
give to the withdrawer. Use while loops to solve this problem
*/

#include <stdio.h>

int main() {
    // get amount to be withdrawn in hundreds
    printf("Enter the amount to be withdrawn (in hundreds): ");
    int amount;
    scanf("%d", &amount);
    
    // initialize counters for each denomination
    int count10 = 0;
    int count50 = 0;
    int count100 = 0;

    // use while loop to distribute the amount in denominations of 10, 50, and 100
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

    // print the number of currency notes of each denomination
    printf("Total number of currency notes:\n");
    printf("The number of 100 rupee notes is %d\n", count100);
    printf("The number of 50 rupee notes is %d\n", count50);
    printf("The number of 10` rupee notes is %d\n", count10);

    return 0;
}
