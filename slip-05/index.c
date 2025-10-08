
// Slip 05 
 
// Q.1) Write a C program to create and display singly linked list.

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
        newnode -> next = NULL;

        printf("\n enter the node data  : ");

        scanf(" %d", &newnode->data);

        last -> next = newnode;

        last = newnode;
    }
}
void display(NODE * head)
{
    NODE *temp;

    for (temp = head -> next; temp != NULL; temp = temp -> next)
    {
        printf("%d\t", temp->data);
    }
}
void main()
{
    NODE *head;
    int ch, n, pos;
    head = (NODE *)malloc(sizeof(NODE));
    createlist(head);
    display(head);
}

// Q.2) Write a C program to create BST and display its preorder , in
// order traversal.

#include <stdio.h>
#define NODEALLOC (struct node *)malloc(sizeof(struct node)) 
typedef struct node
{
    int data;
    struct node *left, *right;
} NODE;
NODE *createbst(NODE * root)
{
    NODE *newnode, *temp;
    int num, n, i;
    printf("\n Enter how many node \n");
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        newnode = NODEALLOC;
        printf(" \n Enter the data to insert ");
        scanf("%d", &num);
        newnode->data = num;
        newnode->left = NULL;
        newnode->right = NULL;
        if (root == NULL)
            root = newnode;
        else
        {
            temp = root;
            while (temp != NULL)
            {
                if (num < temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = newnode;
                        break;
                    }
                    else
                        temp = temp->left; 
                }
                else if (num > temp->data)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = newnode;
                        break;
                    }
                    else
                        temp = temp->right;
                }
            } 
        }
    } 
    return root;
}
void preorder(NODE * root)
{
    NODE *temp = root;
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(NODE * root)
{
    NODE *temp = root;
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}
void postorder(NODE * root)
{
    NODE *temp = root;
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}
int main()
{
    NODE *root = NULL;
    int count;
    root = createbst(root);

    printf("\n Node in Preorder \n\n ");
    preorder(root);
    printf("\n Node in Inorder \n\n");
    inorder(root);
    printf("\n Node in Postorder \n\n ");
    postorder(root);
    return 0;
}
