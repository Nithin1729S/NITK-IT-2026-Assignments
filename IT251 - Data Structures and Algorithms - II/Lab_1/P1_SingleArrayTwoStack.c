#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100  //The size of array

struct TwoStacks {
    int top1;
    int top2;
    int* arr;
};


//Function to create Two stacks in the same array arr present in TwoStacks structure
struct TwoStacks* createTwoStacks() {
    struct TwoStacks* twoStacks = (struct TwoStacks*)malloc(sizeof(struct TwoStacks));
    twoStacks->top1 = -1;
    twoStacks->top2 = MAX_SIZE;
    twoStacks->arr = (int*)malloc(MAX_SIZE * sizeof(int));
    return twoStacks;
}


//Function to push in first stack
void push1(struct TwoStacks* ts, int value) {
    if (ts->top1 < ts->top2 - 1) {
        ts->top1++;
        ts->arr[ts->top1] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

//Function to push in second stack
void push2(struct TwoStacks* ts, int value) {
    if (ts->top1 < ts->top2 - 1) {
        ts->top2--;
        ts->arr[ts->top2] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

//Function to pop for first stack
int pop1(struct TwoStacks* ts) {
    if (ts->top1 >= 0) {
        int popped = ts->arr[ts->top1];
        ts->top1--;
        return popped;
    } else {
        printf("Stack 1 Underflow\n");
        return -1;
    }
}

//Function to pop from second stack
int pop2(struct TwoStacks* ts) {
    if (ts->top2 < MAX_SIZE) {
        int popped = ts->arr[ts->top2];
        ts->top2++;
        return popped;
    } else {
        printf("Stack 2 Underflow\n");
        return -1;
    }
}


int main() {
    struct TwoStacks* ts = createTwoStacks();
    
    push1(ts, 5);
    push2(ts, 10);
    push1(ts, 15);
    push2(ts, 20);
    
    printf("Popped element from stack 1: %d\n", pop1(ts));  //15
    printf("Popped element from stack 2: %d\n", pop2(ts));  //20
    return 0;
}