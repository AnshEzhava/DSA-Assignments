#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void LinkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deleteFirstNode(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node * deleteNodeAtIndex(struct Node * head, int index){
    struct Node * p = head;
    int i = 0;
    while(i != index - 1){
        p = p->next;
        i++;
    }
    struct Node * q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct Node * deleteLastNode(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->next != NULL){
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node * deleteNodeWithGivenValue(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->data != value && q->next != NULL){
        q = q->next;
        p = p->next;
    }

    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}

int main(){
    struct Node* head = (struct Node *)malloc(sizeof(struct Node));
    struct Node* second = (struct Node *)malloc(sizeof(struct Node));
    struct Node* third = (struct Node *)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    head = deleteNodeWithGivenValue(head, 2);
    printf("After deleting first node\n");
    LinkedListTraversal(head);
}