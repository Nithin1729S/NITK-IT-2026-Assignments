#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int empId;
    char name[50];
    int age;
    char gender;
    float salary;
};

void swap(struct Employee *a, struct Employee *b) {
    struct Employee temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct Employee *arr, int n, int (*compare)(const void *, const void *)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(&arr[j], &arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int compareBySalary(const void *a, const void *b) {
    return ((struct Employee *)b)->salary - ((struct Employee *)a)->salary;
}

int compareById(const void *a, const void *b) {
    return ((struct Employee *)a)->empId - ((struct Employee *)b)->empId;
}

int main() {
    int numEmployees;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    struct Employee *employees = (struct Employee *)malloc(numEmployees * sizeof(struct Employee));

    for (int i = 0; i < numEmployees; ++i) {
        printf("\nEnter details for employee %d:\n", i + 1);
        employees[i].empId = i + 1;

        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Age: ");
        scanf("%d", &employees[i].age);

        printf("Gender (M/F): ");
        scanf(" %c", &employees[i].gender);

        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    printf("\nUnsorted List of Employees:\n");
    printf("ID\tName\tAge\tGender\tSalary\n");
    for (int i = 0; i < numEmployees; ++i) {
        printf("%d\t%s\t%d\t%c\t%.2f\n", employees[i].empId, employees[i].name, employees[i].age, employees[i].gender, employees[i].salary);
    }

    printf("\nChoose sorting option:\n");
    printf("1. Sort by Salary\n");
    printf("2. Sort by Employee ID\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        bubbleSort(employees, numEmployees, compareBySalary);
        break;
    case 2:
        bubbleSort(employees, numEmployees, compareById);
        break;
    default:
        printf("Invalid choice\n");
        return 1;
    }

    printf("\nSorted List of Employees:\n");
    printf("ID\tName\tAge\tGender\tSalary\n");
    for (int i = 0; i < numEmployees; ++i) {
        printf("%d\t%s\t%d\t%c\t%.2f\n", employees[i].empId, employees[i].name, employees[i].age, employees[i].gender, employees[i].salary);
    }

    free(employees);

    return 0;
}

