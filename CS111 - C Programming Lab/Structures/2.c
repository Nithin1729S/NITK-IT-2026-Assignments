#include<stdio.h>
#include<string.h>

struct Person
{
    char name[40];
    char address[200];
    double tele;
};

void swap(struct Person* p1, struct Person* p2)
{
    struct Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sortTele(struct Person* person, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (person[j].tele > person[j + 1].tele)
            {
                swap(&person[j], &person[j + 1]);
            }
        }
    }
}

int searchOnTele(struct Person* peoples, int low, int high, double key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (key == peoples[mid].tele)
        return mid;

    if (key > peoples[mid].tele)
        return searchOnTele(peoples, mid + 1, high, key);
    else
        return searchOnTele(peoples, low, mid - 1, key);
}

int searchOnName(struct Person* peoples, char* name, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(peoples[i].name, name) == 0)
            return i;
    }
    return -1;
}

int main()
{
    struct Person people[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter Name: ");
        scanf("%s", people[i].name);
        printf("Enter Address: ");
        scanf("%s", people[i].address);
        printf("Enter telephone number: ");
        scanf("%lf", &people[i].tele);
    }
    sortTele(people, 5);

    
    char nameToSearch[40];
    printf("Enter the name to search: ");
    scanf("%s", nameToSearch);
    int nameIndex = searchOnName(people, nameToSearch, 5);

    if (nameIndex != -1)
    {
        printf("Person found by name:\n");
        printf("Name: %s\n", people[nameIndex].name);
        printf("Address: %s\n", people[nameIndex].address);
        printf("Telephone: %.2lf\n", people[nameIndex].tele);
    }
    else
    {
        printf("Person with name %s not found.\n", nameToSearch);
    }

    
    double teleToSearch;
    printf("Enter the telephone number to search: ");
    scanf("%lf", &teleToSearch);
    int teleIndex = searchOnTele(people, 0, 4, teleToSearch);

    if (teleIndex != -1)
    {
        printf("Person found by telephone number:\n");
        printf("Name: %s\n", people[teleIndex].name);
        printf("Address: %s\n", people[teleIndex].address);
        printf("Telephone: %.2lf\n", people[teleIndex].tele);
    }
    else
    {
        printf("Person with telephone number %.2lf not found.\n", teleToSearch);
    }

    return 0;
}
