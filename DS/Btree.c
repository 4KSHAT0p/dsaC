/*
This program is not written entirely by me, it's written with the help of cormen
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define order 6
#define t (int)ceil((float)order / 2) // minimum degree of btree

typedef struct B
{
    int keys[order - 1], count;
    struct B *children[order];
    bool is_leaf;
} btree;

void INSERT_NON_FULL(btree **, int);
void SPLIT_CHILD(btree **, int);
void SPLIT_ROOT(btree **);
void INSERT(btree **, int);
void DELETE(btree **, int);
btree *SEARCH(btree *, int);
btree *createNode(void);

int main()
{
    btree *root = createNode(); // empty node
    INSERT(&root, 'A');
    INSERT(&root, 'G');
    INSERT(&root, 'F');
    INSERT(&root, 'B');
    INSERT(&root, 'K');
    // SPLIT_ROOT(&root);
    INSERT(&root, 'D');
    INSERT(&root, 'H');
    INSERT(&root, 'M');
    INSERT(&root, 'J');
    INSERT(&root, 'E');
    INSERT(&root, 'S');
    INSERT(&root, 'I');
    INSERT(&root, 'R');
    INSERT(&root, 'X');
    INSERT(&root, 'C');
    DELETE(&root, 'I');
    DELETE(&root, 'A');
    DELETE(&root, 'E');
    DELETE(&root, 'C');
    // t-1 keys left in both children of 'F'

    /*
                    F     J
                   / \   / \
                  /   \ /   \
                 B D  G H  K M R S X
    */

    INSERT(&root, 'L');

    /*

                        F     J     R
                       / \   / \   / \
                      /   \ /   \ /   \
                     B D  G H  K L M  S X

    */
    DELETE(&root, 'F');
    /*

                        F     J     R
                       / \   / \   / \
                      /   \ /   \ /   \
                     B D  G H  K L M  S X

    */

    return 0;
}

btree *createNode(void)
{
    btree *new = calloc(1, sizeof(btree));
    for (int i = 0; i < order - 1; i++)
    {
        new->keys[i] = -1;
    }
    for (int i = 0; i < order; i++)
    {
        new->children[i] = NULL;
    }
    new->count = 0;
    new->is_leaf = true;
    return new;
}

/*The procedure B-TREE-SPLIT-CHILD on the facing page takes as input a nonfull
internal node x (assumed to reside in main memory) and an index i such that x:ci
(also assumed to reside in main memory) is a full child of x.*/
void SPLIT_CHILD(btree **parent, int index)
{
    btree *y = (*parent)->children[index];
    btree *z = createNode();
    z->is_leaf = y->is_leaf; // if y is leaf then z is leaf and vice versa

    int i = 0;
    while (z->count != t - 1) // y must have t keys and z must have t-1 keys
    {
        z->keys[i] = y->keys[t + i];
        y->keys[t + i] = -1;
        y->count--;
        z->count++;
        i++;
    }

    if (!y->is_leaf) // shifting child's children to remain intact
    {
        for (int j = 0; j < t; j++)
        {
            z->children[j] = y->children[j + t];
            y->children[j + t] = NULL;
        }
    }

    for (int j = (*parent)->count; j > index; j--) // shifting parent's children to make room for new child
    {
        (*parent)->children[j + 1] = (*parent)->children[j];
        (*parent)->children[j] = NULL;
    }

    (*parent)->children[index + 1] = z;

    for (int j = (*parent)->count; j > index; j--) // make room for median key of y
    {
        (*parent)->keys[j] = (*parent)->keys[j - 1];
    }

    (*parent)->keys[index] = y->keys[t - 1];
    y->keys[t - 1] = -1;
    y->count--;
    (*parent)->count++;
}

void SPLIT_ROOT(btree **root)
{
    btree *s = createNode();
    s->is_leaf = false;
    s->children[0] = *root;
    *root = s;
    SPLIT_CHILD(&s, 0);
}

