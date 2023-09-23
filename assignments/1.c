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

// Function to add two sparse matrices
void addSparseMatrices(const int A[][3], int termsA, const int B[][3], int termsB, int C[][3], int *termsC)
{
    int i = 0, j = 0, k = 0;
    while (i < termsA && j < termsB)
    {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1]))
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++;
        }
        else if (A[i][0] > B[j][0] || (A[i][0] == B[j][0] && A[i][1] > B[j][1]))
        {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++;
        }
        else
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i < termsA)
    {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++;
        k++;
    }

    while (j < termsB)
    {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++;
        k++;
    }

    *termsC = k;
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int maxTerms = rows * cols;
    int A[maxTerms][3], B[maxTerms][3], C[maxTerms][3];
    int termsA, termsB, termsC;

    inputSparseMatrix(A, &termsA, rows, cols);
    inputSparseMatrix(B, &termsB, rows, cols);

    addSparseMatrices(A, termsA, B, termsB, C, &termsC);

    printSparseMatrix(C, termsC, rows, cols);

    return 0;
}
