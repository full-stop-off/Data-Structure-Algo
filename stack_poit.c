#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define YES 1
#define NO 0

struct stack
{
    char data[MAX];
    int tos;
};

void push(struct stack *s, int number)
{
    if (s->tos == MAX - 1)
    {
        printf("Stack is full.");
    }
    else
    {
        s->tos++;
        s->data[s->tos] = number;
    }
}

int pop(struct stack *s)
{
    if (s->tos == -1)
    {
        printf("Stack is Empty.");
        exit(0);
    }
    else
    {
        return s->data[s->tos--];
    }
}

int main()
{
    char expression[MAX], symb;
    int i, value, op1, op2; // Operand == integer, Operator == Character
    struct stack s;
    s.tos = -1;
    printf("Enter your expression: ");
    gets(expression);
    for (i = 0; i < strlen(expression); i++)
    {
        symb = expression[i];
        if (symb > 64 && symb <= 90) // if operand
        {
            printf("[+] Enter the value of %c: ", symb);
            scanf("%d", &value);
            push(&s, value);
        }
        else
        {
            op2 = pop(&s); //  first stack on the top
            op1 = pop(&s); // second stack of the top
            switch (symb)
            {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '/':
                value = op1 / op2;
                break;
            }
            push(&s, value);
        }
    }
    printf("Value of Stack %d", pop(&s));
}