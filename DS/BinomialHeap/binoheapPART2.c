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
binoheap *merge(binoheap *, binoheap *); // to merge binomial heaps
binoheap *insert(binoheap *, int);
binoheap *delete(binoheap *);
void reverse_roots(binoheap **);

void DISPLAY(binoheap *); //complete this fucntion

int main()
{
    binoheap *BINO_HEAP = insert(insert(insert(insert(insert(insert(createNode(67), 23), 15), 34), 56), 89), 1);
    binoheap *after_deletion = delete (BINO_HEAP);

DISPLAY(after_deletion);

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

binoheap *merge(binoheap *x, binoheap *y)
{
    if (x->degree == y->degree && x->next == NULL && y->next == NULL) // merging binomial heaps with single root of same degree
    {
        if (x->data < y->data) // assuming that no data can be equal
        {
            if (x->degree > 0)
            {
                y->next = x->exleftchld;
            }
            y->parent = x;
            x->exleftchld = y;
            x->degree++;
            return x;
        }
        else
        {
            if (y->degree > 0)
            {
                x->next = y->exleftchld;
            }
            x->parent = y;
            y->exleftchld = x;
            y->degree++;
            return y;
        }
    }
    else if (x->degree != y->degree && x->next == NULL && y->next == NULL) // merging 2 binomial heaps of different degree with multiple roots(siblings)
    {
        if (x->degree < y->degree)
        {
            x->next = y;
            return x;
        }
        else
        {
            y->next = x;
            return y;
        }
    }
    else
    {
        // first unite the heaps in ascending order of degree
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
        else // if degree equal then compare on the basis of siblings
        {
            int count[2] = {0, 0};

            mer = x;
            head = y;

            while (mer != NULL)
            {
                count[0]++; // count x
                mer = mer->next;
            }
            while (head != NULL)
            {
                count[1]++; // count y
                head = head->next;
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

        while (mer->next != NULL) // use mer only for traversal use other pointers for modification
        {
            if (mer->degree == mer->next->degree)
            {
                max = mer;
                if (mer->data > mer->next->data)
                {
                    mer = mer->next;
                }
                backup = max->next;
                min = max->next->next;
                max->next = NULL;
                backup->next = NULL;
                head = merge(max, backup);
                head->next = min;
            }
            else
            {
                mer = mer->next;
            }
        }
        /*if(head->degree>head->next->degree)
        {
            reverse_roots(&head);
        }*/
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
        del = del->next;
    }
    del = root;
    if (del != min)
    {
        while (del->next != min) // finding predecessor
        {
            del = del->next;
        }
    }
    temp = del; // predecessor
    del = min->next;
    min->next = NULL;

    if (temp->data != min->data)
    {
        temp->next = NULL;
        min = min->exleftchld;
        free(min->parent);
        min->parent = NULL;
        ref = min;
        reverse_roots(&min);
        min->next = ref;
        ref->next = del;
        return merge(root, min);
    }
    else
    {
        if (min->exleftchld != NULL)
        {
            min = min->exleftchld;
            free(min->parent);
            min->parent = NULL;
            temp = min;
            reverse_roots(&min);
            temp->next = del;
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
    binoheap *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *x = prev;
}
