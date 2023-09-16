#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};

void insertNodeAtEnd(struct Node *head, int k)
{

    if (head == NULL)
    {
        printf("not found");
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->info = k;
        newNode->next = NULL;
        head = newNode;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = k;
    newNode->next = NULL;

    temp->next = newNode;
}

void traverse(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d, ", temp->info);
            temp = temp->next;
        }
    }
}

void insertAtEnd(struct Node *head)
{
    struct Node *temp = head;

    int data;
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->next = NULL;

    temp->next = newNode;
}

void insertAtStart(struct Node *head)
{
    struct Node *temp = head;

    int data;
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->next = head;

    head = &newNode;
}

void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->info = 0;
    head->next = NULL;

    insertAtStart(head);
    insertAtEnd(head);
    insertAtStart(head);

    traverse(head);
}
