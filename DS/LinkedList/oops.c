#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct info
{
    char *name;
    int rn;
    struct info *next;
} info;
void LDISPLAY(info *);
void LINSERT(info **, char *, int);
void LDELETE(info **, int);
void LSEARCH(info *, int);
void LSORT(info *);
void LREV(info **);
int main()
{
    char *p_name = malloc(20 * sizeof(char));
    int a;
    // declaring head
    info *first = malloc(sizeof(info));
    info *head = first; // head pointing to first element
    // growing the list
    printf("enter elements(name and roll number of students) to grow linked list\n");
    char another = 'Y';
    info *temp = first; // temporary variable to grow the list
    while (another == 'Y')
    {
        printf("\nEnter name\n");
        temp->name = malloc(20 * sizeof(char));
        scanf("%[^\n]s", temp->name);
        temp->name = realloc(temp->name, strlen(temp->name));
        printf("Enter roll number\n");
        scanf("%d", &temp->rn);
        getchar();
        printf("Do you want to enter more ?\n");
        another = getchar();
        if (another == 'Y')
        {
            temp->next = malloc(sizeof(info));
            temp = temp->next;
        }
        else
        {
            temp->next = NULL;
        }
        getchar();
    }

    while (1)
    {
        printf("\n\nWhat operation do want to perform ?\n\nInsert at beginning(i)\nDelete a node based on roll number(d)\nSearch based on roll number(s)\nDisplay the linked list(D)\nShow the number of nodes(n)\nSort as per roll number(S)\nReverse the linked list(r)\nQuit(q)\n\n");
        char choice = getchar();
        switch (choice)
        {
        case 'i':
            getchar();
            printf("Enter name to add\n");
            scanf("%[^\n]s", p_name);
            printf("Enter roll number\n");
            scanf("%d", &a);
            LINSERT(&head, p_name, a);
            getchar();
            break;

        case 'd':
            printf("Enter the roll number of the student to be deleted\n");
            scanf("%d", &a);
            LDELETE(&head, a);
            getchar();
            break;

        case 's':
            printf("Enter the roll number you want to search\n");
            scanf("%d", &a);
            LSEARCH(head, a);
            getchar();
            break;

        case 'D':
            LDISPLAY(head);
            getchar();
            break;

        case 'q':
            goto label;

        case 'n':
            int count = 0;
            info *hel = head;
            while (hel != NULL)
            {
                count++;
                hel = hel->next;
            }
            printf("\nThe number of nodes is %d\n", count);
            getchar();
            break;

        case 'S':
            LSORT(head);
            getchar();
            break;

        case 'r':
            LREV(&head);
            getchar();
            break;
        }
    }

    info *freel = first;
    while (freel != NULL)
    {
        free(freel);
        freel = freel->next;
    }
    free(p_name);

label:
    return 0;
}

void LINSERT(info **x, char *y, int z)
{
    info *new = malloc(sizeof(info));
    new->name = y;
    new->rn = z;
    new->next = *x;
    *x = new;
}

void LDISPLAY(info *x)
{
    printf("The linked list is :\n");
    info *temp = x;
    while (temp != NULL)
    {
        printf("%s %d\n", temp->name, temp->rn);
        temp = temp->next;
    }
}

void LDELETE(info **x, int z)
{
    info *temp;
    if ((*x)->rn == z)
    {
        temp = *x;
        *x = (*x)->next;
        free(temp);
    }
    else
    {
        info *current = *x;
        while (current->next != NULL)
        {
            if (current->next->rn == z)
            {
                temp = current->next;
                current->next = current->next->next;
                free(temp);
                break;
            }
            else
            {
                current = current->next;
            }
        }
    }
}

void LSEARCH(info *x, int y)
{
    int v = 0;
    info *temp = x;
    while (temp != NULL)
    {
        if (temp->rn == y)
        {
            printf("IT'S PRESENT\n");
            break;
        }
        temp = temp->next;
        if (temp == NULL)
        {
            printf("IT'S NOT PRESENT");
        }
    }
}

void LSORT(info *x)
{
    info *current = x, *index = NULL;
    int temp;
    char *ntemp;
    if (x == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {

            index = current->next;

            while (index != NULL)
            {

                if (current->rn > index->rn)
                {
                    temp = current->rn;
                    ntemp = current->name;
                    current->rn = index->rn;
                    current->name = index->name;
                    index->rn = temp;
                    index->name = ntemp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void LREV(info **x)
{

    info *prev = NULL;
    info *current = *x;
    info *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *x = prev;
}