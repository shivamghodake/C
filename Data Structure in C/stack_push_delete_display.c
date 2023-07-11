#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct Stack {
    int top;
    int elements[MAX_SIZE];
};
void initialize(struct Stack* stack) {
    stack->top = -1;
}
void push(struct Stack* stack, int element) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push element %d\n", element);
        return;
    }
    stack->elements[++stack->top] = element;
}
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow: Cannot pop element from an empty stack\n");
        return -1;
    }
    return stack->elements[stack->top--];
}
void display(struct Stack* stack) {
    printf("Elements in the stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}
int main() {
    struct Stack stack;
    initialize(&stack);
    printf("Enter 10 elements to insert into the stack:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        int element;
        scanf("%d", &element);
        push(&stack, element);
    }
    printf("Inserted elements: ");
    display(&stack);
    printf("Deleting 2 elements from the stack...\n");
    for (int i = 0; i < 2; i++) {
        pop(&stack);
    }
    printf("Remaining elements after deletion: ");
    display(&stack);
    return 0;
}
