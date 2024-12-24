#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, k = 0;
    char c;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while ((c = pop()) != '(') {
                postfix[k++] = c;
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int evaluatePostfix(char* postfix, int values[]) {
    int stack[SIZE];
    int top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalpha(postfix[i])) {
            stack[++top] = values[postfix[i] - 'a'];
        } else {
            int op2 = stack[top--];
            int op1 = stack[top--];
            switch (postfix[i]) {
                case '+': stack[++top] = op1 + op2; break;
                case '-': stack[++top] = op1 - op2; break;
                case '*': stack[++top] = op1 * op2; break;
                case '/': stack[++top] = op1 / op2; break;
                case '^': stack[++top] = pow(op1, op2); break;
            }
        }
    }
    return stack[top];
}

int main() {
    char infix[] = "((a+b)^((c/d)*e))";
    char postfix[SIZE];
    int values[] = {2, 6, 3, 2, -2}; 

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix, values));
    return 0;
}
