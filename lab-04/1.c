#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void createList(struct Node **head)
{
    if (*head == NULL)
    {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0)
        {
            int data;
            struct Node *newnode;
            struct Node *temp;
            newnode = (struct Node *)malloc(sizeof(struct Node));
            (*head) = newnode;
            temp = (*head);
            printf("\nEnter number to be inserted : ");
            scanf("%d", &data);
            (*head)->info = data;

            for (int i = 2; i <= n; i++)
            {
                newnode = (struct Node *)malloc(sizeof(struct Node));
                temp->link = newnode;
                printf("\nEnter number to be inserted : ");
                scanf("%d", &data);
                newnode->info = data;
                temp = temp->link;
            }
            temp->link = *head; // Make it circular
        }
        printf("\nThe circular list is created\n");
    }
    else
        printf("\nThe circular list is already created\n");
}

void traverse(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
        printf("\nCircular List is empty\n");

    else
    {
        temp = head;
        do
        {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        } while (temp != head);
    }
}

void insertAtFront(struct Node **head)
{
    int data;
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    temp->info = data;

    temp->link = *head;
    struct Node *last = *head;
    while (last->link != *head)
        last = last->link;

    last->link = temp; // Update the last node's link
    *head = temp;      // Update the head
}

void insertAtEnd(struct Node **head)
{
    int data;
    struct Node *temp, *last;
    temp = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);

    temp->link = *head;
    temp->info = data;
    if (*head == NULL)
    {
        temp->link = temp; // Make it circular
        *head = temp;
    }
    else
    {
        last = *head;
        while (last->link != *head)
            last = last->link;

        last->link = temp; // Update the last node's link
    }
}

void insertAtPosition(struct Node **head)
{
    struct Node *temp, *newnode;
    int pos, data, i = 1;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);

    temp = *head;
    newnode->info = data;
    newnode->link = *head;
    if (pos == 1)
    {
        struct Node *last = *head;
        while (last->link != *head)
            last = last->link;

        newnode->link = *head;
        *head = newnode;
        last->link = newnode; // Update the last node's link
    }
    else
    {
        while (i < pos - 1)
        {
            temp = temp->link;
            i++;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
}

void deleteFirst(struct Node **head)
{
    struct Node *temp;
    if (*head == NULL)
        printf("\nCircular List is empty\n");
    else
    {
        temp = *head;
        struct Node *last = *head;
        while (last->link != *head)
            last = last->link;

        *head = temp->link;
        last->link = *head; // Update the last node's link
        free(temp);
    }
}

void deleteEnd(struct Node **head)
{
    struct Node *temp, *prevnode;
    if (*head == NULL)
        printf("\nCircular List is Empty\n");
    else
    {
        temp = *head;
        struct Node *last = *head;
        while (last->link != *head)
        {
            prevnode = last;
            last = last->link;
        }
        prevnode->link = *head; // Update the last node's link
        free(last);
    }
}

void deletePosition(struct Node **head)
{
    struct Node *temp, *position;
    int i = 1, pos;

    if (*head == NULL)
        printf("\nCircular List is empty\n");
    else
    {
        printf("\nEnter index : ");
        scanf("%d", &pos);
        position = (struct Node *)malloc(sizeof(struct Node));
        temp = *head;

        if (pos == 1)
        {
            struct Node *last = *head;
            while (last->link != *head)
                last = last->link;

            position = *head;
            *head = position->link;
            last->link = *head; // Update the last node's link
            free(position);
        }
        else
        {
            while (i < pos - 1)
            {
                temp = temp->link;
                i++;
            }
            position = temp->link;
            temp->link = position->link;
            free(position);
        }
    }
}

int main()
{
    int choice;

    struct Node *head = NULL;

    while (1)
    {
        printf("\n1. To see list\n");
        printf("2. For insertion at starting\n");
        printf("3. For insertion at end\n");
        printf("4. For insertion at any position\n");
        printf("5. For deletion of first element\n");
        printf("6. For deletion of last element\n");
        printf("7. For deletion of any position\n");
        printf("8. To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            traverse(head);
            break;
        case 2:
            insertAtFront(&head);
            break;
        case 3:
            insertAtEnd(&head);
            break;
        case 4:
            insertAtPosition(&head);
            break;
        case 5:
            deleteFirst(&head);
            break;
        case 6:
            deleteEnd(&head);
            break;
        case 7:
            deletePosition(&head);
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}
