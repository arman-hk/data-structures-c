// stack structure based on LIFO
#include <stdio.h>

#define max_size 100
typedef struct Stack {
    int data[max_size];
    int top; // for indexing
} Stack;

void push(Stack* stack, int data) {
    if (stack -> top == max_size - 1) {
        printf("Overflow\n");
        return;
    }
    stack -> top++; // if not full then add element
    stack -> data[stack -> top] = data;
}

int pop(Stack* stack) {
    if (stack -> top == -1) {
        printf("Underflow\n");
        return -1;
    }
    int item = stack -> data[stack -> top];
    stack -> top--; // if not empty return the top element
    return item;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}


int main() {
    // init an empty stack
    Stack stack;
    stack.top = -1;

    // push three elements
    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);

    while (!isEmpty(&stack)) {
        printf("%d\n", pop(&stack));
    }
    
    return 0;
}
