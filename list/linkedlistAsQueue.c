// linkedlist implementation of array

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *head;
} Queue;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue *createQueue()
{
    Queue *newLinkedList = (Queue *)malloc(sizeof(Queue));
    newLinkedList->head = NULL;
    return newLinkedList;
}

// insert at the beginning
void enqueue(Queue *queue, int data)
{
    Node *newNode = createNode(data);
    if (queue->head == NULL)
    {
        queue->head = newNode;
    }
    else
    {
        newNode->next = queue->head;
        queue->head = newNode;
    }
}

// delete the data
void dequeue(Queue *queue)
{
    if (queue->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *current = queue->head;
    Node *previous = NULL;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    if (previous != NULL)
        previous->next = NULL;
    else
        queue->head = NULL;
    free(current);
}

void display(Queue *queue)
{
    Node *current = queue->head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}
int main()
{
    Queue *queue = createQueue();
    int choice, data;

    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(queue, data);
            break;

        case 2:
            dequeue(queue);
            break;

        case 3:
            printf("Queue: ");
            display(queue);
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
        printf("\n");
        printf("Queue:");
        display(queue);
        printf("\n\n");
    } while (choice != 4);

    return 0;
}