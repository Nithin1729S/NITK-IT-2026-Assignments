#include <stdio.h>

struct Student
{
    char name[20];
    int regNo;
    int marks[6];
    int total;
    double avg;
};

void swap(struct Student *a, struct Student *b)
{
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void sortRegNo(struct Student *students, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].regNo > students[j + 1].regNo)
            {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

int binarySearch(struct Student *students, int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (students[mid].regNo == key)
            return mid;

        if (students[mid].regNo < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; 
}

int main()
{
    struct Student students[200];
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter Student's Name: ");
        scanf("%s", students[i].name);
        printf("Enter Register Num: ");
        scanf("%d", &students[i].regNo);
        printf("Enter Marks in 6 subjects separated by spaces: ");
        for (int j = 0; j < 6; j++)
            scanf("%d", &students[i].marks[j]);

        int total = 0;
        for (int j = 0; j < 6; j++)
            total += students[i].marks[j];

        students[i].total = total;
        students[i].avg = (double)total / 6.0;
    }

    
    sortRegNo(students, n);

    
    int key;
    printf("Enter the registration number to search: ");
    scanf("%d", &key);

    int index = binarySearch(students, 0, n - 1, key);

    if (index != -1)
    {
        printf("Student found:\n");
        printf("%s %d %d %lf\n", students[index].name, students[index].regNo, students[index].total, students[index].avg);
    }
    else
    {
        printf("Student with registration number %d not found.\n", key);
    }

    return 0;
}
