// circularlinkedlist implementation of array

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct LinkedList
{
    Node *head;
    int size;
} CircularLinkedList;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

CircularLinkedList *createLinkedList()
{
    CircularLinkedList *newLinkedList = (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
    newLinkedList->head = NULL;
    newLinkedList->size = 0;
    return newLinkedList;
}

// insert at the end
void insertAtTheEnd(CircularLinkedList *list, int data)
{
    Node *newNode = createNode(data);
    Node *current = list->head;
    if (list->head == NULL)
    {
        list->head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    else if (list->head->next == list->head)
    {
        newNode->prev = list->head;
        newNode->next = list->head;
        list->head->next = newNode;
        list->head->prev = newNode;
        return;
    }
    while (current->next != list->head)
    {
        current = current->next;
    }
    newNode->prev = current;
    current->next = newNode;
    newNode->next = list->head;
    list->head->prev = newNode;
    list->size++;
}

// insert at the beginning
void insertAtTheBeginning(CircularLinkedList *list, int data)
{
    Node *newNode = createNode(data);
    Node *current = list->head;
    if (list->head == NULL)
    {
        list->head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    else if (list->head->next == list->head)
    {
        newNode->prev = list->head;
        newNode->next = list->head;
        list->head->next = newNode;
        list->head->prev = newNode;
        list->head = newNode;
        return;
    }
    while (current->next != list->head)
    {
        current = current->next;
    }
    newNode->next = list->head;
    list->head->prev = newNode;
    newNode->prev = current;
    current->next = newNode;
    list->head = newNode;
    list->size++;
}

// delete at the end
void deleteAtTheEnd(CircularLinkedList *list)
{
    Node *current = list->head;
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if (list->head->next == list->head)
    {
        list->head = NULL;
        free(current);
        return;
    }
    while (current->next != list->head)
    {
        current = current->next;
    }
    current->prev->next = list->head;
    list->head->prev = current->prev;
    free(current);
    list->size--;
}

// delete at the beginning
void deleteAtTheBeginning(CircularLinkedList *list)
{
    Node *current = list->head;
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if (list->head->next == list->head)
    {
        list->head = NULL;
        free(current);
        return;
    }
    while (current->next != list->head)
    {
        current = current->next;
    }
    current->next = list->head->next;
    list->head->next->prev = current;
    free(list->head);
    list->head = current->next;
    list->size--;
}

// display

void display(CircularLinkedList *list)
{
    Node *current = list->head;
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (current->next != list->head)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}
