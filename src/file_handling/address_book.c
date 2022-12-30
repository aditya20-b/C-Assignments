/*
2. Write an interactive C program to maintain a list of names, addresses and telephone numbers. Store the information as records in a file by representing each record as a structure. Perform the following operations:
	i) Add a new record at the end of file
	ii) Retrieve and display the entire record for a given name
	iii) List all names with their addresses and telephone numbers.

Note: Use fscanf and fprintf functions for reading and writing to the file.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[20];
    char address[50];
    char phone[10];
};

void add_new_record(FILE *fp) {
    struct contact c;
    printf("Enter name: ");
    scanf("%s", c.name);
    printf("Enter address: ");
    scanf("%s", c.address);
    printf("Enter phone number: ");
    scanf("%s", c.phone);
    fprintf(fp, "%s %s %s\n", c.name, c.address, c.phone);
}

void list_all_records(FILE *fp) {
    struct contact c;
    fseek(fp, 0, SEEK_SET);
    while (fscanf(fp, "%s %s %s\n", c.name, c.address, c.phone) != EOF) {
        printf("\nName: %s", c.name);
        printf("\nAddress: %s", c.address);
        printf("\nPhone number: %s", c.phone);
    }
}

void retrieve_record(FILE *fp) {
    struct contact c;
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    fseek(fp, 0, SEEK_SET);
    while (fscanf(fp, "%s %s %s\n", c.name, c.address, c.phone) != EOF) {
        if (strcmp(c.name, name) == 0) {
            printf("\nName: %s", c.name);
            printf("\nAddress: %s", c.address);
            printf("\nPhone number: %s", c.phone);
            return;
        }
    }
    printf("No such record");
}

int choices() {
    int choice;
    printf("\n1. Add a new record");
    printf("\n2. Retrieve a record");
    printf("\n3. List all records");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    FILE *fp;
    struct contact c;
    char name[20];
    int choice;
    fp = fopen("contacts.txt", "a+");
    if (fp == NULL) {
        printf("Error opening file");
        return 0;
    }
    while (1) {
        choice = choices();
        switch (choice) {
            case 1:
                add_new_record(fp);
                break;
            case 2:
                retrieve_record(fp);
                break;
            case 3:
                list_all_records(fp);
                break;
            case 4:
                fflush(fp);
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}
