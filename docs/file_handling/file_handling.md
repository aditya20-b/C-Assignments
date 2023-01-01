# FILE HANDLING

## AIM:
The aim of the program is to accept three file names as command line arguments (file1, file2 and file3), copy the contents of file1 to file2, and if file1 does not exist, display an error message. If file2 already exists, it asks the user whether to overwrite the existing contents or to append the contents and does accordingly. Finally, it appends the details of file3 to file2 and counts the number of word occurrences in file2.

## ALGORITHM:
1. Check if the correct number of command line arguments (i.e., 3) are provided. If not, display the usage message and exit.
2. Get the file names from the command line arguments and open file1 in read mode. If file1 does not exist, display an error message and exit.
3. Open file2 in read mode to check if it exists. If file2 exists, ask the user whether to overwrite or append to the file. If the user selects to overwrite, open file2 in write mode; if the user selects to append, open file2 in append mode. If file2 does not exist, open file2 in write mode.
4. Copy the contents of file1 to file2.
5. Close file1 and file2, and then open file3 in read mode. If file3 does not exist, display an error message and exit.
6. Open file2 in append mode and append the contents of file3 to file2.
7. Close file3 and file2, and then open file2 in read mode.
8. Count the number of word occurrences in file2 and display the result.
9. Close file2 and exit.

