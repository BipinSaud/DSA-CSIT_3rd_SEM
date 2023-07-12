// stack implementation using linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *head;
} Stack;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack *createStack()
{
    Stack *newLinkedList = (Stack *)malloc(sizeof(Stack));
    newLinkedList->head = NULL;
    return newLinkedList;
}

// insert at the beginning
void push(Stack *stack, int data)
{
   Node *newNode = createNode(data);
    if (stack->head == NULL)
    {
        stack->head = newNode;
    }
    else
    {
        Node *current = stack->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// delete the data
void pop(Stack *stack)
{
    if (stack->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *current = stack->head;
    Node *previous = NULL;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    if (previous != NULL)
        previous->next = NULL;
    else
        stack->head = NULL;
    free(current);
}

void display(Stack *stack)
{
    Node *current = stack->head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}
int main()
{
    Stack *stack = createStack();
    int choice, data;

    do
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(stack, data);
            break;

        case 2:
            pop(stack);
            break;

        case 3:
            printf("Stack: ");
            display(stack);
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
        printf("\n");
        printf("Stack:");
        display(stack);
        printf("\n\n");
    } while (choice != 4);

    return 0;
}