// Create a complete binary three with the following as node values.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *createNode(int x)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void preorder(struct Node *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->info);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(struct Node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->info);
        inorder(temp->right);
    }
}

void postorder(struct Node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->info);
    }
}

void main()
{
    insert(12);
    insert(56);
    insert(64);
    insert(9);
    insert(16);
    insert(20);
    insert(38);
    insert(34);
    insert(21);
    insert(26);

    preorder(root);
    inorder(root);
    postorder(root);
}