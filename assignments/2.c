#include <stdio.h>

// Function to input a sparse matrix
void inputSparseMatrix(int matrix[][3], int *terms, int rows, int cols)
{
    *terms = 0;
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int element;
            scanf("%d", &element);
            if (element != 0)
            {
                matrix[*terms][0] = i;
                matrix[*terms][1] = j;
                matrix[*terms][2] = element;
                (*terms)++;
            }
        }
    }
}

// Function to multiply two sparse matrices
void multiplySparseMatrices(const int A[][3], int termsA, const int B[][3], int termsB, int C[][3], int *termsC, int rowsA, int rowsB, int colsA, int colsB)
{
    if (colsA != rowsB)
    {
        printf("Matrix multiplication is not possible. The number of columns in A must be equal to the number of rows in B.\n");
        *termsC = 0;
        return;
    }

    *termsC = 0;
    for (int i = 0; i < termsA; i++)
    {
        int rowA = A[i][0];
        int colA = A[i][1];
        int valueA = A[i][2];

        for (int j = 0; j < termsB; j++)
        {
            int rowB = B[j][0];
            int colB = B[j][1];
            int valueB = B[j][2];

            if (colA == rowB)
            {
                C[*termsC][0] = rowA;
                C[*termsC][1] = colB;
                C[*termsC][2] = valueA * valueB;
                (*termsC)++;
            }
        }
    }
}

// Function to print a sparse matrix
void printSparseMatrix(const int matrix[][3], int terms, int rows, int cols)
{
    printf("Sparse Matrix:\n");
    int currentTerm = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (currentTerm < terms && matrix[currentTerm][0] == i && matrix[currentTerm][1] == j)
            {
                printf("%d ", matrix[currentTerm][2]);
                currentTerm++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
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

    int maxTermsA = rowsA * colsA;
    int maxTermsB = rowsB * colsB;
    int maxTermsC = rowsA * colsB;

    int A[maxTermsA][3], B[maxTermsB][3], C[maxTermsC][3];
    int termsA, termsB, termsC;

    inputSparseMatrix(A, &termsA, rowsA, colsA);
    inputSparseMatrix(B, &termsB, rowsB, colsB);

    multiplySparseMatrices(A, termsA, B, termsB, C, &termsC, rowsA, rowsB, colsA, colsB);

    if (termsC > 0)
    {
        printSparseMatrix(C, termsC, rowsA, colsB);
    }
    else
    {
        printf("Matrix multiplication resulted in a zero matrix.\n");
    }

    return 0;
}
