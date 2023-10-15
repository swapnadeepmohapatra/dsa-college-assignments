// WAP to create a stack using linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->data = data;
    new->next = NULL;

    if (top == NULL)
    {
        top = new;
    }
    else
    {
        new->next = top;
        // top->next = new;
        top = new;
    }
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *temp = top;
        int data = temp->data;
        top = top->next;
        free(temp);
        printf("\nData popped is %d\n", data);
    }
}

int peek()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("\nData at top is %d\n", top->data);
        return top->data;
    }
}

void traverse()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("\nStack elements are:\n");
        struct Node *temp = top;

        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
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