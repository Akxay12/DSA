
// Slip 04 
 
// Q.1) Write a C program to search an element using linear search method.

#include <stdio.h> 
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1; 
}
int main()
{
    int arr[100], n, key, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the element to search: ");
    scanf("%d", &key);
    result = linearSearch(arr, n, key);
    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d (position %d).\n", result,
               result + 1);
    return 0;
}

// Q.2) Write a C menu driven program to implement singly circular 
// linked list of integers with Following operations: ● Create ● Insert 
// ● Delete ● Display

#include <stdio.h> 
  typedef struct node
{
    int data;
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
        newnode->next = head;

        printf("\n enter the node data  : ");

        scanf(" %d", &newnode->data);

        last->next = newnode;

        last = newnode;
    }
}
void display(NODE * head)
{
    NODE *temp;

    for (temp = head->next; temp != head; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
}
void insert(NODE * head, int num, int pos)
{
    NODE *newnode, *temp;
    int i;

    for (temp = head, i = 1; (temp->next != head) && (i <= pos - 1); i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("\n Postion is out of range ");
        return;
    }
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = num;
    newnode->next = temp->next;
    temp->next = newnode;
}
void deletepos(NODE * head, int pos)
{
    NODE *temp, *temp1;

    int i;
    for (temp = head, i = 1; (temp->next != head) && (i <= pos - 1); i++)
        temp = temp->next;

    if (temp->next == NULL)
    {
        printf("\nPosition is out of range ");
        return;
    }

    temp1 = temp->next;
    temp->next = temp1->next;

    free(temp1);
}
void main()
{
    NODE *head;
    int ch, n, pos;
    head = (NODE *)malloc(sizeof(NODE));
    do
    {
        printf("\n 1: CREATE ");
        printf("\n 2: DELETE BY POSITION");
        printf("\n 3: DISPLAY");
        printf("\n 4: INSERT");
        printf("\n 5: EXIT");

        printf("\nenter your choice  : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createlist(head);
            break;
        case 2:
            printf("\n Enter the position ");
            scanf("%d", &pos);
            deletepos(head, pos);
            display(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            printf("\n enter the element and position to insert");
            scanf("%d%d", &n, &pos);
            insert(head, n, pos);
            display(head);
            break;
        }
    } while (ch != 5);
}
