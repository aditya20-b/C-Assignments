## AIM:
The aim of this code is to manage data related to waiters, items, and bills in a restaurant. It allows the user to add new waiters, items, and bills, and also provides functionality to print the list of waiters, items, and bills, and a summary of sales made by each waiter for each item.

## ALGORITHM:
1. Initialize structs for waiters, items, and bills, and corresponding sizes for each struct.
2. Implement functions to add new waiters, items, and bills, and update the corresponding sizes.
3. Implement functions to print the list of waiters, items, and bills.
4. Implement a function to print the summary of sales made by each waiter for each item. This function will iterate through the bills array and update a summary array with the sales made by each waiter for each item. It will then print the summary array along with the names of the waiters and items.

## CODE:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define WAITERS 5
#define ITEMS 5



struct waiter {
    int id;
    char name[100];
};

struct Bill {
    int waiter_id;
    int item_id;
    float cost;
};

struct Item {
    int id;
    char name[100];
    float price;
};

void addWaiter(struct waiter *waiters, int *size) {
    printf("Enter the name of the waiter: ");
    scanf("%s", waiters[*size].name);
    waiters[*size].id = *size + 1;
    *size += 1;
    printf("Waiter added successfully\n\n");
}

void addItem(struct Item *items, int *size) {
    printf("Enter the name of the item: ");
    scanf("%s", items[*size].name);
    items[*size].id = *size + 1;
    *size += 1;
    printf("Item added successfully\n\n");
}

void addBill(struct Bill *bills, int *size) {
    printf("Enter the waiter id: ");
    scanf("%d", &bills[*size].waiter_id);
    printf("Enter the item id: ");
    scanf("%d", &bills[*size].item_id);
    printf("Enter the cost of the item: ");
    scanf("%f", &bills[*size].cost);
    *size += 1;
    printf("Bill added successfully\n\n");
}

void printWaiters(struct waiter *waiters, int size) {
    printf("The waiters are:\n");
    for (int i=0; i<size; i++) {
        printf("%d. %s\n", i+1, waiters[i].name);
    }
    printf("\n\n");
}

void printItems(struct Item *items, int size) {
    printf("The items are:\n");
    for (int i=0; i<size; i++) {
        printf("%d. %s - %frs\n", i+1, items[i].name, items[i].price);
    }
    printf("\n\n");
}

void printBills(struct Bill *bills, int size) {
    printf("The bills are:\n");
    for (int i=0; i<size; i++) {
        printf("The waiter id is: %d\n", bills[i].waiter_id);
        printf("The item id is: %d\n", bills[i].item_id);
        printf("The cost of the item is: %0.2f\n", bills[i].cost);
        printf("\n");
    }
    printf("\n");
}

void line() {
    printf("\n------------------------------------------------------------------\n"); 
    
}

void printSummary(struct Bill *bills, int size, struct waiter *waiters, int waiter_size, struct Item *items, int item_size) {
    float summary[item_size][waiter_size];
    line();
    for (int i=0; i<item_size; i++) {
        for (int j=0; j<waiter_size; j++) {
            summary[i][j] = 0;
        }
    }
    
    for (int i=0; i<size; i++) {
        summary[bills[i].item_id-1][bills[i].waiter_id-1] += bills[i].cost;
    }
    
    printf("\tWaiter\t");
    for (int i=0; i<waiter_size; i++) {
        printf("\t%s\t", waiters[i].name);
    }
    line();
    
    for (int i=0; i<item_size; i++) {
        printf("\t%s\t", items[i].name);
        float total = 0;
        for (int j=0; j<waiter_size; j++) {
            printf("\t%0.2f\t", summary[i][j]);
            total += summary[i][j];
        }
        printf("\t%0.2f\n", total);
    }
    printf("\tTotal\t");
    for (int i=0; i<waiter_size; i++) {
        float total = 0;
        for (int j=0; j<item_size; j++) {
            total += summary[j][i];
        }
        printf("\t%0.2f\t", total);
    }
    printf("\n");
}


int main() {
    struct waiter waiters[WAITERS];
    int waiter_size = 0;
    struct Item items[ITEMS];
    int item_size = 0;
    struct Bill bills[100];
    int bill_size = 0;
    int choice;
    while (true) {
        printf("1. Add a waiter\n");
        printf("2. Add an item\n");
        printf("3. Add a bill\n");
        printf("4. Display waiters\n");
        printf("5. Display items\n");
        printf("6. Display bills\n");
        printf("7. Display summary\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addWaiter(waiters, &waiter_size);
                break;
            case 2:
                addItem(items, &item_size);
                break;
            case 3:
                addBill(bills, &bill_size);
                break;
            case 4:
                printWaiters(waiters, waiter_size);
                break;
            case 5:
                printItems(items, item_size);
                break;
            case 6:
                printBills(bills, bill_size);
                break;
            case 7:
                printSummary(bills, bill_size, waiters, waiter_size, items, item_size);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
```
## OUTPUT:
```
aditya@LAPTOP:~$ gcc -o restaurant_bill restaurant_bill.c
aditya@LAPTOP:~$ ./restaurant_bill
1. Add a waiter
2. Add an item
3. Add a bill
4. Display waiters
5. Display items
6. Display bills
7. Display summary
8. Exit
Enter your choice: 1
Enter the name of the waiter: aditya
Enter your choice: 1
Enter the name of the waiter: vishal
Waiter added successfully
Enter your choice: 2
Enter the name of the item: pizza
Item added successfully
Enter your choice: 2
Enter the name of the item: burger
Item added successfully
Enter your choice: 3
Enter the waiter id: 1
Enter the item id: 1
Enter the cost of the item: 100
Bill added successfully
Enter your choice: 3
Enter the waiter id: 1
Enter the item id: 2
Enter the cost of the item: 50
Bill added successfully
Enter your choice: 3
Enter the waiter id: 2
Enter the item id: 1
Enter the cost of the item: 200
Bill added successfully
Enter your choice: 7
------------------------------------------------------------------
        Waiter           aditya           vishal        
------------------------------------------------------------------
        pizza           100.00           200.00           300.00
        burger          50.00            0.00            50.00
        Total           150.00           200.00           350.00
```
## RESULT:
Hence, a restaurant bill management system is designed.
