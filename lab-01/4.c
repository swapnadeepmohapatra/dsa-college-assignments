// Write a menu driven program to create a structure to represent complex number and perform the following operation using function :

#include <stdio.h>

struct Complex
{
    float real;
    float imaginary;
};

void addComplex(struct Complex num1, struct Complex num2)
{
    struct Complex sum;
    sum.real = num1.real + num2.real;
    sum.imaginary = num1.imaginary + num2.imaginary;
    printf("Sum=%.2f+%.2fi\n", sum.real, sum.imaginary);
}

void multiplyComplex(struct Complex *num1, struct Complex *num2)
{
    struct Complex product;
    product.real = (num1->real * num2->real) - (num1->imaginary * num2->imaginary);
    product.imaginary = (num1->real * num2->imaginary) + (num1->imaginary * num2->real);
    printf("Product=%.2f+%.2fi\n", product.real, product.imaginary);
}

int main()
{
    struct Complex num1, num2;
    int choice;
    printf("Enter complex number 1: ");
    scanf("%f %f", &num1.real, &num1.imaginary);
    printf("Enter complex number 2: ");
    scanf("%f %f", &num2.real, &num2.imaginary);
    printf("\nMENU\n");
    printf("1. addition\n");
    printf("2. multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        addComplex(num1, num2);
    }
    else if (choice == 2)
    {
        multiplyComplex(&num1, &num2);
    }
    else
    {
        printf("Invalid choice\n");
    }
    return 0;
}