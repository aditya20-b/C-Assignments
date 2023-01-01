/*
Write a program in C which accepts three file names as command line arguments, file1, file2 and file3.
Copy the contents of file1 to file2. If file1 already exists copy the contents to file2 otherwise display as no such file.
If file2 already exists, ask the user whether to overwrite the existing contents or to append the contents and do accordingly.
Now, append the details of file3 to file2 and count the number of word occurrences in file2.
*/


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

