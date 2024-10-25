#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int *array;
    int top;
    int capacity;
};

struct Stack *createStack(int capacity){
    struct Stack *newStack = (struct Stack*)malloc(sizeof(struct Stack));
    newStack->capacity = capacity;
    newStack->top = -1;
    newStack->array = (int*)malloc(newStack->capacity * (sizeof(int)));

    return newStack;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

int isFull(struct Stack* stack){
    return stack->top == stack->capacity - 1;
}

void push(struct Stack *stack, int value){
    if(isFull(stack)){
        printf("Stack OverFlow");
    }
    stack->array[++stack->top] = value;
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is already empty");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty");
        return -1;
    }

    return stack->array[stack->top];
}

void printStack(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty");
        return;
    }
    printf("Stack Contents: ");
    for(int i = 0; i <= stack->top; i++){
        printf("%d ", stack->array[i]);
    }

    printf("\n");
}

int main(){
    struct Stack *stack = createStack(10);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("top value: %d\n", peek(stack));

    printStack(stack);
}