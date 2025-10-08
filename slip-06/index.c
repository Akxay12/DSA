
// Slip 06 
// Q.1) Write a C program to reverse a string using Stack .

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

// Q.2) Write a C program to read the data from the file “employee.txt” 
// which contains empno and empname and sort the data on names 
// alphabetically (use strcmp) using Bubble Sort.

#include <stdio.h>
#include <string.h> 
typedef struct
{
    char ename[30];
    int eno;
} RECORD;
RECORD emp[100];
int readFile(RECORD a[100])
{
    int i = 0;
    FILE *fp;
    if ((fp = fopen("empinfo.txt", "r")) != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s%d", a[i].ename, &a[i].eno);
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
            fprintf(fp, "%s\t%d\n", a[i].ename, a[i].eno);
        }
    }
}
int Bubblesort(RECORD * a, int n)
{
    int i, j;
    RECORD t;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (strcmp(a[j].ename, a[j + 1].ename) > 0)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    } 
    return 0;
}
int main()
{
    int n;
    n = readFile(emp);
    Bubblesort(emp, n);
    writeFile(emp, n);
    return 0;
}
