// WAP to evaluate an postfix expression with the help of explicit stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int stack[MAX];

int top = -1;

void push(int data)
{
    if (top == MAX - 1)
        printf("\nStack Overflow\n");
    else
    {
        top++;
        stack[top] = data;
    }
}

int pop()
{
    if (top == -1)
        printf("\nStack Underflow\n");
    else
    {
        int data = stack[top];
        top--;
        return data;
    }
}

int peek()
{
    if (top == -1)
        printf("\nStack Underflow\n");
    else
    {
        return stack[top];
    }
}

int isOperand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1; // True
    else
        return 0; // False
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char *exp)
{
    char *e, x;
    e = exp;

    while (*e != '\0')
    {
        if (isOperand(*e))
        {
            printf("%c", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (precedence(stack[top]) >= precedence(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }

    while (top != -1)
    {
        printf("%c", pop());
    }
}

int main()
{
    char exp[MAX];

    printf("\nEnter an infix expression: ");
    scanf("%s", exp);

    printf("\nPostfix expression is: ");
    infixToPostfix(exp);

    return 0;
}
