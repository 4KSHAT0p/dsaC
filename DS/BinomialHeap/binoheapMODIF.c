#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data, degree;
    struct node *next;
    struct node *exleftchld;
    struct node *parent;
} binoheap;

binoheap *createNode(int);
void merge(binoheap **, binoheap **); // to merge binomial heaps

int main()
{
    binoheap *root1 = createNode(67); // B0
    binoheap *root2 = createNode(45); // B0
    binoheap *root3 = createNode(11); // B0
    binoheap *root4 = createNode(5);  // B0
    binoheap *root5 = createNode(6);  // B0
    binoheap *root6 = createNode(1);  // B0
    merge(&root1, &root2);            // B1
    merge(&root3, &root4);            // B1
    merge(&root2, &root4);            // B2
    merge(&root4, &root5);            // B2 + B0
    merge(&root6, &root5);            // B0 + B0 + B2 to be B1 + B2

printf("%d",root6->next->data);

    return 0;
}

binoheap *createNode(int data)
{
    binoheap *newnode = calloc(1, sizeof(binoheap));
    newnode->data = data;
    newnode->degree = 0;
    newnode->exleftchld = NULL;
    newnode->next = NULL;
    newnode->parent = NULL;
}

void merge(binoheap **x, binoheap **y) // passing double pointer to not be able to access roots that are merged bcz we point larger root to NULL
{
    if ((*x)->degree == (*y)->degree && (*x)->next == NULL && (*y)->next == NULL) // O(1) == O(log 2) bcz there are 2 roots
    {
        if ((*x)->data < (*y)->data) // assuming that no data can be equal
        {
            if ((*x)->degree > 0)
            {
                (*y)->next = (*x)->exleftchld;
            }
            (*y)->parent = *x;
            (*x)->exleftchld = *y;
            (*x)->degree++;
            *y = NULL; // so that it cant be accessed
        }
        else
        {
            if ((*y)->degree > 0)
            {
                (*x)->next = (*y)->exleftchld;
            }
            (*x)->parent = *y;
            (*y)->exleftchld = *x;
            (*y)->degree++;
            *x = NULL; // so that it cant be accessed
        }
    }
    else if ((*x)->degree != (*y)->degree && (*x)->next == NULL && (*y)->next == NULL)
    {
        if ((*x)->degree < (*y)->degree)
        {
            (*x)->next = *y;
        }
        else
        {
            (*y)->next = *x;
        }
    }
    else
    {
        // first unite the heaps in ascending order of degree
        binoheap *min = NULL, *max = NULL, *backup = NULL, *mer = NULL;

        if ((*x)->degree < (*y)->degree)
        {
            min = *x;
            mer = *x;
            max = *y;
        }
        else if ((*x)->degree > (*y)->degree)
        {
            min = *y;
            mer = *y;
            max = *x;
        }
        else // if degree equal then compare on the basis of siblings
        {
            if ((*x)->next == NULL && (*y)->next != NULL)
            {
                min = *x;
                mer = *x;
                max = *y;
            }
            else
            {
                min = *y;
                mer = *y;
                max = *x;
            }
        }

        // merge like merging algo of mergesort
        while (min->next != NULL && max->next != NULL) // atleast 2 roots in each heap
        {
            if (min->next->degree <= max->degree)
            {
                min = min->next;
            }
            else
            {
                backup = min->next;
                min->next = max;
                min = max;
                max = backup;
            }
        }

        while (min->next != NULL)
        {
            min = min->next;
        }
        min->next = max;

        // now merging same degree nodes

//reverse linked list

        while (mer->next != NULL)  //use mer only for traversal use other pointers for modification
        {
            if (mer->degree == mer->next->degree)
            {
                max=mer;
                if(mer->data>mer->next->data)
                {
                    mer=mer->next;
                }
                backup = max->next;
                min = max->next->next;
                max->next = NULL;
                backup->next = NULL;
                merge(&max, &backup);
                mer->next=min; 
            }
            mer=mer->next;
        }
    }
}