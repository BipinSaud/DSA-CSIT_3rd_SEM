// linkedlist implementation of array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void insert(LinkedList *list, int data)
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

// find the data
bool find(LinkedList *list, int data)
{
    for (int i = 0; i < list->size; i++)
    {
        Node *current = list->head;
        current->data == data;
        current = current->next;
        return true;
    }
    return false;
}

// retrieve the data
int retrieve(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        printf("Index out of bound\n");
        return -1;
    }
    Node *current = list->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
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

int getSize(LinkedList *list)
{
    return list->size;
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
        insert(list, data);
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

int main()
{
    LinkedList *list = createLinkedList();
    int choice, data, index;

    while (1)
    {
        // all above functions to a menu
        printf("\n1. Insert at the end\n2. Insert at the beginning\n3. Insert at index\n4. Find\n5. Retrieve\n6. Delete last item\n7. Delete first item\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to insert at the end: ");
            scanf("%d", &data);
            insert(list, data);
            break;

        case 2:
            printf("Enter the data to insert at the beginning: ");
            scanf("%d", &data);
            insertAtBeginning(list, data);
            break;
        
        case 3:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the index to insert: ");
            scanf("%d", &index);
            insertAtIndex(list, index, data);
            break;

        case 4:
            printf("Enter the data to find: ");
            scanf("%d", &data);
            if (find(list, data))
                printf("Data found\n");
            else
                printf("Data not found\n");
            break;

        case 5:
            printf("Enter the index to retrieve data: ");
            scanf("%d", &index);
            data = retrieve(list, index);
            if (data != -1)
                printf("Data at index %d is %d\n", index, data);
            break;

        case 6:
            deleteLastItem(list);
            printf("Last item deleted\n");
            break;

        case 7:
            deleteFirstItem(list);
            printf("First item deleted\n");
            break;

        case 8:
            display(list);
            break;

        case 9:
            exit(0);

        default:
            printf("Invalid choice\n");
        }

        printf("\nCurrent list: ");
        display(list);
        printf("\n");
    }

    return 0;
}