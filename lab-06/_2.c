// WAP to merge two single linked list.

// Input – 1stlist
// :  2 3 4 6 7

// Input – 2ndlist
// :  12 15 20 45

// Output : 2
// 12 3 15 4 20 6 45 7

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

void merge(struct Node **head1, struct Node **head2)
{
    struct Node *temp1 = *head1;
    struct Node *temp2 = *head2;
    struct Node *temp3 = NULL;

    while (temp1 != NULL && temp2 != NULL)
    {
        temp3 = temp1->next;
        temp1->next = temp2;
        temp1 = temp3;
        temp3 = temp2->next;
        temp2->next = temp1;
        temp2 = temp3;
    }
    *head2 = temp2;
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    createList(&head1);
    createList(&head2);

    printf("\nList 1:\n");
    traverse(head1);
    printf("\nList 2:\n");
    traverse(head2);

    merge(&head1, &head2);

    printf("\nMerged List:\n");
    traverse(head1);

    return 0;
}