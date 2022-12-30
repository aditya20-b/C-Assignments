/*
Bob is a librarian. He requires a system that can enable him to add new books, delete any existing book,
search for the availability of books, and print all the books. 
The system should also be able to store the information about the books in a file
and read from the file when the program is run.
Create a structure called books and store the relevant information,
and create separate user-defined functions for performing the above operations.
Write a menu-driven program to get a choice from the librarian. Based on his choice, 
the corresponding functions should be invoked, and the structure should be updated. 
The program should also save the updated information to the file when the program is closed.
*/

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

