#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void display(Node *head)
{
    Node *current = head;
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

void reverse(Node **head)
{
    Node *prev = NULL;
    Node *current = *head;
    Node *nextNode = NULL;
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    *head = prev;
}

int main()
{
    int n;
    printf("Enter the no of nodes: ");
    scanf("%d", &n);

    Node *head = NULL;

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Original Linked List: ");
    display(head);

    reverse(&head);

    printf("Reversed Linked List: ");
    display(head);

    return 0;
}
