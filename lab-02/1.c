#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coefficient;
    int exponent;
    struct Node *next;
} Node;

Node *createNode(int coef, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coefficient = coef;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int coef, int exp)
{
    Node *newNode = createNode(coef, exp);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

Node *addPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;

    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exponent > poly2->exponent)
        {
            insertNode(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            insertNode(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
        else
        {
            insertNode(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL)
    {
        insertNode(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        insertNode(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

Node *multiplyPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;

    while (poly1 != NULL)
    {
        Node *temp = poly2;
        while (temp != NULL)
        {
            int coef = poly1->coefficient * temp->coefficient;
            int exp = poly1->exponent + temp->exponent;
            insertNode(&result, coef, exp);
            temp = temp->next;
        }
        poly1 = poly1->next;
    }

    return result;
}

void printPolynomial(Node *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL)
        {
            printf("+ ");
        }
    }
    printf("\n");
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;

    int n1, n2;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        int coef, exp;
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%d", &coef);
        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &exp);
        insertNode(&poly1, coef, exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        int coef, exp;
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%d", &coef);
        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &exp);
        insertNode(&poly2, coef, exp);
    }

    Node *addResult = addPolynomials(poly1, poly2);
    Node *multiplyResult = multiplyPolynomials(poly1, poly2);

    printf("Addition: ");
    printPolynomial(addResult);

    printf("Multiplication: ");
    printPolynomial(multiplyResult);

    return 0;
}