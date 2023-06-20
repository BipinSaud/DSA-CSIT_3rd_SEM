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
void display(queueType *);
int isFull(queueType *);
int isEmpty(queueType *);

int main()
{
    int ch;
    queueType q;
    q.rear = -1;
    q.front = 0;

    printf("\nMenu for program:");
    printf("\n1: Insert\n2: Display\n3: Exit\n");

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
            display(&q);
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Your choice is wrong\n");
            break;
        }
    } while (ch != 3);

    return 0;
}

/* Insert item or enqueue function */
void insertItem(queueType *q)
{
    int d;
    printf("\nEnter data to be inserted: ");
    scanf("%d", &d);

    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }

    q->rear++;
    q->item[q->rear] = d;
}

/* Display the elements of the queue */
void display(queueType *q)
{
    int i;

    if (isEmpty(q))
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

int isFull(queueType *q)
{
    if (q->rear == SIZE - 1)
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty(queueType *q)
{
    if (q->front > q->rear)
    {
        return 1;
    }
    else
        return 0;
}
