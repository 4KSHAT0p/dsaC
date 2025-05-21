#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} heap;

heap *createNode(int);
void ArrToTree(int *, int, heap **);
void ArrToHeap(int *, int); // heapify
void insert(int *, int *, int);
int delete(int *, int *);
void HEAPSORT(int *, int *);
int parent(int);
void swap(int *, int *);
void PREORDER(heap *root);
int main()
{
    int n;
    printf("enter number of elements in heap\n");
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(int));
    printf("enter elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    heap *root = NULL;
    insert(arr, &n, 45);
    HEAPSORT(arr, &n);

    return 0;
}

void ArrToTree(int *arr, int x, heap **root)
{

    for (int i = 0; i < x; i++)
    {
        if (*root == NULL)
        {
            *root = createNode(arr[i]);
        }
        else
        {
            heap *ins = createNode(arr[i]);
            heap *queue[20];
            int f = -1;
            int r = -1;
            queue[++r] = *root;
            f++;
            while (f <= r)
            {
                heap *temp = queue[f++];
                if (temp->left != NULL)
                {
                    queue[++r] = temp->left;
                }
                else
                {
                    temp->left = ins;
                    break;
                }
                if (temp->right != NULL)
                {
                    queue[++r] = temp->right;
                }
                else
                {
                    temp->right = ins;
                    break;
                }
            }
        }
    }
}
void ArrToHeap(int *arr, int x)
{
    for (int i = x - 1; i >= 0; i--)
    {
        if (parent(i) == i)
        {
            return;
        }
        else if (arr[i] < arr[parent(i)]) // > for max heap
        {
            swap(&arr[i], &arr[parent(i)]);
        }
        ArrToHeap(arr, parent(i) + 1);
    }
}
void insert(int *arr, int *x, int data) // int*n to reflect changes in n after inserting
{
    (*x)++;
    arr = realloc(arr, (*x) * sizeof(int));
    arr[(*x) - 1] = data;
    ArrToHeap(arr, *x);
    // ArrToTree(arr,*x,root);  pata nahi ye kyu nahi kaam kar raha
}
int delete(int *arr, int *n)
{
    (*n)--; // be careful dont write *m++; its wrong
    int m = arr[0];
    arr[0] = arr[*n];
    arr = realloc(arr, (*n) * sizeof(int));
    ArrToHeap(arr, (*n));
    return m;
}
void HEAPSORT(int *arr, int *n)
{
    ArrToHeap(arr,*n);
    while (*n > 0)
    {
        printf("%d\n", delete (arr, n));
    }
}
heap *createNode(int x)
{
    heap *new = malloc(sizeof(heap));
    new->data = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int parent(int n)
{
    if (n >= 1)
        return (n - 1) / 2;

    else
        return 0;
}
void PREORDER(heap *root)
{
    if (root == NULL)
        return;
    printf("%d->", root->data);
    PREORDER(root->left);
    PREORDER(root->right);
}
void swap(int *x, int *y)
{
    if (*x == *y)
    {
        return;
    }
    else
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
}
