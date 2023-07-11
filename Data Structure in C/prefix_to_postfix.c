#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX][MAX];
int top = -1;
void push(char str[]) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    strcpy(stack[top], str);
}
void pop(char str[]) {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    strcpy(str, stack[top]);
    top--;
}
int isOperator(char ch) {
    switch(ch) {
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
void prefixToPostfix(char prefix[]) {
    char ch, str[MAX];
    int i, j, len = strlen(prefix);

    for (i = len - 1; i >= 0; i--) {
        ch = prefix[i];
        if (isOperator(ch)) {
            pop(str);
            char str2[MAX];
            pop(str2);
            char temp[MAX];
            sprintf(temp, "%s%s%c", str, str2, ch);
            push(temp);
        }
        else {
            char temp[MAX];
            sprintf(temp, "%c", ch);
            push(temp);
        }
    }
    printf("%s\n", stack[top]);
}
int main() {
    char prefix[MAX];
    printf("");
    scanf("%s", prefix);
    prefixToPostfix(prefix);
    return 0;
}