// Slip-01

// Q.1 Write a C program to search an element by using binary search method.

#include <stdio.h>
int binarySearch(int arr[], int size, int target)
{
    int Begin = 0, End = size - 1, mid;
    while (Begin <= End)
    {
        mid = (Begin + End) / 2;
        printf("%d", mid);
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            Begin = mid + 1;
        else
            End = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[100], n, target;
    printf("Enter number of elements (sorted): ");
    scanf("%d", &n);
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, n, target);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array.\n");

    return 0;
}

// Q.2) Write a C program to implement static stack of integer with
// operations:
// ● Push () ● Pop () ● Empty ()

#include <stdio.h>
#define MAX 5
#define EMPTY -1
#define FULL MAX - 1
typedef struct stk
{
    int top;
    int item[MAX];
} stack;
void initstack(stack *ps)
{
    ps->top = -1;
}
int isempty(stack *ps)
{
    return (ps->top == EMPTY);
}

int isfull(stack *ps)
{
    return (ps->top == FULL);
}
void push(stack *ps, int n)
{
    if (isfull(ps))
    {
        printf("\n stack full");
    }
    else
    {
        ++ps->top;
        ps->item[ps->top] = n;
    }
}
int pop(stack *ps)
{
    int n1;
    n1 = ps->item[ps->top];
    ps->top--;
    return n1;
}
void show(stack *ps)
{
    int t;
    t = ps->top;
    while (t >= 0)
    {
        printf("%d  ", ps->item[t]);
        t--;
    }
}
int main()
{
    int ch, n, n1;
    stack s1;
    initstack(&s1);
    do
    {
        printf("\n-------------MENU---------------------------");
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
            push(&s1, n);
            break;

        case 2:
            if (!isempty(&s1))
            {
                n1 = pop(&s1);
                printf("\n %d is deleted from stack", n1);
            }
            else
            {
                printf("\n Stack is empty \n");
            }
            break;

        case 3:
            printf("\n The element in stack are as follows \n");
            show(&s1);
            break;

        case 4:
            break;
        }
    } while (ch != 4);
    return 0;
}
