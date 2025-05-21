#include <stdio.h>
#include <stdlib.h>
#define num 4
typedef struct mem_ref
{
    int value;
    int time;
} mem;

int main()
{
    int frame[num] = {-1, -1, -1, -1};  //this array stores the time of arrival of respective reference
    int n;
    printf("Enter the number of string references\n");
    scanf("%d", &n);
    mem ref_str[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter ");
        scanf("%d", &(ref_str[i].value));
        ref_str[i].time = i;
    }
    int filled = 0;

    int page_faults = 0;

    for (int i = 0; i < n; i++)
    {
        if (filled <= num && filled > 0)
        {
            if (filled != num)
            {
                int j = 0;
                for (j = 0; j < filled; j++)
                {
                    if (ref_str[frame[j]].value == ref_str[i].value)
                    {
                        frame[j] = ref_str[i].time;
                        break;
                    }
                    if (j == filled - 1)
                    {
                        frame[j + 1] = ref_str[i].time;
                        filled++;
                        page_faults++;
                    }
                }
            }
            else
            {
                int j = 0;
                for (j = 0; j < filled; j++)
                {
                    if (ref_str[frame[j]].value == ref_str[i].value)
                    {
                        frame[j] = ref_str[i].time;
                        break;
                    }
                    if (j == filled - 1)
                    {
                        for (int k = 0; k < num - 1; k++)
                        {
                            frame[k] = frame[k + 1];
                        }
                        frame[num - 1] = ref_str[i].time;
                        page_faults++;
                    }
                }
            }
        }
        else if (filled == 0)
        {
            frame[0] = ref_str[i].time;
            filled++;
            page_faults++;
        }
    }

    for (int i = 0; i < num; i++)
    {

        printf("%d\n", frame[i]);
    }

    printf("The total number of page faults is %d", page_faults);
    return 0;
}
