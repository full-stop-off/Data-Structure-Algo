#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define TRUE 1
#define FALSE 0

struct queue
{
    int item[MAX];
    int rare;
};
int isEmpty(struct queue *q)
{
    if (q->rare == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int isFull(struct queue *q)
{
    if (q->rare == MAX - 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
int enqueue(struct queue *q, int data)
{
    // Insert the item
    if (isFull(q))
    {
        printf("Queue is full. ");
    }
    else
    {
        q->rare ++ ;
        q->item[q->rare] = data; // rare increase and data strore in rare [One-Liner]
        printf("Item Inserted Successfully.");
    }
}

int dequeue(struct queue *q)
{
    int data,i;
    data = q->item[0]; //save a copy of front position
    for (i = 0; i < q->rare; i++)
     {
        q->item[i] = q->item[i+1]; // moves item from ith position to i-th position
     }
    q->rare --;
    return data;
    
}
void display(struct queue q)
{
    int i;
    if (isEmpty(&q))
    {
       printf("Queue if Empty");
    }
    else
    {
        for (i = 0; i < q.item[i]; i++)
        {
            printf("%d \t",q.item[i]);
        }       
    }  
}

int main()
{	
	struct queue q;
    char choice;
    int data;
    q.rare =-1;
    do
    {
        printf("Selet your choice \n 1. Insert \n 2. Remove \n 3. Show \n 4. Exit \n");
        choice = getche();
        switch (choice)
        {
	        case '1':
	            printf("Enter your Data: ");
	            scanf("%d",&data);
	            enqueue(&q,data);
	       		break;
	        case '2':
	            if (isEmpty(&q))
	            {
	                printf("Queue is Empty");
	            }
	            else
	            {
	            printf("%d has been removed from the queue .",dequeue(&q));
	            }       
	       		 break;
	        case '3': display(q); break;  
	        default:
	            return 0;
        }
    } while (TRUE);
    
    return 0;
}