## CODE:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Check if the correct number of arguments are provided
  if (argc != 4) {
    printf("Usage: %s file1 file2 file3\n", argv[0]);
    exit(1);
  }

  // Get the file names from the command line arguments
  char *file1 = argv[1];
  char *file2 = argv[2];
  char *file3 = argv[3];

  // Open file1 in read mode
  FILE *fp1 = fopen(file1, "r");
  // Check if file1 exists
  if (fp1 == NULL) {
    perror("Error");
    printf("No such file: %s\n", file1);
    exit(1);
  }

  // Open file2 in read mode to check if it exists
  FILE *fp2 = fopen(file2, "r");
  // If file2 exists, ask the user whether to overwrite or append
  if (fp2 != NULL) {
    char ch;
    printf("File %s already exists. Overwrite or Append (o/a)? ", file2);
    scanf("%c", &ch);

    // Close file2 if it was opened in read mode
    fclose(fp2);

    // Open file2 in write or append mode based on user's choice
    if (ch == 'o') {
      fp2 = fopen(file2, "w");
    } else if (ch == 'a') {
      fp2 = fopen(file2, "a");
    } else {
      printf("Invalid choice. Exiting program.\n");
      exit(1);
    }
  } else {
    // If file2 does not exist, open it in write mode
    fp2 = fopen(file2, "w");
  }

  // Copy the contents of file1 to file2
  char c;
  while ((c = fgetc(fp1)) != EOF) {
    fputc(c, fp2);
  }

  // Close file1 and file2
  fclose(fp1);
  fclose(fp2);

  // Open file3 in read mode
  FILE *fp3 = fopen(file3, "r");
  // Check if file3 exists
  if (fp3 == NULL) {
    perror("Error");
    printf("No such file: %s\n", file3);
    exit(1);
  }

  // Open file2 in append mode
  fp2 = fopen(file2, "a");
    // Append the contents of file3 to file2
  while ((c = fgetc(fp3)) != EOF) {
    fputc(c, fp2);
  }

  // Close file3 and file2
  fclose(fp3);
  fclose(fp2);

  // Open file2 in read mode
  fp2 = fopen(file2, "r");
  // Check if file2 exists
  if (fp2 == NULL) {
    perror("Error");
    printf("No such file: %s\n", file2);
    exit(1);
  }

  // Count the number of word occurrences in file2
  int word_count = 0;
  char word[256];
  while (fscanf(fp2, "%s", word) == 1) {
    word_count++;
  }

  printf("Number of word occurrences in %s: %d\n", file2, word_count);

  // Close file2
  fclose(fp2);

  return 0;
}
```

## OUTPUT:
```
aditya@LAPTOP:~$ gcc cli_args.c -o cli_args
aditya@LAPTOP:~$ ./cli_args file1.txt file2.txt file3.txt
File file2.txt already exists. Overwrite or Append (o/a)? a
Number of word occurrences in file2.txt: 6
aditya@LAPTOP:~$ cat file2.txt
This is file1.
```

## RESULT:
The program will copy the contents of file1 to file2, and if file1 does not exist, it will display an error message. If file2 already exists, it will ask the user whether to overwrite the existing contents or to append the contents and do accordingly. Finally, it will append the details of file3 to file2 and count the number of word occurrences in file2. The result of the program will be displayed on the screen.

<div style="page-break-after: always"></div>

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

<div style="page-break-after: always"></div>

## AIM: 
To create a program that maintains a library of books and allows the user to perform various tasks related to the library, such as adding, deleting, and searching for books, and printing the list of books.


## ALGORITHM: 

The above program that maintain a library of books. It has several functions that perform different tasks related to the library:

1. `loadBooks()`: This function reads the contents of a file called "books.txt" and stores the information about each book in an array of struct Book. It also increments the size of the library by 1 for each book that is read from the file.

2. `addBook()`: This function prompts the user to enter the details of a new book and adds it to the end of the array of struct Book. The availability of the new book is set to true by default.

3. `deleteBook()`: This function prompts the user to enter the name of a book, and removes the book from the array if it is present. It shifts the subsequent elements of the array one position to the left to fill the gap left by the deleted book.

4. `searchBook()`: This function prompts the user to enter the name of a book, and searches the array of struct Book for a book with that name. If the book is found, it prints a message indicating that the book was found.

5. `printBooks()`: This function prints the names of all the books in the array.

6. `rewriteFile()`: This function overwrites the contents of the "books.txt" file with the information about the books stored in the array.

The `main()` function is the entry point of the program. It defines an array of `struct Book` called `books` and a variable `size` to store the number of books in the library. It then opens the "books.txt" file in append mode and calls the `loadBooks()` function to read the contents of the file into the books array.

A `while` loop is then used to display a menu of options to the user and perform the corresponding task based on the user's choice. The options include adding a book, deleting a book, searching for a book, printing the list of books, and quitting the program. The `rewriteFile()` function is called after each action that modifies the `books` array, to update the "books.txt" file with the latest information. The program exits when the user selects the option to quit.



## CODE: 
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Book {
    char name[100];
    char author[100];
    int pages;
    float price;
    bool availability;
};

void loadBooks(struct Book *books, int *size) {
    FILE *fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("Error opening file");
        exit(1);
    }
    while (fscanf(fp, "%s %s %d %f %d", books[*size].name, books[*size].author, &books[*size].pages, &books[*size].price, &books[*size].availability) != EOF) {
        *size += 1;
    }
    fclose(fp);
}

void addBook(struct Book *books, int *size) {
    printf("Enter the name of the book: ");
    scanf("%s", books[*size].name);
    printf("Enter the author of the book: ");
    scanf("%s", books[*size].author);
    printf("Enter the number of pages in the book: ");
    scanf("%d", &books[*size].pages);
    printf("Enter the price of the book: ");
    scanf("%f", &books[*size].price);
    books[*size].availability = true;
    *size += 1;
}

void deleteBook(struct Book *books, int *size) {
    char name[100];
    printf("Enter the name of the book to be deleted: ");
    scanf("%s", name);
    for (int i=0; i<*size; i++) {
        if (strcmp(books[i].name, name) == 0) {
            for (int j=i; j<*size-1; j++) {
                books[j] = books[j+1];
            }
            *size -= 1;
            printf("%s has been removed from the library\n", name);
            printf("Book deleted successfully\n");
            return;
        }
    }
    printf("No such book");
}

void searchBook(struct Book *books, int size) {
    char name[100];
    printf("Enter the name of the book to be searched: ");
    scanf("%s", name);
    for (int i=0; i<size; i++) {
        if (strcmp(books[i].name, name) == 0) {
            printf("Book found");
            return;
        }
    }
    printf("No such book");
}


void printBooks(struct Book *books, int size) {
    printf("The books are: \n");
    for (int i=0; i<size; i++) {
        printf("%d. %s\n ", i+1, books[i].name);
    }
}


void rewriteFile(FILE *fp, struct Book *books, int size) {
    // clear all contents of the file or delete the file and remake it
    fclose(fp);
    fp = fopen("books.txt", "w");
    for (int i=0; i<size; i++) {
        fprintf(fp, "%s %s %d %f %d\n", books[i].name, books[i].author, books[i].pages, books[i].price, books[i].availability);
    }
    fclose(fp);
}


int main() {
    struct Book books[100];
    int size = 0;
    int choice;
    FILE *fp;
    fp = fopen("books.txt", "a+");
    if (fp == NULL) {
        fp = fopen("books.txt", "w");
        fclose(fp);
        fp = fopen("books.txt", "a+");
    }
    loadBooks(books, &size);
    while (true) {
        printf("=====MENU=====\n");
        printf("1. Add a book\n");
        printf("2. Delete a book\n");
        printf("3. Search for a book\n");
        printf("4. Print all books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook(books, &size);
                rewriteFile(fp, books, size);
                fflush(fp);
                break;
            case 2:
                deleteBook(books, &size);
                rewriteFile(fp, books, size);
                break;
            case 3:
                searchBook(books, size);
                break;
            case 4:
                printBooks(books, size);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice");
        };
    }
    return 0;
}

```

<div style="page-break-after: always"></div>

## OUTPUT: 
```
aditya@LAPTOP:~$ gcc bob_the_librarian.c -o bob_the_librarian
aditya@LAPTOP:~$ ./bob_the_librarian
=====MENU=====
1. Add a book
2. Delete a book
3. Search for a book
4. Print all books
5. Exit
Enter your choice: 1
Enter the name of the book: HarryPotter
Enter the author of the book: Rowling
Enter the number of pages in the book: 100
Enter the price of the book: 100
=====MENU=====
1. Add a book
2. Delete a book
3. Search for a book
4. Print all books
5. Exit
Enter your choice: 4
The books are:
    1. HarryPotter
```
## RESULT:
The program is now able to read the initial list of books from a file called "books.txt", allow the user to add new books to the library, delete books from the library, search for a book by name, print the list of books in the library, and update the "books.txt" file with the latest information about the books after each action that modifies the library.
The program should also provide a menu of options for the user to choose from and should continue to run until the user chooses to quit.

