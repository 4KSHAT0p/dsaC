#include <stdio.h>
#include <stdlib.h>
#define MAXQSIZE 20
typedef struct TREE
{
    struct TREE *right;
    struct TREE *left;
    int data;
} tree;
tree *createNode(int);
void TINSERT(int);
void TDELETE(int);
void LEVELORDER(void);
void POSTORDER(tree*);
void INORDER(tree*);
void PREORDER(tree*);
void pushq(tree **, int *, int *, tree *);
tree *popq(tree **, int *, int *);
tree *root = NULL;

int main()
{
    TINSERT(67);
    TINSERT(45);
    TINSERT(456);
    TINSERT(4353);
    TINSERT(13211);
    INORDER(root);
    printf("\n");
    LEVELORDER();
    printf("\n");
    PREORDER(root);
    printf("\n");
    POSTORDER(root);
    /*
             67
          /     \
        45       456
      /   \      /   \
    4353 13211

  after deletion of 67

             45
          /     \
       456     4353
      /   \      /   \
    13211
    */
    return 0;
}
tree *createNode(int x)
{
    tree *node = malloc(sizeof(tree));
    node->data = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}
void TINSERT(int x) // we can also pass tree* root or tree** root it won't matter because all we are doing is inserting at the end.
{
    if (root == NULL)
    {
        root = createNode(x);
    }
    else
    {
        tree *new = createNode(x);

        tree *queue[MAXQSIZE];

        int front = -1;
        int rear = -1;

        pushq(queue, &front, &rear, root);

        while (front <= rear)
        {
            tree *temp = queue[front];

            popq(queue, &front, &rear);
            if (temp->left != NULL)
            {
                pushq(queue, &front, &rear, temp->left);
            }
            else
            {
                temp->left = new;
                new->left = NULL;
                new->right = NULL;
                return;
            }
            if (temp->right != NULL)
            {
                pushq(queue, &front, &rear, temp->right);
            }
            else
            {
                temp->right = new;
                new->right = NULL;
                new->left = NULL;
                return;
            }
        }
    }
}

void TDELETE(int x)
{
    tree *delq[MAXQSIZE];
    tree *array[MAXQSIZE]; // memory waste
    int delf = -1;
    int delr = -1;
    int index = 0;
    pushq(delq, &delf, &delr, root);
    while (delf <= delr)
    {
        tree *delt = delq[delf];
        array[index++] = popq(delq, &delf, &delr);

        if (delt->left != NULL)
        {
            pushq(delq, &delf, &delr, delt->left);
        }

        if (delt->right != NULL)
        {
            pushq(delq, &delf, &delr, delt->right);
        }
    }
    // now we have an array where level order traversal is stored by reference
    // we search for node to be deleted
    for (int i = 0; i < index; i++)
    {
        if (array[i]->data == x)
        {
            for (int j = i; j < index - 1; j++)
            {
                array[j]->data = array[j + 1]->data; // array[index-1+1] doesn't exist so we can replace index by index-1 in inner loop
            }
            break;
        }
    }
    // parent of (index-1)th node is (index-2)/2 th node
    if (array[(index - 2) / 2]->right = array[index - 1]) // very complex this is ::::for freeing we must check its right child then its left child as it's level order
    {
        array[(index - 2) / 2]->right = NULL;
    }
    else
    {
        array[(index - 2) / 2]->left = NULL;
    }

    free(array[index - 1]);
}

void LEVELORDER(void)
{
    tree *delq[MAXQSIZE];
    int delf = -1;
    int delr = -1;
    pushq(delq, &delf, &delr, root);
    while (delf <= delr)
    {
        tree *delt = delq[delf];
        printf("%d\n", popq(delq, &delf, &delr)->data);

        if (delt->left != NULL)
        {
            pushq(delq, &delf, &delr, delt->left);
        }

        if (delt->right != NULL)
        {
            pushq(delq, &delf, &delr, delt->right);
        }
    }
}

void INORDER(tree* root)
{
    if (root == NULL)
        return;
    INORDER(root->left);
    printf("%d\n", root->data);
    INORDER(root->right);
}

void PREORDER(tree* root)
{
    if (root == NULL)
        return;
    printf("%d\n", root->data);
    PREORDER(root->left);
    PREORDER(root->right);
}

void POSTORDER(tree* root)
{
    if (root == NULL)
        return;
    POSTORDER(root->left);
    POSTORDER(root->right);
    printf("%d\n", root->data);
}

void pushq(tree **q, int *f, int *r, tree *x)
{
    if (*r == MAXQSIZE - 1)
    {
        printf("queue overflow");
    }
    else
    {
        if (*f == -1)
        {
            (*f)++;
        }
        (*r)++;
        q[*r] = x;
    }
}

tree *popq(tree **q, int *f, int *r)
{
    if (*f == -1 || *f > *r)
    {
        printf("queue underflow\n");
        return NULL;
    }
    else
    {
        (*f)++;
        return q[*f - 1];
    }
}