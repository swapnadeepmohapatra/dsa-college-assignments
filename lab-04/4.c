#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void sort(struct Node **list1, struct Node **list2, struct Node **result)
{
    struct Node *current1 = *list1;
    struct Node *current2 = *list2;

    while (current1 != NULL && current2 != NULL)
    {
        if (current1->data < current2->data)
        {
            append(result, current1->data);
            current1 = current1->next;
        }
        else
        {
            append(result, current2->data);
            current2 = current2->next;
        }
    }

    while (current1 != NULL)
    {
        append(result, current1->data);
        current1 = current1->next;
    }

    while (current2 != NULL)
    {
        append(result, current2->data);
        current2 = current2->next;
    }
}

void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(", ");
        }
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int n1, n2;

    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    struct Node *result = NULL;

    printf("Enter the no of nodes in list 1: ");
    scanf("%d", &n1);

    printf("Enter the elements for list 1: ");
    for (int i = 0; i < n1; i++)
    {
        int data;
        scanf("%d", &data);
        append(&list1, data);
    }

    printf("Enter the no of nodes in list 2: ");
    scanf("%d", &n2);

    printf("Enter the elements for list 2: ");
    for (int i = 0; i < n2; i++)
    {
        int data;
        scanf("%d", &data);
        append(&list2, data);
    }

    sort(&list1, &list2, &result);

    printf("Merged and sorted list: ");
    display(result);

    return 0;
}
