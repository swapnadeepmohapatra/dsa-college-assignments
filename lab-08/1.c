// Linear Queue using Array
#include <stdio.h>

#define MAX 5

int queue[MAX];

int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == MAX - 1)
        printf("\nQueue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1)
        printf("\nQueue Underflow\n");
    else
    {
        printf("\nDeleted : %d\n", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void peek()
{
    if (front == -1)
        printf("\nQueue Underflow\n");
    else
        printf("\nFront : %d\n", queue[front]);
}

void main()
{
    int choice;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int n;
            printf("Enter number to be added");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
