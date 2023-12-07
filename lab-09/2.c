// Write a menu driven program to implement priority queue operations such as Enqueue, Dequeue, Traverse using linked list.

#include <stdio.h>

struct Node
{
    int info;
    int priority;
    struct Node *next;
};

struct Node *front = NULL;

void enqueue(int x, int p)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = x;
    newnode->priority = p;
    newnode->next = NULL;

    if (front == NULL)
    {
        front = newnode;
    }
    else
    {
        if (p < front->priority)
        {
            newnode->next = front;
            front = newnode;
        }
        else
        {
            struct Node *temp = front;
            while (temp->next != NULL && temp->next->priority <= p)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue Underflow\n");
    }
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
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        printf("\nFront : %d\n", front->info);
    }
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
            int n, p;
            printf("Enter number to be added");
            scanf("%d", &n);
            printf("Enter priority");
            scanf("%d", &p);
            enqueue(n, p);
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
            printf("Invalid choice");
        }
    }
}