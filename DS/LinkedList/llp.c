#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    char *sensorium;
    struct linkedlist *next;
} sensate;
void swapstr(char **, char **);
void sensert(sensate **, char *, char *); // double pointer isliye pass karta hu kyuki head k contents change karne hai agar single pointer karta to return head karna padta aur program me head=node* f(node*) likhna padta
void sensplay(sensate *);
void lobotomize(sensate **, char *);
void sensort(sensate *); // based on first letter of names
void serever(sensate **);
int howMany(sensate *);
int main()
{

    sensate *angelica = malloc(sizeof(sensate));
    angelica->sensorium = "Will Gorski";
    angelica->next = NULL;
    sensert(&angelica, "Riley Blue", "end");
    sensert(&angelica, "Lito Rodriguez", "end");
    sensert(&angelica, "Wolfgang", "end");
    sensert(&angelica, "Raoul", "end");
    serever(&angelica);
    sensplay(angelica);
    return 0;
}
void sensert(sensate **x, char *name, char *choice)
{
    sensate *new = malloc(sizeof(sensate));
    new->sensorium = name;
    sensate *temp = *x;
    if (choice == "end") //inserting in end can also be done by passing sensate* because we're not actually changing contents of any pointer
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
    else if (choice == "beginning")
    {
        new->next = *x;
        *x = new;
    }
    else if (choice == "middle")
    {
        if (howMany(*x) > 1)
        {
            printf("enter the position in between %d,%d to add %s\n", 1, howMany(*x) - 1, name);
            int pos;
            scanf("%d", &pos);
            int j = 0;
            sensate *temp = *x;
            while (j != pos - 1)
            {
                j++;
                temp = temp->next;
            }
            new->next = temp->next;
            temp->next = new;
        }
        else
        {
            printf("unable to sensert a new next\n");
        }
    }
}
void sensplay(sensate *x)
{
    sensate *temp = x;
    while (temp != NULL)
    {
        printf("%s\n", temp->sensorium);
        temp = temp->next;
    }
}
int howMany(sensate *x)
{
    int i = 0;
    sensate *temp = x;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}
void lobotomize(sensate **x, char *name)
{
    sensate *temp = *x;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (temp->sensorium == name)
        {
            break;
        }
        temp = temp->next;
    }
    sensate *del = *x;
    if (count == 1)
    {
        *x = (*x)->next;
        free(temp);
    }
    else if (count == howMany(*x) && howMany(*x) > 1)
    {
        while (del->next->next != NULL)
        {
            del = del->next;
        }
        free(del->next);
        del->next = NULL;
    }
    else
    {
        while (del->next != temp)
        {
            del = del->next;
        }
        del->next = del->next->next;
        free(temp);
    }
}
void sensort(sensate *x) // bubble sort
{
    sensate *i = x;
    sensate *j = NULL;
    while (i != NULL)
    {
        j = i;
        while (j != NULL)
        {

            if (i->sensorium[0] > j->sensorium[0])
            {
                swapstr(&(i->sensorium), &(j->sensorium));
            }
            j = j->next;
        }

        i = i->next;
    }
}
void swapstr(char **x, char **y)
{
    char *temp = *x;
    *x = *y;
    *y = temp;
}
void serever(sensate **x)
{
    sensate *i = *x;
    sensate *j = NULL;
    sensate *k = NULL;
    while (i != NULL)
    {
        j = i->next;
        i->next = k;
        k = i;
        i = j;
    }
    *x = k;
}