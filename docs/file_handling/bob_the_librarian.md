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

