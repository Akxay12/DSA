// Slip 11 

// Q.1) Write a C program to generate n random numbers and sort it 
// using QuickSort.

#include <stdio.h> 
int x[20];
void main()
{
    int n, i;
    printf("\n\n--------------Quick Sort--------------------\n\n");
    printf("\n Enter how many number u want to enter :----> ");
    scanf("%d", &n);
    printf("\n\n Enter all array element\n\n");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &x[i]);
    }
    Qsort(0, n - 1);
printf("\n\n--------------------The Sorted array --------------\n\n"); 
for(i=0;i<n;++i) 
{
            printf("%d ", x[i]); 
}
}
Qsort(int m, int n)
{
    int down, up, temp, pivot;
    if (m < n)
    {
        down = m + 1;
        up = n;
        pivot = x[m];
        do
        {
            while (x[down] < pivot && down < n)
            {
                down++;
            }
            while (x[up] > pivot && up > m)
            {
                up--;
            }
            if (down < up)
            {
                temp = x[down];
                x[down] = x[up];
                x[up] = temp;
            }
        } while (down < up);
        temp = x[m];
        x[m] = x[up];
        x[up] = temp;
        Qsort(m, up - 1);
        Qsort(up + 1, n);
    }
}

// Q.2) Write a C program to implement dynamic stack of integer with 
// operations: (● Push () ● Pop () ● Search ()

#include <stdio.h>
#define NODEALLOC (struct node *)malloc(sizeof(struct node)) 
typedef struct node 
{
        char data;
        struct node *next; 
}Stack; 
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
int search() 
 {
        Stack *temp;
        int key, flag = 0;
        printf(" \n Enter elements to search \n");
        scanf( "%d", &key);
        temp = top;
        do
        {
            if (temp -> data == key)
                flag = 1;
            else
                temp = temp -> next;
        } while (temp != NULL);

        return flag; 
}
#include <string.h> 
main() 
{
        int i = 0, n, n1, ch;
        initstack();
        do
        {
            printf("\n--------MENU---------------------------");
            printf("\n 1) Push element");
            printf("\n 2) POP element");
            printf("\n 3) Show element");
            printf("\n 4) Search");
            printf("\n 5) Exit");
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
               n1 = search();

               if (n1 == 1)
                   printf("\n\n % d is FOUND in Stack", n1);
               else
                   printf("\n\n % d is NOT FOUND in Stack", n1);

               break;
           }
        } while (ch != 4);
        return; 
 } 
 
