#include <stdio.h>
#include <string.h>


struct Student {
    char name[50];
    int regNumber;
    int marks[6];
    int totalMarks;
    float percentage;
    char grade;
};


void calculateResult(struct Student *student) {
    student->totalMarks = 0;
    for (int i = 0; i < 6; ++i) {
        student->totalMarks += student->marks[i];
    }

    student->percentage = (float)student->totalMarks / 6.0;

    if (student->percentage >= 90) {
        student->grade = 'A';
    } else if (student->percentage >= 80) {
        student->grade = 'B';
    } else if (student->percentage >= 70) {
        student->grade = 'C';
    } else if (student->percentage >= 60) {
        student->grade = 'D';
    } else if (student->percentage >= 50) {
        student->grade = 'E';
    } else {
        student->grade = 'F';
    }
}

int main() {
    
    struct Student student;

    
    printf("Enter Student Name: ");
    scanf("%s", student.name);

    printf("Enter Registration Number: ");
    scanf("%d", &student.regNumber);

    printf("Enter Marks for 6 Subjects:\n");
    for (int i = 0; i < 6; ++i) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &student.marks[i]);
    }

    
    calculateResult(&student);

    
    printf("\nStudent Mark Sheet:\n");
    printf("Name: %s\n", student.name);
    printf("Registration Number: %d\n", student.regNumber);
    printf("Marks in 6 Subjects:\n");
    for (int i = 0; i < 6; ++i) {
        printf("Subject %d: %d\n", i + 1, student.marks[i]);
    }
    printf("Total Marks: %d\n", student.totalMarks);
    printf("Percentage: %.2f%%\n", student.percentage);
    printf("Grade: %c\n", student.grade);

    return 0;
}
