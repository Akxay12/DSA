// Slip-02 


// Q.1) Write a C program to sort n elements using Bubble Sort.

#include <stdio.h> 
Bubblesort(int x[],int n)
{
    int t, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (x[j] > x[j + 1])
            {

                t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;
            } 
        } 
    } 
}
int main()
{
    int x[20], n, i;
    printf("\n\n--------------Bubble Sort--------------------\n\n");
    printf("\n Enter how many number u want to enter :----> ");
    scanf("%d", &n);
    printf("\n\n Enter all array element\n\n");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &x[i]);
    }
    Bubblesort(x, n);
    printf("\n\n------------The Sorted array --------------\n\n");
    for (i = 0; i < n; ++i)
    {
        printf("%d ", x[i]);
    }
    return;
}

// Q.2) Write a C menu driven program to implement doubly linked list 
// of integers with following Operations:  
//  ● Create ● Delete ● Insert ● Display

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
void insert(NODE * head, int num, int pos)
{
    NODE *newnode, *temp, *temp1;
    int i;

    for (temp = head, i = 1; (temp != NULL) && (i <= pos - 1); i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("\n Position is out of range");
        return;
    }
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = num;
    newnode->next = newnode->prev = NULL;
    temp1 = temp->next;
    newnode->next = temp1;
    temp1->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}
void deletepos(NODE * head, int pos)
{
    NODE *temp, *temp1;

    int i;
    for (temp = head, i = 1; (temp->next != NULL) && (i <= pos - 1); i++)
        temp = temp->next;
    if (temp->next == NULL)
    {
        printf("\nPosition is out of range ");
        return;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    if (temp1->next != NULL)
        temp1->next->prev = temp;
    free(temp1);
}
void deletevalue(NODE * head, int num)
{
    NODE *temp, *temp1;
    for (temp = head; temp->next != NULL; temp = temp->next)
        if (temp->next->data == num)
        {
            temp1 = temp->next;
            temp->next = temp1->next;
            if (temp1->next != NULL)
                temp1->next->prev = temp;
            free(temp1);
            return;
        }
    printf("Element not found");
}
void main()
{
    NODE *head;
    int ch, n, pos;
    head = (NODE *)malloc(sizeof(NODE));
    do
    {
        printf("\n 1: CREATE ");
        printf("\n 2: INSERT");
        printf("\n 3: DISPLAY");
        printf("\n 4: DELBYPOS");
        printf("\n 5: DELBYVALUE");
        printf("\n 6: EXIT");
        printf("\nenter your choice  : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createlist(head);
            break;
        case 2:
            printf("\n Enter the element and position ");
            scanf("%d%d", &n, &pos);
            insert(head, n, pos);
            display(head);
            break;
        case 3:
            display(head);
            break;

        case 4:
            printf("\n Enter the position to delete");
            scanf("%d", &pos);
            deletepos(head, pos);
            display(head);
            break;
        case 5:
            printf("\n Enter the elementto delete");
            scanf("%d", &n);
            deletevalue(head, n);
            display(head);
            break;
        }
    } while (ch != 6);
}
