
#include <stdio.h>

// Slip 18 
 
// Q.1) Write a C program to display the city code of the corresponding 
// city name using linear search method. The structure is: struct city

#include <stdio.h> 
{
    int city_code;
    char name[30];
}
struct city
{
    char cname[10];
    int STD;
} C[10];
int Linearsearch(struct city A[], int last, char target[], int *location)
{
    int i;
    i = 0;
    while (i < last && strcmp(target, A[i].cname) != 0)
        i++;
    *location = i;
    return (strcmp(target, A[i].cname));
}
int main(void)
{
    int arr[10];
    int x, result, n, index, i, num, t2;
    char fname[10], line[50], t1[20], name[10];
    FILE *fp;
    printf("\n Enter Filename : ");
    scanf("%s", fname);
    if ((fp = fopen(fname, "r")) == NULL)
    {
        printf("\n Error in opening File \n");
        return;
    }
    fflush(stdin);
    n = 0;
    printf("\n------------- File Data------------\n");
    while (fgets(line, 80, fp))
    {
        sscanf(line, "%s %d", t1, &t2);
        strcpy(C[n].cname, t1);
        C[n].STD = t2;
        printf("\n\t %s\t %d", C[n].cname, C[n].STD);
        n++;
    }
    printf("\n Enter cityname to search ");
    scanf("%s", name);
    result = Linearsearch(C, n, name, &index);
    if (!result)
        printf("\n Element is present at---> %d location and \n STD Code is -- ---> %d", index + 1, C[index].STD);

    else
        printf("\n Element is not present");
    return 0;
}

// Q.2) Write a C program to implement dynamic implementation of queue 
// with following operations:  • Insert • Length-Count total elements • 
// Search-Search particular element

#include <stdio.h> 
typedef struct node
{
    int data;
    struct node *next;
} NODE;
NODE *front, *rear;
void initQ()
{
    front = rear = NULL;
}
void addQ(int n)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = n;
    newnode->next = NULL;
    if (front == NULL)
    {
        rear = front = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
int isempty()
{
    return (front == NULL);
}
void display()
{
    NODE *temp;
    temp = front;
    printf("\n Elemnt");
    do
    {
        printf("\n %d", temp->data);
        temp = temp->next;
    } while (temp != NULL);
}
void Search()
{
    int key, flag = 0;
    NODE *temp;
    temp = front;
    printf("\n Enter Element to search ");
    scanf("%d", &key);
    do
    {
        if (temp->data == key)
        {
            flag = 1;
            break;
        }
        else
            temp = temp->next;
    } while (temp != NULL);

    if (flag == 1)
        printf("\n\n %d is present in Queue");
    else
        printf("\n\n %d isNOT present in Queue");
}
void Length()
{
    int count;
    NODE *temp;
    temp = front;
    printf("\n Count Number of elements in Q : ");
    do
    {
        count++;
        temp = temp->next;
    } while (temp != NULL);

    printf("%d", count);
}
int main()
{
    int ch, n;
    initQ();
    do
    {
printf("\n 1.Insert Node \n 2.Serach  Node\n 3.Length - count total element \n 4.Display\n 5.exit"); 
printf("\n Enter ur choice : "); 
scanf("%d",&ch); 
switch(ch) 
{
            case 1:
                printf("\n Enter element : ");
                scanf("%d", &n);
                addQ(n);
                break;
            case 2:
                Search();
                break;

            case 3:
                Length();
                break;
            case 4:
                display();
                break;
            case 5:
                break; 
 
}
    } while (ch != 5);
}
