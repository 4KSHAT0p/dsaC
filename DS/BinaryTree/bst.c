#include <stdio.h>
#include <stdlib.h>
typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
} bst;

struct BST *createNode(int);
void BSTINSERT(bst *, int); // bst* as we insert on leaf only
void BSTDELETE(bst *, int); // bst* also because every task can be done by copying i.e. changing contents of pointers not pointers itself

struct BST *createNode(int x)
{
    bst *new = malloc(sizeof(bst));
    new->data = x;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void BSTINSERT(bst *x, int y)
{
    bst *newnode = createNode(y);

    if (y > x->data)
    {
        if (x->right == NULL)
        {
            x->right = newnode;
        }
        else
        {
            BSTINSERT(x->right, y);
        }
    }
    else
    {
        if (x->left == NULL)
        {
            x->left = newnode;
        }
        else
        {
            BSTINSERT(x->left, y);
        }
    }
}

void BSTDELETE(bst *x, int y)
{
    bst *temp = x;
    bst *backup = NULL;
    while (temp->data != y)
    {
        if (temp->data > y)
        {
            backup = temp;
            temp = temp->left;
            if (temp == NULL)
            {
                break;
            }
        }
        else if (temp->data < y)
        {
            backup = temp;
            temp = temp->right;
            if (temp == NULL)
            {
                break;
            }
        }
    }
    if (temp == NULL)
    {
        printf("Sorry, but %d is not present in BST\n", y);
        return;
    }
    else if (temp->left == NULL && temp->right == NULL) // leaf node
    {
        if (backup->right == temp)
        {
            free(temp);
            backup->right = NULL;
        }
        else if (backup->left == temp)
        {
            free(temp);
            backup->left = NULL;
        }
    }
    else if (temp->left != NULL && temp->right != NULL)
    {
        // strategy
        // find smallest in right subtree or largest in left subtree (it will be a leaf node)
        // copy its data to the node that needs to be deleted and delete the leaf node
        //  i'll find largest in left subtree
        bst *small = temp->left;
        bst *backsmall = NULL;
        while (small->left != NULL && small->right != NULL)
        {
            backsmall = small;
            small = small->right;
        }
        temp->data = small->data;
        if (backsmall->right == small)
        {
            backsmall->right = NULL;
            free(small);
        }
        else if (backsmall->left == small)
        {
            backsmall->left = NULL;
            free(small);
        }
    }
    else // node with one child
    {
        if (backup->right == temp)
        {
            if (temp->left == NULL)
            {
                backup->right = temp->right;
                free(temp);
            }
            else
            {
                backup->right = temp->left;
                free(temp);
            }
        }
        else if (backup->left == temp)
        {
            if (temp->left == NULL)
            {
                backup->left = temp->right;
                free(temp);
            }
            else
            {
                backup->left = temp->left;
                free(temp);
            }
        }
    }
}

int main()
{

    bst *root = (bst *)malloc(sizeof(bst));

    root->data = 30;
    root->left = NULL;
    root->right = NULL;

    BSTINSERT(root, 50);
    BSTINSERT(root, 20);
    BSTINSERT(root, 25);
    BSTINSERT(root, 35);
    BSTINSERT(root, 60);
    BSTINSERT(root, 10);
    BSTDELETE(root,30);
printf("%d",root->data);
    /*
              30
            /    \
           20    50
           / \    / \
          10  25  35 60

    */

    return 0;
}