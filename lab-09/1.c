// Write a menu driven program to implement Deques (double ended queue) (both Inputrestricted and output-restricted) and performed operations such as Enqueue, Dequeue, Peek, IsEmpty, IsFull using static array.

#include <stdio.h>

#define MAX 5

int queue[MAX];

int front = -1;
int rear = -1;

void enqueue_front(int x)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\nQueue Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = MAX - 1;
        }
        else
        {
            front--;
        }
        queue[front] = x;
    }
}

void enqueue_rear(int x)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\nQueue Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == MAX - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = x;
    }
}

void dequeue_front()
{
    if (front == -1)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        printf("\nDeleted : %d\n", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

void dequeue_rear()
{
    if (front == -1)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        printf("\nDeleted : %d\n", queue[rear]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = MAX - 1;
        }
        else
        {
            rear--;
        }
    }
}

void peek()
{
    if (front == -1)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        printf("\nFront : %d\n", queue[front]);
    }
}

void main()
{
    int choice;

    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Peek\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int n;
            printf("Enter number to be added");
            scanf("%d", &n);
            enqueue_front(n);
            break;
        case 2:
            printf("Enter number to be added");
            scanf("%d", &n);
            enqueue_rear(n);
            break;
        case 3:
            dequeue_front();
            break;
        case 4:
            dequeue_rear();
            break;
        case 5:
            peek();
            break;
        case 6:
            exit(0);
        default:
            printf("\nInvalid Choice\n");
        }
    }
}
