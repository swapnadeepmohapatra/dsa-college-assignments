// WAP to display the elements in the main diagonal, the diagonal above and below the main diagonal of a matrix.

#include <stdio.h>

int main()
{
    int rows;
    printf("Enter the number of rows and columns: ");
    scanf("%d", &rows);

    int matrix[rows][rows];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("\n Enter the element at position (%d, %d):", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Main diagonal: ");
    for (int i = 0; i < rows; i++)
    {
        printf("%d ", matrix[i][i]);
    }

    printf("\nDiagonal above the main diagonal: ");
    for (int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j < rows; j++)
        {
            printf("%d ", matrix[i][j]);
        }
    }

    printf("\nDiagonal below the main diagonal: ");
    for (int i = 1; i < rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ", matrix[i][j]);
        }
    }

    return 0;
}