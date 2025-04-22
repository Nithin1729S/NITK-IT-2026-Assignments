#include <stdio.h>


struct Employee {
    int employeeId;
    char name[50];
    float salary;
};

int main() {
    
    FILE *file;
    struct Employee emp;

    
    file = fopen("emp.txt", "w");

    
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    
    int numEmployees;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    
    for (int i = 0; i < numEmployees; ++i) {
        

        
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &emp.employeeId);

        printf("Name: ");
        scanf("%s", emp.name);

        printf("Salary: ");
        scanf("%f", &emp.salary);

        
        fprintf(file, "%d %s %.2f\n", emp.employeeId, emp.name, emp.salary);
    }

    
    fclose(file);

    
    file = fopen("emp.txt", "r");

    
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    
    printf("\nEmployee List:\n");
    while (fscanf(file, "%d %s %f", &emp.employeeId, emp.name, &emp.salary) == 3) {
        printf("Employee ID: %d\n", emp.employeeId);
        printf("Name: %s\n", emp.name);
        printf("Salary: %.2f\n", emp.salary);
        printf("--------------------\n");
    }

    
    fclose(file);

    return 0;
}
