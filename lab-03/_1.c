#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void createList(struct node *head)
{
    if (head == NULL)
    {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0)
        {
            int data;
            struct node *newnode;
            struct node *temp;
            newnode = malloc(sizeof(struct node));
            head = newnode;
            temp = head;
            printf("\nEnter number to"
                   " be inserted : ");
            scanf("%d", &data);
            head->info = data;

            for (int i = 2; i <= n; i++)
            {
                newnode = malloc(sizeof(struct node));
                temp->link = newnode;
                printf("\nEnter number to"
                       " be inserted : ");
                scanf("%d", &data);
                newnode->info = data;
                temp = temp->link;
            }
        }
        printf("\nThe list is created\n");
    }
    else
        printf("\nThe list is already created\n");
}

void traverse(struct node *head)
{
    struct node *temp;

    if (head == NULL)
        printf("\nList is empty\n");

    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        }
    }
}

void insertAtFront(struct node *head)
{
    int data;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
    temp->info = data;

    temp->link = head;
    head = temp;
}

void insertAtEnd(struct node *head)
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));

    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);

    temp->link = 0;
    temp->info = data;
    head = head;
    while (head->link != NULL)
    {
        head = head->link;
    }
    head->link = temp;
}

void insertAtPosition(struct node *head)
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));

    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);

    temp = head;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void deleteFirst(struct node *head)
{
    struct node *temp;
    if (head == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = head;
        head = head->link;
        free(temp);
    }
}

void deleteEnd(struct node *head)
{
    struct node *temp, *prevnode;
    if (head == NULL)
        printf("\nList is Empty\n");
    else
    {
        temp = head;
        while (temp->link != 0)
        {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}

void deletePosition(struct node *head)
{
    struct node *temp, *position;
    int i = 1, pos;

    if (head == NULL)
        printf("\nList is empty\n");

    else
    {
        printf("\nEnter index : ");

        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = head;

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

int main()
{
    int choice;

    struct node *head = NULL;

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
            insertAtFront(head);
            break;
        case 3:
            insertAtEnd(head);
            break;
        case 4:
            insertAtPosition(head);
            break;
        case 5:
            deleteFirst(head);
            break;
        case 6:
            deleteEnd(head);
            break;
        case 7:
            deletePosition(head);
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
