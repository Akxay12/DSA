// Slip 07      

// Q.1) Write a C program to find the length of singly linked list

#include <stdio.h> 
  typedef struct node
{
    int data;
    struct node *next;
} NODE;
void createlist(NODE * head)
{
    int n, i;
    char ch;
    NODE *last, *newnode;
    last = head;
    do
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->next = NULL;
       printf("\n Enter the node data to Insert in Linked List  :");        
       scanf(" %d",&newnode->data);            
       last->next = newnode;  
       last=newnode;         
       while ((getchar()) != '\n');   
        printf("Do you want to insert another node (y/n)? "); 
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
void display(NODE * head)
{
    NODE *temp;
    for (temp = head->next; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
}
void Length(NODE * head)
{
    NODE *temp;
    int count = 0;
    for (temp = head->next; temp != NULL; temp = temp->next)
    {
        count++;
    }
    printf("\n \n Length of Linked List  :  %d", count);
}
void main()
{
    NODE *head;
    int ch, n, pos;
    head = (NODE *)malloc(sizeof(NODE));
    createlist(head);
    printf("\n\n  Singly Linked List All Elements \n\n");
    display(head);
    Length(head);
}

// Q.2) Write a C program to implement dynamic implementation of stack 
// of integers with following operation: • push() • pop () • isempty() 
// • isfull() • display ()

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
        printf("\n-----------MENU---------------------------");
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