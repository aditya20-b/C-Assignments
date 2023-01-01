## AIM: 
To create an interactive program in C to maintain a list of names, addresses, and phone numbers and perform the following operations:
* Add a new record at the end of a file
* Retrieve and display the entire record for a given name
* List all names with their addresses and phone numbers

## ALGORITHM:

1. Define a structure `contact` with three fields - name, address, and phone number.
2. Create a function `add_new_record` that accepts a file pointer as an argument. Inside this function, create a variable of type `contact` and get the values of name, address, and phone number from the user. Then, write these values to the file using the fprintf function.
3. Create a function `list_all_records` that accepts a file pointer as an argument. Inside this function, create a variable of type `contact` and use the `fseek` function to move the file pointer to the beginning of the file. Then, use the `fscanf` function to read all the records in the file and print them to the screen.
4. Create a function `retrieve_record` that accepts a file pointer as an argument. Inside this function, create a variable of type `contact` and get the name of the record to be retrieved from the user. Then, use the `fseek` function to move the file pointer to the beginning of the file. Use the `fscanf` function to read all the records in the file and compare the name with the one entered by the user. If a match is found, print the entire record to the screen and return from the function. If no match is found, print "No such record".
5. Create a function `choices` that displays the menu and gets the user's choice.
6. In the main function, open the file "contacts.txt" in append mode. If the file cannot be opened, print an error message and exit the program. Inside a while loop, get the user's choice using the `choices` function and execute the appropriate action based on the choice. If the choice is 1, call the `add_new_record` function. If the choice is 2, call the `retrieve_record` function. If the choice is 3, call the `list_all_records` function. If the choice is 4, exit the program. If the choice is invalid, print an error message.

## CODE:
```c
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
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc address_book.c -o address_book
aditya@LAPTOP:~$ ./address_book
1. Add a new record
2. Retrieve a record
3. List all records
4. Exit
Enter your choice: 1
Enter name: Aditya
Enter address: Chennai
Enter phone number: 1234567890

1. Add a new record
2. Retrieve a record
3. List all records
4. Exit
Enter your choice: 3

Name: Aditya
Address: Chennai
Phone number: 1234567890
```
## RESULT:
The program should be able to maintain a list of names, addresses, and phone numbers and perform the required operations on the list. The list should be stored in the file "contacts.txt" and the file should be updated whenever a change is made to the list.
