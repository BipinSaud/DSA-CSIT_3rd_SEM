// linkedlist implementation of array

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    int size;
} LinkedList;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

LinkedList *createLinkedList()
{
    LinkedList *newLinkedList = (LinkedList *)malloc(sizeof(LinkedList));
    newLinkedList->head = NULL;
    newLinkedList->size = 0;
    return newLinkedList;
}

// insert at the end
void insertAtTheEnd(LinkedList *list, int data)
{
    Node *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        Node *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

// insert at the beginning
void insertAtBeginning(LinkedList *list, int data)
{
    Node *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }
    list->size++;
}

// delete the data
void deleteLastItem(LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *current = list->head;
    Node *previous = NULL;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    if (previous != NULL)
        previous->next = NULL;
    else
        list->head = NULL;
    free(current);
    list->size--;
}

void deleteFirstItem(LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *first = list->head;
    list->head = list->head->next;
    free(first);
    list->size--;
}

void display(LinkedList *list)
{
    Node *current = list->head;
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

void insertAtIndex(LinkedList *list, int index, int data)
{
    if (index < 0 || index > list->size)
    {
        printf("Index out of bound\n");
        return;
    }
    if (index == 0)
    {
        insertAtBeginning(list, data);
        return;
    }
    if (index == list->size)
    {
        insertAtTheEnd(list, data);
        return;
    }
    Node *newNode = createNode(data);
    Node *current = list->head;
    Node *previous = NULL;
    for (int i = 0; i < index; i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = newNode;
    newNode->next = current;
    list->size++;
}

// delete at index
void deleteAtIndex(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        printf("Index out of bound\n");
        return;
    }
    if (index == 0)
    {
        deleteFirstItem(list);
        return;
    }
    if (index == list->size - 1)
    {
        deleteLastItem(list);
        return;
    }
    Node *current = list->head;
    Node *previous = NULL;
    for (int i = 0; i < index; i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
    list->size--;
}

int main()
{
    LinkedList *list = createLinkedList();
    int choice, data, index;

    while (1)
    {
        // all above functions to a menu
        printf("\n1. Insert at the end\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at index\n");
        printf("4. Delete last item\n");
        printf("5. Delete first item\n");
        printf("6. Delete at index\n");
        printf("7. Display\n");
        printf("8. Exit\n");
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
            insertAtBeginning(list, data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter index: ");
            scanf("%d", &index);
            insertAtIndex(list, index, data);
            break;
        case 4:
            deleteLastItem(list);
            break;
        case 5:
            deleteFirstItem(list);
            break;
        case 6:
            printf("Enter index: ");
            scanf("%d", &index);
            deleteAtIndex(list, index);
            break;
        case 7:
            display(list);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }

        printf("\n");
        display(list);
        printf("\n\n");
    }

    return 0;
}