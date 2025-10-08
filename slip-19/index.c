
// Slip 19 
 
// Q.1) Write a C program to create and display singly Linked List of 
// vowels.

#include <stdio.h> 
  typedef struct node
{
    char data;
    struct node *next;
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
        newnode->next = NULL;
        printf("\n enter the node data  : ");
        scanf(" %c", &newnode->data);
        last->next = newnode;
        last = newnode;
    }
}
void display(NODE * head)
{
    NODE *temp;

    for (temp = head->next; temp != NULL; temp = temp->next)
    {
        printf("%c\t", temp->data);
    }
}
void main()
{
    NODE *head;
    int ch, n, pos;

    head = (NODE *)malloc(sizeof(NODE));

    createlist(head);

    printf("\n\n  Singly Linked List All Elements \n\n");
    display(head);
}

// Q.2) Write a C program to implement dynamic implementation of stack with following 
// operations: ● Push ● Pop ● Reverse-Display elements in reverse order of insertion

#include <stdio.h>
#define NODEALLOC (struct node *)malloc(sizeof(struct node)) 
typedef struct node
{
    char data;
    struct node *next;
} Stack;
Stack *top;
void initstack()
{
    top = NULL;
}
int isempty()
{
    return (top == NULL);
}
void push(char n)
{
    Stack *newnode;
    newnode = NODEALLOC;
    newnode->data = n;
    newnode->next = top;
    top = newnode;
}
char pop()
{
    char num;
    Stack *temp = top;
    num = top->data;
    top = top->next;
    free(temp);
    return num;
}
void show()
{

    Stack *temp;
    printf(" \n Elements in Stack \n");
    temp = top;
    do
    {
        printf("\n %d", temp->data);
        temp = temp->next;
    } while (temp != NULL);
}
#include <string.h>
main()
{
    int i = 0, n, n1, ch;
    initstack();
    do
    {
        printf("\n--------------------MENU---------------------------");
        printf("\n 1) Push element");
        printf("\n 2) POP element");
        printf("\n 3) Show element");
        printf("\n 4) Exit");
        printf("\n Enter your choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter the element to insert :  ");
            scanf("%d", &n);
            push(n);
            break;

        case 2:
            if (!isempty())
            {
                n1 = pop();
                printf("\n %d is deleted from stack", n1);
            }
            else
            {
                printf("\n Stack is empty \n");
            }
            break;

        case 3:
            printf("\n The element in stack are as follows \n");
            show();
            break;

        case 4:
            break;
        }
    } while (ch != 4);
    return;
}
