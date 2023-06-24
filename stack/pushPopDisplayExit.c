// 1.PUSH POP DISPLAY AND EXIT

#include <stdio.h>
#define MAX 100

typedef struct
{
    int items[MAX];
    int top;
} stack;

void push(stack *s, int element);
int pop(stack *s);
void display(stack *s);

int main()
{
    stack s;
    s.top = -1; // Initializing the top of the stack

    int element, choice;
    int flag = 1;

    do
    {
        printf("\n\n Enter your choice");
        printf("\n\n\t 1: Push the element");
        printf("\n\n\t 2: Pop the element");
        printf("\n\n\t 3: Display the elements");
        printf("\n\n\t 4: Exit");
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
            element = pop(&s);
            if (element != -1)
                printf("Popped element: %d\n", element);
            break;

        case 3:
            display(&s);
            break;

        case 4:
            flag = 0;
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

int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow! Cannot pop element.\n");
        return -1;
    }
    else
    {
        int element = s->items[s->top];
        s->top--;
        return element;
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
