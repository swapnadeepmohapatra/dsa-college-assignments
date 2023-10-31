// Linear Queue using linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = x;
    newnode->next = NULL;

    if (front == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    if (front == NULL)
        printf("\nQueue Underflow\n");
    else
    {
        struct Node *temp;
        temp = front;
        printf("\nDeleted : %d\n", front->info);
        front = front->next;
        free(temp);
    }
}

void peek()
{
    if (front == NULL)
        printf("\nQueue Underflow\n");
    else
        printf("\nFront : %d\n", front->info);
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
            printf("Enter number to be added : ");
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