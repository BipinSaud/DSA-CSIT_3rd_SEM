// Pop Display and Exit
#include <stdio.h>
#define MAX 100

typedef struct
{
    int items[MAX];
    int top;
} stack;

void pop(stack *s);
void display(stack *s);

int main()
{
    stack s;
    s.top = -1; // Initializing the top of the stack

    int choice;
    int flag = 1;

    do
    {
        printf("\n\n Enter your choice");
        printf("\n\n\t 1: Pop the element");
        printf("\n\n\t 2: Exit");
        printf("\n\n\n Enter your choice:\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            pop(&s);
            break;
        case 2:
            flag = 0;
            break;
        default:
            printf("Enter a valid choice.\n");
        }
    } while (flag);

    return 0;
}

void pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow! Cannot pop element.\n");
        return;
    }
    else
    {
        s->top--;
    }
}
