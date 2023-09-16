#include <stdio.h>
#include <stdlib.h>

void polynomialAdd(int poly1[], int poly2[], int res[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        res[i] = poly1[i] + poly2[i];
    }
}

void polynomialMultiply(int poly1[], int poly2[], int res[], int n)
{
    for (int i = 0; i <= 2 * n; i++)
    {
        res[i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            res[i + j] += poly1[i] * poly2[j];
        }
    }
}

void printPolynomial(int poly[], int n)
{
    for (int i = n; i >= 0; i--)
    {
        if (poly[i] != 0)
        {
            printf("%d", poly[i]);
            if (i > 1)
            {
                printf("x^%d", i);
            }
            if (i != 0 && i != 1)
            {
                printf(" + ");
            }
            else if (i == 1)
            {
                printf("x + ");
            }
        }
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the degree of both the polynomials: ");
    scanf("%d", &n);

    int *poly1 = (int *)malloc((n + 1) * sizeof(int));
    int *poly2 = (int *)malloc((n + 1) * sizeof(int));
    int *addResult = (int *)malloc((n + 1) * sizeof(int));
    int *multiplyResult = (int *)malloc((2 * n + 1) * sizeof(int));

    printf("Enter coefficients of first polynomial: ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &poly1[n - i]);
    }

    printf("Enter coefficients of second polynomial: ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &poly2[n - i]);
    }

    polynomialAdd(poly1, poly2, addResult, n);
    polynomialMultiply(poly1, poly2, multiplyResult, n);

    printf("Sum of the polynomials: ");
    printPolynomial(addResult, n);

    printf("Product of the polynomials: ");
    printPolynomial(multiplyResult, 2 * n);

    free(poly1);
    free(poly2);
    free(addResult);
    free(multiplyResult);

    return 0;
}