#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct BOOK
{
    int pages;
    char author[20];
    char genre[10];
    char name[20];
    int qty;
} book;

int main(int argc, char **argv)
{
    FILE *ptr = NULL;
    char ch;
    int serial = -1;
    ptr = fopen("record.txt", "r");
    if (ptr == NULL)
    {
        exit(1);
    }
    do
    {
        ch = fgetc(ptr);
        
        if (ch == '\n')
        {
            serial++;
        }
    } while (ch != EOF);
    fclose(ptr);
    while (1)
    {
        char choice;
        printf("\n\n\nBOOK INVENTORY\n\n*DISPLAY CATALOGUE(D)\n*SEARCH(S)\n*ADD(A)\n*DELETE(d)\n*ISSUE(I)\n*EXIT(E)\n");
        scanf("%c", &choice);
        switch (choice)
        {
        case 'D':
            ptr = fopen("record.txt", "r");
            if (ptr == NULL)
            {
                exit(1);
            }
            do
            {
                ch = fgetc(ptr);
                printf("%c", ch);
            } while (ch != EOF);
            fclose(ptr);
            break;
        case 'A':

            ptr = fopen("record.txt", "a");

            serial++;
            book b1;
            getchar();
            printf("Enter the name of the book\n");
            scanf("%[^\n]s", b1.name);
            fprintf(ptr, "%d. %s  ", serial, b1.name);
            getchar();
            printf("Enter the name of the author of the book\n");
            scanf("%[^\n]s", b1.author);
            fprintf(ptr, "%s  ", b1.author);
            getchar();
            printf("Enter the genre of the book\n");
            scanf("%[^\n]s", b1.genre);
            fprintf(ptr, "%s  ", b1.genre);
            getchar();
            printf("Enter the number of pages of this book\n");
            scanf("%d", &b1.pages);
            fprintf(ptr, "%d  ", b1.pages);
            printf("Enter the number of these books\n");
            scanf("%d", &b1.qty);
            fprintf(ptr, "%d\n", b1.qty);
            fclose(ptr);
            break;
        case 'd':
            getchar();
            char todelete[20];
            printf("\nEnter a keyword to search\n");
            scanf("%s", todelete);
            ptr = fopen("record.txt", "r+");

            if (ptr == NULL)
            {
                exit(1);
            }
            int l = 0;
            int length = strlen(todelete);
            do
            {
                ch = fgetc(ptr);
                if (ch != todelete[l])
                {
                    l = 0;
                }
                else
                {
                    l++;
                }
                if (l == length)
                {

                    printf("\nFOUND\nNow Deleting\n");
                    while (ch != '\n')
                    {
                        ch = fgetc(ptr);
                    }
                    break;
                }

            } while (ch != EOF && l < length);
            if (ch == EOF)
            {
                printf("NOT FOUND");
            }
            else
            {
                fseek(ptr, -4, SEEK_CUR);
                ch = fgetc(ptr);
                while (ch != '\n')
                {
                    fseek(ptr, -2, SEEK_CUR);
                    printf("seeked\n");
                    ch = fgetc(ptr);
                }

                char delchar = fgetc(ptr);
                int indexdel = 0;
                char delete[60];
                while (delchar != '\n')
                {
                    delete[indexdel++] = delchar;
                    delchar = fgetc(ptr);
                }

                FILE *temp = fopen("temp.txt", "w");
                rewind(ptr);
                ch = fgetc(ptr);
                int d = 0;
                printf("%d\n", strlen(delete));
                while (ch != EOF)
                {
                    if (ch != delete[d])
                    {
                        if (d != strlen(delete))
                        {
                            fputc(ch, temp);
                        }
                        d = 0;
                    }
                    else
                    {
                        d++;
                    }
                    ch = fgetc(ptr);
                }
                fclose(temp);
            }
            fclose(ptr);
            remove("record.txt");
            rename("temp.txt","record.txt");
            break;
        case 'S':
            getchar();
            char exp[20];
            printf("\nEnter a keyword to search\n");
            scanf("%s", exp);
            ptr = fopen("record.txt", "r");
            if (ptr == NULL)
            {
                exit(1);
            }
            int j = 0;
            do
            {
                ch = fgetc(ptr);
                if (ch != exp[j])
                {
                    j = 0;
                }
                else
                {
                    j++;
                }

                if (j == strlen(exp))
                {
                    printf("\nFOUND\n\n%s", exp);
                    while (ch != '\n')
                    {
                        ch = fgetc(ptr);
                        printf("%c", ch);
                    }
                    break;
                }

            } while (ch != EOF && j < strlen(exp));
            if (ch == EOF)
            {
                printf("NOT FOUND");
            }
            fclose(ptr);
            break;

        case 'E':
            goto label;
            break;

        default:
            printf(" ch case INVALID CHOICE %d", ch);
            break;
        }
        getchar();
    }
label:
    return 0;
}