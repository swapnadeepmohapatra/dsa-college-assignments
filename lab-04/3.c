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
        newNode->next = *head;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != *head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

int isPrime(int num)
{
    if (num <= 1)
        return 0;
    if (num <= 3)
        return 1;
    if (num % 2 == 0 || num % 3 == 0)
        return 0;
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

void displayPrimeFollowers(struct Node *head)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct Node *current = head;
    do
    {
        if (isPrime(current->data))
        {
            printf("%d, ", current->next->data);
        }
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the no of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL;

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Elements following prime value nodes: ");
    displayPrimeFollowers(head);

    return 0;
}
