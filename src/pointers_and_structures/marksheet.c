/*
2. Define a data type for Date having 3 members namely day, month and year. 
Define a data type for Student with members rollnum, name, marks[5], totalMarks, rank, dateofbirth (of type Date), age, gender. 
Use an enumerated data type for gender with values MALE, FEMALE, TRANSGENDER. 
Write a C program that gets data for N students, computes and displays the rank of the students. 
Use array of structures. 
Write a C function that takes an array of structures of students and compute their rank. 
Write another C function that prints the mark sheet of a particular student with all the details in a proper format designed by you.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUBJECTS 5

typedef struct date {
    int day;
    int month;
    int year;
} date;

typedef enum gender {
    MALE, FEMALE, TRANSGENDER
} gender;

typedef struct student {
    int rollnum;
    char name[100];
    int marks[SUBJECTS];
    int totalMarks;
    int rank;
    date dateofbirth;
    int age;
    gender genderOfStudent;
} student;

int totalMarks(student *s) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum = sum + s->marks[i];
    }
    return sum;
}


void getData(student *s, int n) {
    int input;
    for (int i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", s[i].name);
        printf("Enter the roll number of the student: ");
        scanf("%d", &s[i].rollnum);
        printf("\nEnter the marks of %s: ", s[i].name);
        for (int j = 0; j < 5; j++) {
            printf("\nEnter the marks of subject %d: ", j+1);
            scanf("%d", &s[i].marks[j]);
        }
        s[i].totalMarks = totalMarks(&s[i]);
        printf("Enter the date of birth of the student  (dd mm yyyy) : ");
        scanf("%d %d %d", &s[i].dateofbirth.day, &s[i].dateofbirth.month, &s[i].dateofbirth.year);
        printf("Enter the age of the student: ");
        scanf("%d", &s[i].age);
        printf("Enter the gender: \n1. MALE\n2. FEMALE\n3. TRANSGENDER\n");
        scanf("%d", &input);
        /*
        if (input == 1 ) {
            s[i].genderOfStudent = MALE
        }
        else if (input == 2) {
            s[i].genderOfStudent = FEMALE
        }
        else if (input == 3) {
            s[i].genderOfStudent
        
        */
        s[i].genderOfStudent = (input == 1) ? MALE : (input == 2) ? FEMALE : TRANSGENDER;

    }
}


void printData(student *s, int n) {
    for (int i = 0; i < n; i++) {
        char gender[100];
        printf("The details of student %d are: ", i+1);
        printf("\nName: %s", s[i].name);
        switch (s[i].genderOfStudent) {
            case MALE:
                snprintf(gender, sizeof(gender), "\nGender: MALE");
                break;
            case FEMALE:
                snprintf(gender, sizeof(gender), "\nGender: FEMALE");
                break;
            case TRANSGENDER:
                snprintf(gender, sizeof(gender), "\nGender: TRANSGENDER");
                break;
        };
        
        printf(gender);
        printf("\nRoll number: %d", s[i].rollnum);
        printf("\nMarks: ");
        for (int j = 0; j < 5; j++) {
            printf("\n\tSubject %d: %d", j+1, s[i].marks[j]);
        }
        printf("\nTotal marks: %d", s[i].totalMarks);
        printf("\nRank: %d", s[i].rank+1);
        printf("\nDate of birth: %d/%d/%d", s[i].dateofbirth.day, s[i].dateofbirth.month, s[i].dateofbirth.year);
        printf("\nAge: %d", s[i].age);
        printf("\n\n\n");       
    }
}


void computeRank(student *students, int n) {
    // sort students in descending order of total marks
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].totalMarks < students[j + 1].totalMarks) {
                student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            };
        };
    };

    // assign ranks to students
    for (int i=0; i<n; i++) {
        students[i].rank = i;        
    };
    
    // if total marks of two students are same, assign the same rank to both of them
    for (int i=0; i<n; i++) {
        if (students[i].totalMarks == students[i+1].totalMarks) {
            students[i+1].rank = students[i].rank;
        };
    };

}


int main() {
    int n;
    printf("\nEnter the number of students: ");
    scanf("%d", &n);
    student s[n];
    getData(s, n);
    computeRank(s, n);
    printData(s, n);
    return 0;   
}