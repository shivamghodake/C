#include <stdio.h>

struct Student {
    int rollNumber;
    char name[50];
    int marks;
};

int main() {
    struct Student students[100];
    int numStudents = 0;

    printf("Enter student information (rollNumber name marks):\n");
    printf("Enter 0 for rollNumber to finish:\n");

    int rollNumber;
    while (1) {
        printf("Roll Number: ");
        scanf("%d", &rollNumber);

        if (rollNumber == 0) {
            break;
        }

        printf("Name: ");
        scanf("%s", students[numStudents].name);

        printf("Marks: ");
        scanf("%d", &students[numStudents].marks);

        students[numStudents].rollNumber = rollNumber;
        numStudents++;
    }

    printf("Student information:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d %s %d\n", students[i].rollNumber, students[i].name, students[i].marks);
    }

    return 0;
}
