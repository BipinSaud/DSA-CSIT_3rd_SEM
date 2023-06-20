#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

struct cqueue
{
    int item[SIZE];
    int rear, front;
};

typedef struct cqueue cqType;

void insertItem(cqType *);
void deleteItem(cqType *);
void display(cqType *);

int main()
{
    int ch;
    cqType q;
    q.rear = 0;
    q.front = 0;

    printf("\nMenu for Program:\n");
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
            printf("Invalid Choice\n");
            break;
        }
    } while (ch < 5);

    return 0;
}

void insertItem(cqType *q)
{
    int d;
    if ((q->rear + 1) % SIZE == q->front)
    {
        printf("Queue is full.\n");
    }
    else
    {
        q->rear = (q->rear + 1) % SIZE;
        printf("\nEnter data to be inserted: ");
        scanf("%d", &d);
        q->item[q->rear] = d;
    }
}

void deleteItem(cqType *q)
{
    if (q->rear == q->front)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        q->front = (q->front + 1) % SIZE;
        printf("Deleted Item is: %d\n", q->item[q->front]);
    }
}

void display(cqType *q)
{
    int i;

    if (q->rear == q->front)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Items of queue are:\n");

        for (i = (q->front + 1) % SIZE; i != q->rear; i = (i + 1) % SIZE)
        {
            printf("%d\t", q->item[i]);
        }
        printf("%d\n", q->item[q->rear]);
    }
}
