
// Slip 08 
// Q.1) Write a C program to create and display doubly linked list.

#include <stdio.h> 
  typedef struct node
{
    int data;
    struct node *next, *prev;
} NODE;
void createlist(NODE * head)
{
    int n, i;
    NODE *last, *newnode;
    printf("\n Enter how many nodes :  ");
    scanf("%d", &n);
    last = head;
    for (i = 1; i <= n; i++)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->next = newnode->prev = NULL;
        printf("\n enter the node data");
        scanf("%d", &newnode->data);
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }
}
void display(NODE * head)
{
    NODE *temp;

    for (temp = head->next; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
}
void main()
{
    NODE *head;
    int ch, n, pos;

    head = (NODE *)malloc(sizeof(NODE));

    createlist(head);
    display(head);
}

// Q.2) Write a C program to read the data from the file “person.txt” 
// which contains person no and person age and sort the data on age in 
// ascending order using insertion Sort.

#include <stdio.h>
#include <string.h> 
typedef struct
{
    int empid;
    int age;
} RECORD;
RECORD emp[100];
int readFile(RECORD a[100])
{
    int i = 0;
    FILE *fp;
    if ((fp = fopen("emp.txt", "r")) != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%d%d", &a[i].empid, &a[i].age);
            i++;
        }
    }
    return i; 
}
void writeFile(RECORD a[100], int n)
{
    int i = 0;
    FILE *fp;
    if ((fp = fopen("sortedemp.txt", "w")) != NULL)
    {
        for (i = 0; i < n; i++)
        {
            fprintf(fp, "%d\t%d\n", a[i].empid, a[i].age);
        }
    }
}
Insertionsort(RECORD a[100], int n)
{
    int next, i;
    RECORD newelement;
    for (next = 1; next < n; ++next)
    {
        newelement = a[next];
        for (i = next - 1; i >= 0 && newelement.age < a[i].age; i--)
        {
            a[i + 1] = a[i];
        }
        a[i + 1] = newelement;
    }
}
int main()
{
    int n;
    n = readFile(emp);
    Insertionsort(emp, n);
    writeFile(emp, n);
    return 0;
}
