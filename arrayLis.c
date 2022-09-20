#include <stdio.h>
#include <conio.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
typedef struct
{
    char name[50];
    int roll;
    char grade[30];
} student;

typedef struct
{
    int rear;
    student std[MAX];
} list;

void addStudent(list *);    // insert at first, insert at last, insert before, insert after
void removeStudent(list *); // remove At first or remove At last
void listStudent(list *);   // list sorted by roll, list sorted by name
void updateStudent(list *); 

int main()
{
    list sList;
    char ch;
    sList.rear = -1;
    do
    {
        printf("\n Select an options: \n 1. Insert \n 2. Remove \n 3. Update \n 4. List \n");
        ch = getche();
        switch (ch)
        {
        case '1':
            addStudent(&sList);
            break;

        case '2':
            removeStudent(&sList);
            break;

        case '3':
            updateStudent(&sList);
            break;

        case '4':
            listStudent(&sList);
            break;

        case '5':
            printf("\n Thank your for using this app.");
            return 0;
        }
    } while (TRUE);

    return 0;
}

void addStudent(list *p)
{
    student s;
    if (p->rear == MAX - 1)
    {
        printf("\n List is Full:");
    }
    else
    {
        fflush(stdin);
        printf("\n Enter Name: ");
        gets(s.name);
        fflush(stdin);
        printf("\n Enter roll number: ");
        scanf("%d", &s.roll);
        fflush(stdin);
        printf("\n Enter Grade: ");
        gets(s.grade);
        p->rear++;
        p->std[p->rear] = s;
        printf("\n Student added ");
    }
}
void removeStudent(list *p)
{
    int i, roll, found = FALSE;
    printf("\n Enter roll number of the student of removed");
    scanf("%d", &roll);
    for (i = 0; i < p->rear; i++)
    {
        if (found == TRUE) // if already found then shift all remainig one position
        {
            p->std[i - 1] = p->std[i];
        }
        else if (p->std[i].roll == roll) // if found
        {
            found = TRUE;
            printf("\n Student rmoved: Name: %s \t Roll: %d \t grade: %s", p->std[i].name, p->std[i].roll, p->std[i].grade);
        }
    }
    if (found == TRUE)
    {
        p->rear--;
    }
    else
    {
        printf("Student not Found");
    }
}

void updateStudent(list *p)
{
    int i, roll, found = FALSE;
    printf("Enter studnet roll numer: ");
    scanf("%d", &roll);
    for ( i = 0; i < p->rear; i++)
    {
        if (p->std[i].roll == roll)
        {
            fflush(stdin);
            printf("\n Your name is %s. Enter Name: ", p->std[i].name);
            gets(p->std[i].name);
            fflush(stdin);
            printf("\n Your Roll number is %d.  Enter roll number: ", p->std[i].roll);
            scanf("%d", &p->std[i].roll);
            fflush(stdin);
            printf("\n your Grade is %s. Enter Grade: ", p->std[i].grade);
            gets(p->std[i].grade);
            printf("UPDATED");
            found = TRUE;
            break;
        }
    }
}

void listStudent(list *p)
{
	int i;
    printf("\n roll no. \t Name of Student \t Grade Name: \n");
    for ( i = 0; i < p->rear; i++)
    {
        printf("\n %d\t\t%s\t\t%s\n",p->std[i].roll,p->std[i].name,p->std[i].grade);
    }
   
}
