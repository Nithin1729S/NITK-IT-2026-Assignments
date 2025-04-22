#include <stdio.h>

int main() {
    int mathMarks, physicsMarks, chemistryMarks;

    printf("Enter marks in Mathematics: ");
    scanf("%d", &mathMarks);

    printf("Enter marks in Physics: ");
    scanf("%d", &physicsMarks);

    printf("Enter marks in Chemistry: ");
    scanf("%d", &chemistryMarks);

    if ((mathMarks >= 60 && physicsMarks >= 50 && chemistryMarks >= 40 && mathMarks + physicsMarks + chemistryMarks >= 200) || (mathMarks + physicsMarks >= 150)) {
        printf("Congratulations! You are eligible for admission.\n");
    } else {
        printf("Sorry, you are not eligible for admission.\n");
    }

    return 0;
}
