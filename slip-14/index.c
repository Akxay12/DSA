// Slip-14 
 
// Q.1) Write a C program to search a given character using binary 
// search method [use recursion]

#include <stdio.h> 
int binarySearch(char arr[], int low, int high, char key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid; 
        }
        else if (arr[mid] < key)
        {
            return binarySearch(arr, mid + 1, high, key); 
        }
        else
        {
            return binarySearch(arr, low, mid - 1, key); 
        }
    }
    return -1; 
}
int main()
{
    char arr[100], key;
    int n, result;
    printf("Enter number of characters: ");
    scanf("%d", &n);
    printf("Enter characters in sorted order: ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i]); 
    }
    printf("Enter character to search: ");
    scanf(" %c", &key);
    result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Character '%c' found at position %d\n", key, result + 1);
    else
        printf("Character '%c' not found in the array.\n", key);
    return 0;
}

// Q.2) Write a C program to create BST and implement following 
// operations: ● Display in-order traversal ● To count total no of 
// nodes ● To count odd numbers from BST

#include <stdio.h>
#define NODEALLOC (struct node *)malloc(sizeof(struct node)) 
typedef struct node
{
    int data;
    struct Node *left, *right;
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
            while (1)
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
int countnodes(NODE * root)
{
    static int count = 0;
    NODE *temp = root;
    if (temp != NULL)
    {
        count++;
        countnodes(temp->left);
        countnodes(temp->right);
    }
    return count;
}
int countOdd(NODE * root)
{
    int count = 0;
    if (root == NULL)
        return 0;
    count = (root->data % 2 != 0) ? 1 : 0;
    count += countOdd(root->left);
    count += countOdd(root->right);
    return count;
}
int main()
{
    NODE *root = NULL;
    int count, totalnode;
    root = createbst(root);
    printf("\n Node in Inorder \n\n");
    inorder(root);
    printf("\n Total Node in Binary Tree : ");
    totalnode = countnodes(root);
    printf("%d", totalnode);
    printf("\n Count ODD Numbers in Binary Tree : ");
    totalnode = countOdd(root);
    printf("%d", totalnode);
    return 0;
}
