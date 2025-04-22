#include <stdio.h>
#include <stdlib.h>


struct Point {
    int x;
    int y;
};


void inputCoordinates(struct Point *ptr) {
    printf("Enter x-coordinate: ");
    scanf("%d", &ptr->x);

    printf("Enter y-coordinate: ");
    scanf("%d", &ptr->y);
}


void displayCoordinates(struct Point *ptr) {
    printf("\nCoordinates: (%d, %d)\n", ptr->x, ptr->y);
}

int main() {
    
    struct Point *pointPtr;

    
    pointPtr = (struct Point *)malloc(sizeof(struct Point));

    
    inputCoordinates(pointPtr);

    
    displayCoordinates(pointPtr);

    
    free(pointPtr);

    return 0;
}
