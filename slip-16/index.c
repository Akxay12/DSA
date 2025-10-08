
// Slip 16 
 
// Q.1) Write a C program to sort character array using bubble sort.

#include <stdio.h> 
Bubblesort(char x[],int n)
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
    char x[20], n, i;
    printf("\n\n-----------Bubble Sort--------------------\n\n");
    printf("\n Enter how many character u want to enter :----> ");
    scanf("%d", &n);
    printf("\n\n Enter all character\n\n");
    for (i = 0; i < n; ++i)
    {
        scanf("%c", &x[i]);
    }
    Bubblesort(x, n);
    printf("\n\n----------The Sorted array --------------\n\n");
    for (i = 0; i < n; ++i)
    {
        printf("%dc ", x[i]);
    }

    return;
}

// Q.2) Write a C program to convert infix expression into Postfix.

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
void postfix(char in[], char post[])
{
    int i, j = 0;
    char ch;
    stack s1;
    initstack(&s1);
    for (i = 0; in[i] != '\0'; i++)
    {

        if (isalpha(in[i]))
        {
            post[j] = in[i];
            j++;
        }
        else
        {
            switch (in[i])
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '(':
                push(&s1, in[i]);
                break;
            case ')':
                while ((ch = pop(&s1)) != '(')
                {
                    post[j] = ch;
                    j++;
                }
            }
        }
    }
    while (!isempty(&s1))
    {
        post[j] = pop(&s1);
        j++;
    }
    post[j] = '\0';
}
void main()
{

    char in[20], post[20];

    printf("\n Enter Infix string : ");
    scanf("%s", in);
    fflush(stdin);
    postfix(in, post); 
    printf(" \n Postfix sring is ");
    printf("%s", post);
}
