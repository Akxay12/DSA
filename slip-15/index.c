
// Slip 15

    // Q1.Write a C program to sort n numbers using Quick sort.

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

// Q.2) Write a C program to reverse a given string using stack.

#include <stdio.h>
#define MAX 5
#define EMPTY -1
#define FULL MAX - 1 
typedef struct stk
    {
        int top;
        int item[MAX];
    } stack;
    void initstack(stack * ps)
    {
        ps->top = -1;
    }
    int isempty(stack * ps)
    {
        return (ps->top == EMPTY);
    }
    int isfull(stack * ps)
    {
        return (ps->top == FULL);
    }
    void push(stack * ps, int n)
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
    int pop(stack * ps)
    {
        int n1;
        n1 = ps->item[ps->top];
        ps->top--;
        return n1;
    }
    void show(stack * ps)
    {

        int t;
        t = ps->top;
        while (t >= 0)
        {
            printf("%d ", ps->item[t]);
            t--;
        }
    }
    int main()
    {
        stack s1;
        char str[20];
        int i = 0;
        initstack(&s1);
        printf("\n enter the string\n");
        gets(str);
        // scanf("%s",str);
        while (str[i] != '\0')
        {
            push(&s1, str[i]);
            i++;
        }
        i = 0;
        while (!isempty(&s1))
        {
            str[i] = pop(&s1);
            i++;
        }
        str[i] = '\0';
        printf("\n The reversed of string is :");
        printf("%s\n", str);
        return 0;
    }
