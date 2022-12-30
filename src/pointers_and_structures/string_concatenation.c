/*
[String concatenation] Read two strings str1 and str2 from the user.
The size of each string should be allocated dynamically which is entered by the user.
A new string str3 should concatenate the first half of str1 and second half of str2.
The size of str3 should also be estimated in runtime and allocated sufficient memory
dynamically to hold relevant parts of str1 and str2.

Note: If length is odd, then first half is integer part of division by 2 and 
second half is length minus integer part (i.e, if length is 5, then first half is 2 chars, and 3 chars 
(i.e., 5-2) is the second half).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int estimateLength(int length1, int length2) {
    return (length1 / 2) + length2 - (length2 / 2);
}

int main() {
    char *string1, *string2, *string3;
    int length1, length2, length3, first_half, second_half;
    printf("Enter the length of string 1: ");
    scanf("%d", &length1);
    string1 = (char *)malloc(length1 * sizeof(char));
    printf("Enter the length of string 2: ");
    scanf("%d", &length2);
    string2 = (char *)malloc(length2 * sizeof(char));
    printf("Enter string 1: ");
    scanf("%s", string1);
    printf("Enter string 2: ");
    scanf("%s", string2);
    length1 = strlen(string1);
    length2 = strlen(string2);
    length3 = estimateLength(length1, length2);
    string3 = (char *)malloc(length3 * sizeof(char));
    if (length3 % 2 == 0) {
        first_half = length1 / 2;
        second_half = length2 / 2;
    } else {
        first_half = length1 / 2;
        second_half = length2 - length2 / 2;
    }
    for (int i=0; i<first_half; i++) {
        string3[i] = string1[i];
    }
    for (int i=0; i<second_half; i++) {
        string3[i + first_half] = string2[i + first_half];
    }
    // Another way to do this is:    
    // for (int i=0; i<length3; i++) {
    //     if (i < length1 / 2) {
    //         string3[i] = string1[i];
    //     } else {
    //         string3[i] = string2[i];
    //     }
    // }
    printf("String 3 is: %s", string3);
}
