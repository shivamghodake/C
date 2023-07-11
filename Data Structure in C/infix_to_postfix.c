#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100
int isOperator(char ch);
int precedence(char ch);
void infixToPostfix(char infix[], char postfix[]);
char stack[MAX_SIZE];
int top = -1;
int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}
int isOperator(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return 1;
    default:
        return 0;
    }
}
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
void infixToPostfix(char infix[], char postfix[])
{
    int i, j;
    char ch;
    postfix[0] = '\0';
    for (i = 0, j = -1; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        if (isalnum(ch))
        {
           postfix[++j] = ch;
        }
        else if (isOperator(ch))
        {         
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[++j] = stack[top--];
            } 
            stack[++top] = ch;
        }
        else if (ch == '(')
        {
            stack[++top] = ch;
        }
        else if (ch == ')')
        {   
            while (top != -1 && stack[top] != '(')
            {
                postfix[++j] = stack[top--];
            }
            if (top == -1)
            {
                printf("Error: Mismatched parentheses.\n");
                exit(1);
            }
            top--;
        }
    }
    while (top != -1)
    {
        if (stack[top] == '(')
        {
            printf("Error: Mismatched parentheses.\n");
            exit(1);
        }
        postfix[++j] = stack[top--];
    }
    postfix[++j] = '\0';
}