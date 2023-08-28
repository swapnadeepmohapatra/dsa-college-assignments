// Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of all the prime elements of the array using function and de-allocate the memory of the array after its use.

#include <stdio.h>
#include <stdlib.h>

int isPrime(int num)
{
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int sumOfPrimes(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (isPrime(arr[i]))
        {
            sum += arr[i];
        }
    }
    return sum;
}

int main()
{
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    int sum = sumOfPrimes(array, size);
    printf("Sum = %d\n", sum);
    free(array);
    return 0;
}