void INSERT_NON_FULL(btree **root, int x)
{
    int i = (*root)->count - 1;

    if ((*root)->is_leaf)
    {
        while (i >= 0 && (*root)->keys[i] > x)
        {
            (*root)->keys[i + 1] = (*root)->keys[i];
            i--;
        }
        (*root)->keys[i + 1] = x;
        (*root)->count++;
    }
    else
    {
        while (i >= 0 && (*root)->keys[i] > x)
        {
            i--;
        }
        i++;
        if ((*root)->children[i]->count == order - 1)
        {
            SPLIT_CHILD(root, i);
            if (x > (*root)->keys[i])
            {
                i++;
            }
        }
        INSERT_NON_FULL(&((*root)->children[i]), x);
    }
}

void INSERT(btree **root, int k)
{
    if ((*root)->count == order - 1)
    {
        SPLIT_ROOT(root);
    }
    INSERT_NON_FULL(root, k);
}

btree *SEARCH(btree *root, int k)
{
    int i = 0;
    while (i < root->count && k > root->keys[i])
    {
        i++;
    }
    if (i < root->count && root->keys[i] == k)
    {
        // printf("%c is present.\n", k);
        return root;
    }
    else if (root->is_leaf)
    {
        return NULL;
    }
    else
    {
        return SEARCH(root->children[i], k);
    }
}

void DELETE(btree **root, int key)
{
    btree *delNode = SEARCH(*root, key);
    int i = 0;
    if (delNode == NULL)
    {
        printf("ELEMENT NOT PRESENT\n");
        return;
    }
    else if (delNode->count < t)
    {
        printf("ELEMENT IS PRESENT BUT UNABLE TO DELETE\n");
        return;
    }
    else
    {
        for (i = 0; i < delNode->count; i++) // index found
        {
            if (delNode->keys[i] == key)
            {
                break;
            }
        }
    }

    if (delNode->is_leaf)
    {
        int j;
        for (j = i; j < order - 2; j++)
        {
            delNode->keys[j] = delNode->keys[j + 1];
        }
        delNode->keys[delNode->count - 1] = -1;
        delNode->count--;
    }
    else if (!delNode->is_leaf) // internal node
    {
        if (delNode->children[i]->count >= t)
        {
            delNode->keys[i] = delNode->children[i]->keys[delNode->children[i]->count - 1];
            delNode->children[i]->keys[delNode->children[i]->count - 1] = -1;
            delNode->children[i]->count--;
        }
        else if (delNode->children[i + 1]->count >= t)
        {
            delNode->keys[i] = delNode->children[i + 1]->keys[0];
            for (int k = 0; k < delNode->children[i + 1]->count - 1; k++)
            {
                delNode->children[i + 1]->keys[k] = delNode->children[i + 1]->keys[k + 1];
                if (k + 1 == delNode->children[i + 1]->count - 1)
                {
                    delNode->children[i + 1]->keys[k + 1] = -1;
                    delNode->children[i + 1]->count--;
                }
            }
        }
        else // both children have minimum keys = t-1
        {
            int l = 0;
            while (delNode->children[i + 1]->count != 0)
            {
                delNode->children[i]->keys[l + t - 1] = delNode->children[i + 1]->keys[l];
                delNode->children[i]->count++;
                delNode->children[i + 1]->keys[l] = -1;
                delNode->children[i + 1]->count--;
                l++;
            }

            free(delNode->children[i + 1]);
            delNode->children[i + 1] = NULL;

            for (int j = i + 1; j < delNode->count; j++)
            {
                delNode->children[j] = delNode->children[j + 1];
            }

            delNode->children[delNode->count] = NULL;
            delNode->is_leaf = true;
            DELETE(&delNode, key);
            delNode->is_leaf = false;
        }
    }
}

//progress can be done in this code but i won't do it 