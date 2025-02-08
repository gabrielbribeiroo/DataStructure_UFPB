/*
Consider the following statements to represent the registration of students in a subject and implement a function that prints the registration number, name, class and average of all students approved in the subject.
Assume that the strategy for approval is given by the average of the three tests (p1, p2 and p3). 
The function receives as parameters the number of students and a vector of pointers to the student data.
*/

#include <stdio.h>

#define SIZE_NAME 81
#define SIZE_ID 8

struct student {
	char name[81];
	char id[8];
	char class;
	float e1;
	float e2;
	float e3;
};

typedef struct student Student;

void print_approved(int n, Student **class) {
    for (int i = 0; i < n; i++) {
        float average = (class[i]->e1 + class[i]->e2 + class[i]->e3) / 3;
        if (average < 7) {
            continue;
        }
        printf("\nStudent approved!\n");
        printf("Registration number: %s\n", class[i]->id);
        printf("Name: %s\n", class[i]->name);
        printf("Class: %c\n", class[i]->class);
        printf("Average: %.2f\n", average);
    }
}

int main() {
	int qnt;
	printf("Enter the number of students: ");
	scanf("%d", &qnt);

	
	for (int i = 0; i < qnt; i++) {
		struct student s; // create a student
        Student *p = &s; // create a pointer to the student

        // read student data
        printf("\nEnter the student's name: ");
        scanf(" %[^\n]", s.name);
        printf("Enter the student's id: ");
        scanf(" %[^\n]", s.id);
        printf("Enter the student's class: ");
        scanf(" %c", &s.class);
        printf("Enter the student's grade in the first test: ");
        scanf("%f", &s.e1);
        printf("Enter the student's grade in the second test: ");   
        scanf("%f", &s.e2);
        printf("Enter the student's grade in the third test: ");
        scanf("%f", &s.e3);

        // checks if the student is approved
        print_approved(1, &p);
    }

	return 0;
}