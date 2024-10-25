#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *newNode(int data){
    struct Node* stackNode = (struct Node *)malloc(sizeof(struct Node));
    stackNode->data = data;
    stackNode->next = NULL;

    return stackNode;
}

int isEmpty(struct Node * top){
    return !top;
}

void push(struct Node** top, int data){
    struct Node * stackNode = newNode(data);
    stackNode->next = *top;
    *top = stackNode;
    printf("%d pushed into the stack.\n", data);
}

int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node *temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void printStack(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack contents: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main(){
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printStack(stack);

    printf("%d popped from stack\n", pop(&stack));
    printStack(stack);
    
    printf("Top element is %d\n", peek(stack));

    return 0;
}