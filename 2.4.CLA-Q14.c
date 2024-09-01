#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

int main() {
    char students[MAX_STUDENTS][MAX_NAME_LENGTH];
    int student_count = 0;
    char name[MAX_NAME_LENGTH];
    char choice;

    while (1) {
        if (student_count >= MAX_STUDENTS) {
            printf("The list is full. No more students can be added.\n");
            break;
        }

        printf("Enter the student's name: ");
        scanf(" %[^\n]", name);

        strcpy(students[student_count], name);
        student_count++;

        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    printf("\nList of students who have submitted their assignments:\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d. %s\n", i + 1, students[i]);
    }

    return 0;
}
