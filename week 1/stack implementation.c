#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
int stack[MAX_SIZE];

int top = -1;

void push(int data);
int pop();
void display();

int main() {
    printf("Stack Implementation\n");

    printf("\n[Pushing elements]\n");
    push(10);
    push(20);
    push(30);
    display();

    push(40);
    push(50);
    push(60);
    display();

    printf("\n[Popping elements]\n");
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();

    return 0;
}

void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("STACK OVERFLOW: Cannot push %d.\n", data);
        return;
    }
    stack[++top] = data;
    printf("Pushed: %d\n", data);
}

int pop() {
    if (top == -1) {
        printf("STACK UNDERFLOW: Cannot pop from an empty stack.\n");
        return -1;
    }
    int val = stack[top--];
    printf("Popped: %d\n", val);
    return val;
}

void display() {
    if (top == -1) {
        printf("\nThe stack is currently empty.\n");
        return;
    }

    printf("\nStack contents (top to bottom):\n");
    for (int i = top; i >= 0; --i) {
        printf(" %d |\n", stack[i]);
    }
    printf("--------\n");
}