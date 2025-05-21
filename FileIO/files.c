#include<stdio.h>
#include<stdlib.h>
typedef F
int main()
{
FILE *ftext=fopen("C:\\Users\\Akshat\\Desktop\\LATEST.txt","x");
int a;
printf("enter a number\n");
scanf("%d",&a);
if (ftext==NULL)
{
    printf("file DNE");
    exit(1);
}
fprintf(ftext,"%d %d\n",a,a+2);

  fclose(ftext);
    return 0;
}
