/*
Write a program that removes all the vowels from a given string using an array.
*/

#include <stdio.h>

int string_length(const char *string) {
    int string_length = 0;
    for (int i=0; string[i] != '\0'; i++) {
        string_length++;
    }
    return string_length;
}

int remove_vowels(char *string) {
    int length = string_length(string);
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int vowel_count = 0;
    for (int i=0; i<length; i++) {
        for (int j=0; j<10; j++) {
            if (string[i] == vowels[j]) {
                vowel_count++;
                for (int k=i; k<length; k++) {
                    string[k] = string[k+1];
                }
                i--;
                break;
            }
        }
    }
    return vowel_count;
}

int main() {
    char string[100];
    printf("Enter a string: ");
    scanf(" %[^\n]s", string);
    int vowel_count = remove_vowels(string);
    printf("The string after removing vowels is: %s", string);
}
