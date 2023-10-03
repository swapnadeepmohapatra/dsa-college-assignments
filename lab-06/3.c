// WAP to display a single linked list in such a way that all even number followed by odd number.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
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
            struct Node *newnode, *temp;
            newnode = malloc(sizeof(struct Node));
            (*head) = newnode;
            temp = (*head);
            printf("\nEnter number to be inserted: ");
            scanf("%d", &data);
            newnode->data = data;

            for (int i = 2; i <= n; i++)
            {
                newnode = malloc(sizeof(struct Node));
                temp->next = newnode;
                printf("\nEnter number to be inserted: ");
                scanf("%d", &data);
                newnode->data = data;
                temp = newnode;
            }
            temp->next = NULL;
        }
        printf("\nThe list is created\n");
    }
    else
    {
        printf("\nThe list is already created\n");
    }
}

void traverse(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;
        }
    }
}

void evenOdd(struct Node **head)
{
    struct Node *temp = *head;
    struct Node *even = NULL;
    struct Node *odd = NULL;
    struct Node *evenStart = NULL;
    struct Node *oddStart = NULL;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (even == NULL)
            {
                even = temp;
                evenStart = even;
            }
            else
            {
                even->next = temp;
                even = even->next;
            }
        }
        else
        {
            if (odd == NULL)
            {
                odd = temp;
                oddStart = odd;
            }
            else
            {
                odd->next = temp;
                odd = odd->next;
            }
        }
        temp = temp->next;
    }

    if (even == NULL || odd == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        even->next = oddStart;
        odd->next = NULL;
        *head = evenStart;
    }
}

int main()
{
    struct Node *head = NULL;
    int choice;

    while (1)
    {
        printf("\n1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Even Odd\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createList(&head);
            break;

        case 2:
            traverse(head);
            break;

        case 3:
            evenOdd(&head);
            traverse(head);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
    return 0;
}