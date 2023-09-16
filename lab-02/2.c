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
            if (matrix[i][j] != 0)
            {
                validInputs++;
            }
        }
    }

    int triplet[3][validInputs + 1];

    triplet[0][0] = rows;
    triplet[1][0] = cols;
    triplet[2][0] = validInputs;

    printf("%d valid inputs\n", validInputs);

    printf("sparse matrix in 3-tuple format");
    for (int i = 0; i < validInputs + 1; i++)
    {
        printf("%d %d %d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
        //        printf("%d %d %d\n", triplet[0][i], triplet[1][i], triplet[2][i]);
    }

    //    int count = 1;
    //
    //    for (int i = 0; i < rows; i++)
    //    {
    //        for (int j = 0; j < cols; j++)
    //        {
    //            if (matrix[i][j] != 0)
    //            {
    //                triplet[0][count] = i;
    //                triplet[1][count] = j;
    //                triplet[2][count] = matrix[i][j];
    //                count ++;
    //            }
    //        }
    //    }
    //
    //    printf("sparse matrix in 3-tuple format");
    //    for (int i = 0; i < validInputs + 1; i++)
    //    {
    //        printf("%d %d %d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    ////        printf("%d %d %d\n", triplet[0][i], triplet[1][i], triplet[2][i]);
    //    }

    return 0;
}