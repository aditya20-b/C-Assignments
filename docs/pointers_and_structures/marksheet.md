## AIM:
The aim of this code is to create a program that can store and manipulate data about students, including their name, roll number, marks in various subjects, total marks, rank, date of birth, age, and gender.

## ALGORITHM:
1. Define a struct and an enum to store data about a student.
2. Define a function `totalMarks` to calculate the total marks of a student.
3. Define a function `getData` to input data about multiple students.
4. Define a function `printData` to print data about multiple students.
5. In the `main` function, ask the user for the number of students and call the `getData` and `printData` functions to input and display the data about the students.

## CODE:
```c
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
```
## OUTPUT:
```
aditya@LAPTOP:~$ gcc -o marksheet marksheet.c
aditya@LAPTOP:~$ ./marksheet
Enter the number of students: 2
Enter the name of student 1: Aditya
Enter the roll number of the student: 1

Enter the marks of Aditya:
Enter the marks of subject 1: 90
Enter the marks of subject 2: 80
Enter the marks of subject 3: 70
Enter the marks of subject 4: 80
Enter the marks of subject 5: 90
Enter the date of birth of the student  (dd mm yyyy) : 21 10 2004
Enter the age of the student: 18
Enter the gender: 
1. MALE
2. FEMALE
3. TRANSGENDER
1
Enter the name of student 2: Vishal
Enter the roll number of the student: 2

Enter the marks of Vishal:
Enter the marks of subject 1: 80
Enter the marks of subject 2: 90
Enter the marks of subject 3: 90
Enter the marks of subject 4: 70
Enter the marks of subject 5: 70

Enter the date of birth of the student  (dd mm yyyy) : 01 01 2000
Enter the age of the student: 23
Enter the gender: 
1. MALE
2. FEMALE
3. TRANSGENDER
1
The details of student 1 are: 
Name: Aditya
Gender: MALE
Roll number: 1
Marks:
        Subject 1: 90
        Subject 2: 80
        Subject 3: 70
        Subject 4: 80
        Subject 5: 90
Total marks: 410
Rank: 1
Date of birth: 21/10/2004
Age: 18


The details of student 2 are:
Name: Vishal
Gender: MALE
Roll number: 2
Marks:
        Subject 1: 80
        Subject 2: 90
        Subject 3: 90
        Subject 4: 70
        Subject 5: 70
Total marks: 400
Rank: 2
Date of birth: 1/1/2000
Age: 23

```

## RESULT:
The program will get data for n students, compute and display their ranks, and print the mark sheet of a particular student with all their details.
