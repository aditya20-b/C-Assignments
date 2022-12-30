/*
A restaurant has 5 waiters (Waiter IDs: 1 to 5) and has 5 items (Item IDs: 1 to 5) in the menu. Each waiter writes a slip for each customer (Assume 1 customer orders only 1 item). The slip contains the following information:

a) Waiter ID

b) Item ID

c) Cost of the item (in Rupees)

At the end of the day, all the slips are consolidated.
Write a program to read the information from each slip and summarize the data into a table (2D array).
Print the results in tabular format with each column representing a waiter and each row representing an item.
Total each row to find the total sales (in Rupees) of an item on that day.
Total each column to find the total sales (in Rupees) by each waiter. 
Column totals should be printed below each column and row totals should be printed to the right of each row.
*/


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
    printf("Enter the price of the item: ");
    scanf("%f", &items[*size].price);
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

// FIX: This function is not working properly and I don't know why
void printSummary(struct Bill *bills, int size, struct waiter *waiters, int waiter_size, struct Item *items, int item_size) {
    float summary[item_size][waiter_size];
    for (int i=0; i<size; i++) {
        summary[bills[i].item_id-1][bills[i].waiter_id-1] += bills[i].cost;
    }
    printf("\t\t");
    /*
      printf("\t\t");
  for (int i = 0; i < NUM_WAITERS; i++) {
    printf("Waiter %d\t", i + 1);
  }
  printf("Total\n");
  for (int i = 0; i < NUM_ITEMS; i++) {
    printf("Item %d\t", i + 1);
    float row_total = 0;
    for (int j = 0; j < NUM_WAITERS; j++) {
      printf("%.2f\t\t", summary[j][i]);
      row_total += summary[j][i];
    }
    printf("%.2f\n", row_total);
  }
  printf("Total\t\t");
  for (int i = 0; i < NUM_WAITERS; i++) {
    float col_total = 0;
    for (int j = 0; j < NUM_ITEMS; j++) {
      col_total += summary[i
        
    */
    printf("Waiter\t");
    for (int i=0; i<waiter_size; i++) {
        printf("%s\t", waiters[i].name);
    }
    printf("Total\n");
    for (int i=0; i<item_size; i++) {
        printf("%s\t", items[i].name);
        float total = 0;
        for (int j=0; j<waiter_size; j++) {
            printf("%f\t", summary[i][j]);
            total += summary[i][j];
        }
        printf("%f\n", total);
    }
    printf("Total\t");
    for (int i=0; i<waiter_size; i++) {
        float total = 0;
        for (int j=0; j<item_size; j++) {
            total += summary[j][i];
        }
        printf("%f\t", total);
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