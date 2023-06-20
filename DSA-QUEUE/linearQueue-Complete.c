#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct queue
{
    int item[SIZE];
    int rear;
    int front;
};

typedef struct queue queueType;

void insertItem(queueType *);
void deleteItem(queueType *);
void display(queueType *);

int main()
{
    int ch;
    queueType q;
    q.rear = -1;
    q.front = 0;

    printf("\nMenu for program:");
    printf("\n1: Insert\n2: Delete\n3: Display\n4: Exit\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

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
            printf("Your choice is wrong\n");
            break;
        }
    } while (ch < 5);

    return 0;
}

/* Insert item or enqueue function */
void insertItem(queueType *q)
{
    int d;
    printf("\nEnter data to be inserted: ");
    scanf("%d", &d);

    if (q->rear == SIZE - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->item[q->rear] = d;
    }
}

/* Delete item or dequeue function */
void deleteItem(queueType *q)
{
    int i;

    if (q->front > q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted item is: %d\n", q->item[q->front]);

        for (i = q->front; i < q->rear; i++)
        {
            q->item[i] = q->item[i + 1];
        }

        q->rear--;
    }
}

/* Display the elements of the queue */
void display(queueType *q)
{
    int i;

    if (q->front > q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->item[i]);
        }
        printf("\n");
    }
}
