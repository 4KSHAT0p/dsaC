#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data, degree;
    struct node *sibling;
    struct node *child;
    struct node *parent;
} binoheap;

binoheap *createNode(int);
binoheap *merge(binoheap *, binoheap *);
binoheap *insert(binoheap *, int);
binoheap *delete(binoheap *);
void reverse_roots(binoheap **);


int main()
{

    binoheap *BINO_HEAP = insert(createNode(67), 23); // 23), 15), 34), 56), 89), 1)));
    BINO_HEAP = insert(BINO_HEAP, 15);
    BINO_HEAP = insert(BINO_HEAP, 34);
    BINO_HEAP = insert(BINO_HEAP, 56);
    BINO_HEAP = insert(BINO_HEAP, 3);
    BINO_HEAP = insert(BINO_HEAP, 16);
    BINO_HEAP = insert(BINO_HEAP, 89);
    BINO_HEAP = insert(BINO_HEAP, 45);
    BINO_HEAP = insert(BINO_HEAP, 31);
    BINO_HEAP = insert(BINO_HEAP, 12);
    BINO_HEAP = insert(BINO_HEAP, 78);
    BINO_HEAP = insert(BINO_HEAP, 19);
    BINO_HEAP = insert(BINO_HEAP, 100);
    BINO_HEAP = insert(BINO_HEAP, 48);
    BINO_HEAP = insert(BINO_HEAP, 29);
    BINO_HEAP = insert(BINO_HEAP, 90);
    BINO_HEAP = insert(BINO_HEAP, 122);
    BINO_HEAP = insert(BINO_HEAP, 59);
    BINO_HEAP = insert(BINO_HEAP, 69);
    BINO_HEAP = insert(BINO_HEAP, 71);
    BINO_HEAP = insert(BINO_HEAP, 40);


binoheap* disp=BINO_HEAP;

printf("LIST OF ROOTS is:(data,degree)\n");
while(disp!=NULL)
{
    printf("(%d,%d) ",disp->data,disp->degree);
    disp=disp->sibling;
}

    return 0;
}

binoheap *createNode(int data)
{
    binoheap *newnode = calloc(1, sizeof(binoheap));
    newnode->data = data;
    newnode->degree = 0;
    newnode->child = NULL;
    newnode->sibling = NULL;
    newnode->parent = NULL;
}

binoheap *merge(binoheap *x, binoheap *y)
{
    if (x->degree == y->degree && x->sibling == NULL && y->sibling == NULL)
    {
        if (x->data < y->data)
        {
            if (x->degree > 0)
            {
                y->sibling = x->child;
            }
            y->parent = x;
            x->child = y;
            x->degree++;
            return x;
        }
        else
        {
            if (y->degree > 0)
            {
                x->sibling = y->child;
            }
            x->parent = y;
            y->child = x;
            y->degree++;
            return y;
        }
    }
    else if (x->degree != y->degree && x->sibling == NULL && y->sibling == NULL)
    {
        if (x->degree < y->degree)
        {
            x->sibling = y;
            return x;
        }
        else
        {
            y->sibling = x;
            return y;
        }
    }
    else
    {
        binoheap *min = NULL, *max = NULL, *backup = NULL, *mer = NULL, *head = NULL;

        if (x->degree < y->degree)
        {
            min = x;
            mer = x;
            head = x;
            max = y;
        }
        else if (x->degree > y->degree)
        {
            min = y;
            mer = y;
            head = y;
            max = x;
        }
        else
        {
            int count[2] = {0, 0};

            mer = x;
            head = y;

            while (mer != NULL)
            {
                count[0]++;
                mer = mer->sibling;
            }
            while (head != NULL)
            {
                count[1]++;
                head = head->sibling;
            }

            if (count[0] < count[1])
            {
                min = x;
                mer = x;
                head = x;
                max = y;
            }
            else
            {
                min = y;
                mer = y;
                head = y;
                max = x;
            }
        }

        // merge like merging algo of mergesort
        while (min->sibling != NULL && max->sibling != NULL)
        {
            if (min->sibling->degree <= max->degree)
            {
                min = min->sibling;
            }
            else
            {
                backup = min->sibling;
                min->sibling = max;
                min = max;
                max = backup;
            }
        }

        while (min->sibling != NULL)
        {
            min = min->sibling;
        }
        min->sibling = max;

        while (mer->sibling != NULL)
        {
            if (mer->degree == mer->sibling->degree)
            {
                max = mer;
                if (mer->data > mer->sibling->data)
                {
                    mer = mer->sibling;
                }
                backup = max->sibling;
                min = max->sibling->sibling;
                max->sibling = NULL;
                backup->sibling = NULL;
                head = merge(max, backup);
                head->sibling = min;
            }
            else
            {
                mer = mer->sibling;
            }
        }
        return head;
    }
}

binoheap *insert(binoheap *root, int x)
{
    binoheap *new = createNode(x);
    return merge(root, new);
}

binoheap *delete(binoheap *root) // we have to select minimum and delete it (EXTRACT MIN)
{
    binoheap *del = NULL, *min = NULL, *temp = NULL, *ref = NULL;
    min = del = root;

    while (del != NULL)
    {

        if (del->data < min->data)
        {
            min = del;
        }
        del = del->sibling;
    }
    del = root;
    if (del != min)
    {
        while (del->sibling != min)
        {
            del = del->sibling;
        }
    }
    temp = del;
    del = min->sibling;
    min->sibling = NULL;

    if (temp->data != min->data)
    {
        temp->sibling = NULL;
        min = min->child;
        free(min->parent);
        min->parent = NULL;
        ref = min;
        reverse_roots(&min);
        min->sibling = ref;
        ref->sibling = del;
        return merge(root, min);
    }
    else
    {
        if (min->child != NULL)
        {
            min = min->child;
            free(min->parent);
            min->parent = NULL;
            temp = min;
            reverse_roots(&min);
            temp->sibling = del;
            return min;
        }
        else
        {
            min = del;
            free(temp);
            return min;
        }
    }
}

void reverse_roots(binoheap **x)
{
    binoheap *prev = NULL;
    binoheap *current = *x;
    binoheap *sibling = NULL;
    while (current != NULL)
    {
        sibling = current->sibling;
        current->sibling = prev;
        prev = current;
        current = sibling;
    }
    *x = prev;
}