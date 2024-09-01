#include <stdio.h>

struct Student {
    int reg_no;
    char name[50];
    int age;
    float cgpa;
};

int main() {
    struct Student students[5];
    int i, max_index = 0;

    for (i = 0; i < 5; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Register Number: ");
        scanf("%d", &students[i].reg_no);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("CGPA: ");
        scanf("%f", &students[i].cgpa);
        printf("\n");
    }

    for (i = 1; i < 5; i++) {
        if (students[i].cgpa > students[max_index].cgpa) {
            max_index = i;
        }
    }

    printf("Student with the greatest CGPA:\n");
    printf("Register Number: %d\n", students[max_index].reg_no);
    printf("Name: %s\n", students[max_index].name);
    printf("Age: %d\n", students[max_index].age);
    printf("CGPA: %.2f\n", students[max_index].cgpa);

    return 0;
}
