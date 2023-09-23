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

// Function to multiply two sparse matrices
struct Node *multiplySparseMatrices(struct Node *A, int rowsA, int colsA, struct Node *B, int rowsB, int colsB)
{
    if (colsA != rowsB)
    {
        printf("Matrix multiplication is not possible. The number of columns in A must be equal to the number of rows in B.\n");
        return NULL;
    }

    struct Node *result = NULL;

    for (struct Node *nodeA = A; nodeA != NULL; nodeA = nodeA->next)
    {
        int rowA = nodeA->row;
        int colA = nodeA->col;
        int valueA = nodeA->value;

        for (struct Node *nodeB = B; nodeB != NULL; nodeB = nodeB->next)
        {
            int rowB = nodeB->row;
            int colB = nodeB->col;
            int valueB = nodeB->value;

            if (colA == rowB)
            {
                int newValue = valueA * valueB;
                result = createNode(rowA, colB, newValue);
            }
        }
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
    int rowsA, colsA, rowsB, colsB;
    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &rowsA);
    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &colsA);
    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &rowsB);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &colsB);

    if (colsA != rowsB)
    {
        printf("Matrix multiplication is not possible. The number of columns in A must be equal to the number of rows in B.\n");
        return 1;
    }

    struct Node *matrixA = inputSparseMatrix(rowsA, colsA);
    struct Node *matrixB = inputSparseMatrix(rowsB, colsB);

    struct Node *result = multiplySparseMatrices(matrixA, rowsA, colsA, matrixB, rowsB, colsB);

    if (result != NULL)
    {
        printSparseMatrix(result);
        freeSparseMatrix(result);
    }
    else
    {
        printf("Matrix multiplication resulted in a zero matrix.\n");
    }

    freeSparseMatrix(matrixA);
    freeSparseMatrix(matrixB);

    return 0;
}
