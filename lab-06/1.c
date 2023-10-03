// WAP to implement Stack using array

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Size of the stack

int stack[MAX];

int top = -1;

void push(int data)
{
    if (top == MAX - 1)
        printf("\nStack Overflow\n");
    else
    {
        top++;
        stack[top] = data;
    }
}

int pop()
{
    if (top == -1)
        printf("\nStack Underflow\n");
    else
    {
        int data = stack[top];
        top--;
        printf("\nData popped is %d\n", data);
        return data;
    }
}

int peek()
{
    if (top == -1)
        printf("\nStack Underflow\n");
    else
    {
        printf("\nData at top is %d\n", stack[top]);
        return stack[top];
    }
}

void traverse()
{
    if (top == -1)
        printf("\nStack is empty\n");
    else
    {
        printf("\nStack elements are:\n");
        int arr[MAX];
        int i = 0;

        while (top >= 0)
        {
            arr[i] = pop();
            printf("%d", arr[i]);
            i++;
        }

        while (i >= 0)
        {
            push(arr[i]);
            i--;
        }
    }
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter data to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            traverse();
            break;

        case 5:
            exit(1);
            break;

        default:
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}