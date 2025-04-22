#include <stdio.h>


struct SimpleStruct1 {
    int a;
    char b;
};

struct SimpleStruct2 {
    double x;
    int y;
};

struct SimpleStruct3 {
    char c;
    short d;
};


struct NestedStruct1 {
    struct SimpleStruct1 inner1;
    float e;
};

struct NestedStruct2 {
    struct SimpleStruct2 inner2;
    char f;
};

struct NestedStruct3 {
    struct SimpleStruct3 inner3;
    int g;
};


union SimpleUnion1 {
    int h;
    char i;
};

union SimpleUnion2 {
    double j;
    int k;
};

union SimpleUnion3 {
    char l;
    short m;
};


union NestedUnion1 {
    union SimpleUnion1 inner4;
    float n;
};

union NestedUnion2 {
    union SimpleUnion2 inner5;
    char o;
};

union NestedUnion3 {
    union SimpleUnion3 inner6;
    int p;
};

int main() {
    
    printf("Size of SimpleStruct1: %lu bytes\n", sizeof(struct SimpleStruct1));
    printf("Size of SimpleStruct2: %lu bytes\n", sizeof(struct SimpleStruct2));
    printf("Size of SimpleStruct3: %lu bytes\n", sizeof(struct SimpleStruct3));
    printf("=================================================================\n");

    
    printf("Size of NestedStruct1: %lu bytes\n", sizeof(struct NestedStruct1));
    printf("Size of NestedStruct2: %lu bytes\n", sizeof(struct NestedStruct2));
    printf("Size of NestedStruct3: %lu bytes\n", sizeof(struct NestedStruct3));
    printf("=================================================================\n");


    
    printf("Size of SimpleUnion1: %lu bytes\n", sizeof(union SimpleUnion1));
    printf("Size of SimpleUnion2: %lu bytes\n", sizeof(union SimpleUnion2));
    printf("Size of SimpleUnion3: %lu bytes\n", sizeof(union SimpleUnion3));
    printf("=================================================================\n");


    
    printf("Size of NestedUnion1: %lu bytes\n", sizeof(union NestedUnion1));
    printf("Size of NestedUnion2: %lu bytes\n", sizeof(union NestedUnion2));
    printf("Size of NestedUnion3: %lu bytes\n", sizeof(union NestedUnion3));
    printf("=================================================================\n");


    return 0;
}
