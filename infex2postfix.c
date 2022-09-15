// converting strings into postfix using stack
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 100
#define YES 1
#define NO 0

// CREATING STACK ::
struct stack
{
    char item[MAX];
    int tos;
};

// PUSH METHOD ::
void push(struct stack *s, char c)
{
    if (s->tos == MAX - 1)
    {
        printf("Stack Full");
            exit(0);
    }
    s->item[++s->tos] = c;
}

// POP METHOD ::
char pop(struct stack *s)
{
    if (s->tos == -1)
    {
        printf("Stack Empty");
        exit(0);
    }
    return s->item[s->tos--];
}

int precedence(char op)
{
    switch (op)
    {
    case '+':;

    case '-':
        return 1;

    case '$':
        return 3;

    case '*':;

    case '/':;

    case '%':
        return 2;

    default:
        return 0;
    }
}

// PEAK METHOD ::
char peak(struct stack s)
{
    if (s.tos == -1)
    {
        printf("Stack Empty");
        exit(0);
    }
    return s.item[s.tos];
}

void display(struct stack s)
{
	int i;
    printf("Stack Contians: \n");
    for (int i = 0; i <= s.tos ; i++)
    {
        printf("%c", s.item[i]);
    }
}

void main()
{
    char infix[MAX], symb;
    struct stack postStack, opStack;

    postStack.tos = -1; // empty stack
    opStack.tos = -1;
    printf("ENTER YOUR INFIX EXPRESSION:    ");

    gets(infix);
    for (int i = 0; i < strlen(infix); i++)
    {
        symb = infix[i];
        if (isalpha(symb)) // if operand
        {
            push(&postStack, symb);
        }
        else if (symb == '(')
        {
            push(&opStack, symb);
        }
        else if (symb == '}')
        {
            while (peek(&opStack) != '(')
            {
                // pop all opeartors and push tointo poststack until ( is encouter
                push(&postStack, pop(&opStack));
            }
            pop(&opStack); // remove ()
        }
        else // operator
        {
            while (opStack.tos != -1 && precedence(symb) < recendence(peek(opStack)))
            {
                push(&postStack, pop(&opStack)); // remove all high priority operators and pushinto post stack
            }
            push(&opStack, symb); // finally
        }
    }
    while (opStack.tos != -1) // finally pop all operators from opstack and push
    {
        push(&postStack, pop(&opStack));
    }
}

