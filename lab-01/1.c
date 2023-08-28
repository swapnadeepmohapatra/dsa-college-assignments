// Write a program to read two numbers and compare the numbers using function call by value and call by address.

#include <stdio.h>

void compareByValue(int a, int b)
{
    if (a < b)
        printf("%d is smaller than %d\n", a, b);
    else if (a > b)
        printf("%d is smaller than %d\n", b, a);
    else
        printf("Both numbers are equal\n");
}

void compareByAddress(int *a, int *b)
{
    if (*a < *b)
        printf("%d is smaller than %d\n", *a, *b);
    else if (*a > *b)
        printf("%d is smaller than %d\n", *b, *a);
    else
        printf("Both numbers are equal\n");
}

int main()
{
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    compareByValue(num1, num2);
    compareByAddress(&num1, &num2);
    return 0;
}
