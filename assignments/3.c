#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node
{
    int row, col, value;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int row, int col, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to input a sparse matrix as a linked list
struct Node *inputSparseMatrix(int rows, int cols)
{
    struct Node *head = NULL;
    printf("Enter the elements of the matrix (row, col, value):\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int element;
            scanf("%d", &element);
            if (element != 0)
            {
                struct Node *newNode = createNode(i, j, element);
                if (head == NULL)
                {
                    head = newNode;
                }
                else
                {
                    struct Node *current = head;
                    while (current->next != NULL)
                    {
                        current = current->next;
                    }
                    current->next = newNode;
                }
            }
        }
    }
    return head;
}

// Function to add two sparse matrices
struct Node *addSparseMatrices(struct Node *A, struct Node *B)
{
    struct Node *result = NULL;

    while (A != NULL && B != NULL)
    {
        if (A->row < B->row || (A->row == B->row && A->col < B->col))
        {
            struct Node *newNode = createNode(A->row, A->col, A->value);
            if (result == NULL)
            {
                result = newNode;
            }
            else
            {
                struct Node *current = result;
                while (current->next != NULL)
                {
                    current = current->next;
                }
                current->next = newNode;
            }
            A = A->next;
        }
        else if (A->row > B->row || (A->row == B->row && A->col > B->col))
        {
            struct Node *newNode = createNode(B->row, B->col, B->value);
            if (result == NULL)
            {
                result = newNode;
            }
            else
            {
                struct Node *current = result;
                while (current->next != NULL)
                {
                    current = current->next;
                }
                current->next = newNode;
            }
            B = B->next;
        }
        else
        {
            int newValue = A->value + B->value;
            if (newValue != 0)
            {
                struct Node *newNode = createNode(A->row, A->col, newValue);
                if (result == NULL)
                {
                    result = newNode;
                }
                else
                {
                    struct Node *current = result;
                    while (current->next != NULL)
                    {
                        current = current->next;
                    }
                    current->next = newNode;
                }
            }
            A = A->next;
            B = B->next;
        }
    }

    while (A != NULL)
    {
        struct Node *newNode = createNode(A->row, A->col, A->value);
        if (result == NULL)
        {
            result = newNode;
        }
        else
        {
            struct Node *current = result;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        A = A->next;
    }

    while (B != NULL)
    {
        struct Node *newNode = createNode(B->row, B->col, B->value);
        if (result == NULL)
        {
            result = newNode;
        }
        else
        {
            struct Node *current = result;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        B = B->next;
    }

    return result;
}

// Function to print a sparse matrix represented as a linked list
void printSparseMatrix(struct Node *head)
{
    printf("Sparse Matrix (row, col, value):\n");
    for (struct Node *current = head; current != NULL; current = current->next)
    {
        printf("%d %d %d\n", current->row, current->col, current->value);
    }
}

// Function to free the memory allocated for the linked list
void freeSparseMatrix(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    struct Node *matrixA = inputSparseMatrix(rows, cols);
    struct Node *matrixB = inputSparseMatrix(rows, cols);

    struct Node *result = addSparseMatrices(matrixA, matrixB);

    if (result != NULL)
    {
        printSparseMatrix(result);
        freeSparseMatrix(result);
    }
    else
    {
        printf("Matrix addition resulted in a zero matrix.\n");
    }

    freeSparseMatrix(matrixA);
    freeSparseMatrix(matrixB);

    return 0;
}
