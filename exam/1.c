// Implement stack with peekHighestElement and peekLowestElement

#include <stdio.h>

#define MAX 10

int stack[MAX];
int minStack[MAX];
int maxStack[MAX];

int top = -1;

void push()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = data;
    if (top == 0)
    {
        minStack[top] = data;
        maxStack[top] = data;
    }
    else
    {
        if (data < minStack[top - 1])
        {
            minStack[top] = data;
        }
        else
        {
            minStack[top] = minStack[top - 1];
        }
        if (data > maxStack[top - 1])
        {
            maxStack[top] = data;
        }
        else
        {
            maxStack[top] = maxStack[top - 1];
        }
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    top--;
}

void peek()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("Peek element: %d\n", stack[top]);
}

void peekHighestElement()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("Highest element: %d\n", maxStack[top]);
}

void peekLowestElement()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("Lowest element: %d\n", minStack[top]);
}

void main()
{
    int choice;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Peek highest element\n");
        printf("5. Peek lowest element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            peekHighestElement();
            break;
        case 5:
            peekLowestElement();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
