#include <stdio.h>
#include <stdlib.h>
//Here we are creating 3 Linked List for 1st Polynomial 2nd Polynomial and the resultant polynomial.
struct Node {
    int cff, pwr;
    struct Node* next;
};

struct Node* push(struct Node* top, int cff, int pwr) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->cff = cff;
    temp->pwr = pwr;
    temp->next = NULL;

    if (top == NULL)
        return temp;

    struct Node* p = top;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    return top;
}

void display(struct Node* p) {
    while (p->next != NULL) {
        printf("%dx^%d", p->cff, p->pwr);
        if (p->next != NULL && p->next->cff >= 0)
            printf("+");
        p = p->next;
    }
    printf("%d\n", p->cff);
}

void add(struct Node* top) {
    struct Node* p1, * p2, * dup;
    p1 = top;

    while (p1 != NULL && p1->next != NULL) {
        p2 = p1;

        while (p2->next != NULL) {
            if (p1->pwr == p2->next->pwr) {
                p1->cff = p1->cff + p2->next->cff;
                dup = p2->next;
                p2->next = p2->next->next;
                free(dup);
            } else
                p2 = p2->next;
        }
        p1 = p1->next;
    }
}

struct Node* multiply(struct Node* poly1, struct Node* poly2, struct Node* poly3) {
    struct Node* p1, * p2;
    p1 = poly1;
    p2 = poly2;
    
    while (p1 != NULL) {
        while (p2 != NULL) {
            int cff, pwr;
            
            cff = p1->cff * p2->cff;
            pwr = p1->pwr + p2->pwr;
            
            poly3 = push(poly3, cff, pwr);
            p2 = p2->next;
        }
        p2 = poly2;
        p1 = p1->next;
    }
    
    add(poly3);
    return poly3;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* poly3 = NULL;

    int cff, pwr, terms;

    printf("Enter the number of terms in Polynomial 1: ");
    scanf("%d", &terms);
    for (int i = 0; i < terms; i++) {
        printf("Enter the coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &cff, &pwr);
        poly1 = push(poly1, cff, pwr);
    }

    printf("Enter the number of terms in Polynomial 2: ");
    scanf("%d", &terms);
    for (int i = 0; i < terms; i++) {
        printf("Enter the coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &cff, &pwr);
        poly2 = push(poly2, cff, pwr);
    }

    printf("1st Polynomial: ");
    display(poly1);
    
    printf("2nd Polynomial: ");
    display(poly2);

    poly3 = multiply(poly1, poly2, poly3);

    printf("Resultant Polynomial: ");
    display(poly3);

    return 0;
}
