#include <stdio.h>

int main()
{
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    int validInputs = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][i] != 0)
            {
                validInputs++;
            }
        }
    }

    int triplet[3][validInputs + 1];

    triplet[0][0] = rows;
    triplet[1][0] = cols;
    triplet[2][0] = validInputs;

    printf("sparse matrix in 3-tuple format");
    for (int i = 0; i < validInputs + 1; i++)
    {
        printf("%d %d %d\n", triplet[0][i], triplet[1][i], triplet[2][i]);
    }

    return 0;
}