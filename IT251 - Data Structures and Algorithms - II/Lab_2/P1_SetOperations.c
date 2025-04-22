//This code inputs two arrays and finds union intersection and difference of both 
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>


//swap functoin to help bubble sort
void swap(int* xp, int* yp)   
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void setUnion(int arr1[], int size1, int arr2[], int size2, int result[], int *resultSize) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else if (arr2[j] < arr1[i]) {
            result[k++] = arr2[j++];
        } else {
            result[k++] = arr1[i++];
            j++;
        }
    }

    
    while (i < size1) {
        result[k++] = arr1[i++];
    }
    while (j < size2) {
        result[k++] = arr2[j++];
    }

    *resultSize = k;
}

void setIntersection(int arr1[], int size1, int arr2[], int size2, int result[], int *resultSize) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr1[i]) {
            j++;
        } else {
            result[k++] = arr1[i++];
            j++;
        }
    }

    *resultSize = k;
}

void setDifference(int arr1[], int size1, int arr2[], int size2, int result[], int *resultSize) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else if (arr2[j] < arr1[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    while (i < size1) {
        result[k++] = arr1[i++];
    }

    *resultSize = k;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

int main() {

    int *array1;
    int size1;

    int *array2;
    int size2;

    printf("Enter the size of the first array: ");
    scanf("%d",&size1);
    array1=(int*)malloc(sizeof(int)*size1);
    for(int i=0;i<size1;i++) scanf("%d",&array1[i]);

    printf("Enter the size of the second array: ");
    scanf("%d",&size2);
    array2=(int*)malloc(sizeof(int)*size2);
    for(int i=0;i<size2;i++) scanf("%d",&array2[i]);


    //Sort two arrays 
    bubbleSort(array1,size1);
    bubbleSort(array2,size2);
    
    int resultUnion[100], resultIntersection[100], resultDifference[100];
    int resultSizeUnion, resultSizeIntersection, resultSizeDifference;
    
    //Call alll functions
    setUnion(array1, size1, array2, size2, resultUnion, &resultSizeUnion);
    setIntersection(array1, size1, array2, size2, resultIntersection, &resultSizeIntersection);
    setDifference(array1, size1, array2, size2, resultDifference, &resultSizeDifference);

    //print all 
    printf("Union: ");
    for (int i = 0; i < resultSizeUnion; i++) {
        printf("%d ", resultUnion[i]);
    }
    printf("\n");

    printf("Intersection: ");
    for (int i = 0; i < resultSizeIntersection; i++) {
        printf("%d ", resultIntersection[i]);
    }
    printf("\n");

    printf("Difference: ");
    for (int i = 0; i < resultSizeDifference; i++) {
        printf("%d ", resultDifference[i]);
    }
    printf("\n");
    return 0;
}
