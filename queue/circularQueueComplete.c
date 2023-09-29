// Including standard input/output library
#include <stdio.h>
// Including standard library
#include <stdlib.h>

// Defining the size of the queue
#define SIZE 20

// Defining a structure for circular queue
struct cqueue
{
    int item[SIZE];  // Array to store queue elements
    int rear, front; // Rear and front pointers
};

// Defining a type for circular queue
typedef struct cqueue cqType;

// Function to insert an element in the circular queue
void insertItem(cqType *);

// Function to delete an element from the circular queue
void deleteItem(cqType *);

// Function to display the elements of the circular queue
void display(cqType *);

// Main function
int main()
{
    int ch;
    cqType q;
    q.rear = 0;
    q.front = 0;

    // Displaying the menu for the program
    printf("\nMenu for Program:\n");
    printf("\n1: Insert\n2: Delete\n3: Display\n4: Exit\n");

    // Loop to execute the program until the user chooses to exit
    do
    {
        // Asking the user for their choice
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        // Switch case to perform the operation based on user's choice
        switch (ch)
        {
        case 1:
            insertItem(&q);
            break;

        case 2:
            deleteItem(&q);
            break;

        case 3:
            display(&q);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (ch < 5);

    return 0;
}

// Function to insert an element in the circular queue
void insertItem(cqType *q)
{
    int d;
    // Checking if the queue is full
    if ((q->rear + 1) % SIZE == q->front)
    {
        printf("Queue is full.\n");
    }
    else
    {
        // Incrementing the rear pointer and adding the element to the queue
        q->rear = (q->rear + 1) % SIZE;
        printf("\nEnter data to be inserted: ");
        scanf("%d", &d);
        q->item[q->rear] = d;
    }
}

// Function to delete an element from the circular queue
void deleteItem(cqType *q)
{
    // Checking if the queue is empty
    if (q->rear == q->front)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        // Incrementing the front pointer and deleting the element from the queue
        q->front = (q->front + 1) % SIZE;
        printf("Deleted Item is: %d\n", q->item[q->front]);
    }
}

// Function to display the elements of the circular queue
void display(cqType *q)
{
    int i;

    // Checking if the queue is empty
    if (q->rear == q->front)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        // Displaying the elements of the queue
        printf("Items of queue are:\n");

        for (i = (q->front + 1) % SIZE; i != q->rear; i = (i + 1) % SIZE)
        {
            printf("%d\t", q->item[i]);
        }
        printf("%d\n", q->item[q->rear]);
    }
}
