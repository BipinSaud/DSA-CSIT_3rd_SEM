// 2.PUSH DISPLAY AND EXIT

#include <stdio.h>
#define MAX 100

typedef struct
{
    int items[MAX];
    int top;
} stack;

void push(stack *s, int element);
void display(stack *s);

int main()
{
    stack s;
    s.top = -1;

    int element, choice;
    int flag = 1;

    do
    {
        printf("\n\n\t 1: Push the element");
        printf("\n\n\t 2: Display the elements");
        printf("\n\n\n Enter your choice:\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number: ");
            scanf("%d", &element);
            push(&s, element);
            break;

        case 2:
            display(&s);
            break;
        default:
            printf("Enter a valid choice.\n");
        }
    } while (flag);

    return 0;
}

void push(stack *s, int element)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push element.\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = element;
        printf("Element %d pushed successfully.\n", element);
    }
}

void display(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Elements in the stack are: ");
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}
