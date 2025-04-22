#include <stdio.h>
#include <stdlib.h>


struct Student {
    int rollNumber;
    char *name;
    float *marks;
};


void inputStudentDetails(struct Student *student) {
    printf("Enter Roll Number: ");
    scanf("%d", &student->rollNumber);

    printf("Enter Name: ");
    
    student->name = (char *)malloc(50 * sizeof(char));
    scanf("%s", student->name);

    printf("Enter Marks: ");
    student->marks = (float *)malloc(sizeof(float));
    scanf("%f", student->marks);
}


void displayStudentDetails(struct Student *student) {
    printf("\nStudent Details:\n");
    printf("Roll Number: %d\n", student->rollNumber);
    printf("Name: %s\n", student->name);
    printf("Marks: %.2f\n", *student->marks);
}


void freeMemory(struct Student *student) {
    free(student->name);
    free(student->marks);
}

int main() {
    
    struct Student student1;

    
    inputStudentDetails(&student1);

    
    displayStudentDetails(&student1);

    
    freeMemory(&student1);

    return 0;
}
