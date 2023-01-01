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