# include <stdio.h>
# define MAX 100
# include YES 1
#  define NO 0

struct stack
{
    char data[MAX];
    int tos;
};

void push(struct stack *s)
{
    if (s->tos==MAX - 1)
    {
        printf("Stack is full.");
    }
    else
    {
        s->data[]=number;
    }
}
