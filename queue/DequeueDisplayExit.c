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

void deleteItem(queueType *);
void display(queueType *);
int isEmpty(queueType *);

int main()
{
    int ch;
    queueType q;
    q.rear = 2;
    q.front = 0;
    q.item[0] = 1;
    q.item[1] = 2;
    q.item[2] = 3;

    printf("\nMenu for program:");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            deleteItem(&q);
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

/* Delete item or dequeue function */
void deleteItem(queueType *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted item is: %d\n", q->item[q->front]);

    for (int i = q->front; i < q->rear; i++)
    {
        q->item[i] = q->item[i + 1];
    }

    q->rear--;
}

/* Display the elements of the queue */
void display(queueType *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->item[i]);
    }
    printf("\n");
}

int isEmpty(queueType *q)
{
    if (q->front > q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
