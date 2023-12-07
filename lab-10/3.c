// Create a complete binary three with the following as node values and do search an element in the tree.

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

// void search(int x)
// {
//     struct Node *curr;
//     curr = root;

//     int isLeft = 0;
//     int level = 1;

//     while (curr != NULL)
//     {
//         if (x == curr->info)
//         {
//             printf("\nFound\n");
//             return;
//         }
//     }
//     printf("\nNot Found\n");
// }

void search(struct Node *root, int x)
{
    if (root != NULL)
    {
        search(root->left, x);
        if (root->info == x)
        {
            printf("%d ", root->info);
        }
        search(root->right, x);
    }
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

    search(root, 9);
}