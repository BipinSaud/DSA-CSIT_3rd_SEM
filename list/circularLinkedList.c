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

int main()
{
    CircularLinkedList *list = createLinkedList();
    int choice, data;
    while (1)
    {
        printf("1. Insert at the end\n");
        printf("2. Insert at the beginning\n");
        printf("3. Delete at the end\n");
        printf("4. Delete at the beginning\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtTheEnd(list, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtTheBeginning(list, data);
            break;
        case 3:
            deleteAtTheEnd(list);
            break;
        case 4:
            deleteAtTheBeginning(list);
            break;
        case 5:
            display(list);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
        printf("\n");
        printf(("list:"));
        display(list);
        printf("\n");
    }
    return 0;
}