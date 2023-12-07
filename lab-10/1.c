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

void main()
{
    struct Node *root = createNode(12);
    root->left = createNode(56);
    root->right = createNode(64);
    root->left->left = createNode(9);
    root->left->right = createNode(16);
    root->right->left = createNode(20);
    root->right->right = createNode(38);
    root->left->left->left = createNode(34);
    root->left->left->right = createNode(21);
    root->left->right->left = createNode(26);
}