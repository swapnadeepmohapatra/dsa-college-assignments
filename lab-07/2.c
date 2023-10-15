// WAP to convert an infix expression(each operand of one digit) into post fix expression with the help of explicit stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

char stack[MAX];
int top = -1;

void push(char data)
{
    if (top == MAX - 1)
        printf("\nStack Overflow\n");
    else
    {
        top++;
        stack[top] = data;
    }
}

char pop()
{
    if (top == -1)
        printf("\nStack Underflow\n");
    else
    {
        char data = stack[top];
        top--;
        return data;
    }
}

char peek()
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
    char postfix[MAX];

    int i = 0, j = 0;

    printf("\nPostfix expression is: %s\n", postfix);

    while (exp[i])
    {
        printf("%c", exp[i]);
        if (isOperand(exp[i]))
        {
            postfix[j] = exp[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(exp[i]) > precedence(peek()))
            {
                push(exp[i]);
                i++;
            }
            else
            {
                postfix[j] = pop();
                j++;
            }
        }
    }

    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("\nPostfix expression is: %s\n", postfix);
}

int main()
{
    char exp[MAX];

    printf("\nEnter the infix expression: ");
    scanf("%s", exp);

    infixToPostfix(exp);

    return 0;
}