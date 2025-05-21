#include <stdio.h>
#include <math.h>
int eudist(int, int);
void swap(int *, int *);
int main()
{

    printf("\n\nWe are now predicting the class of the validation data (to check the accuracy) and test data\n\n\n");
    /*storing the training data in form of 4x4 matrix in the format
    S No.,number of comedy scenes,number of action scenes, and actual class
    */
    // taking action as 0 and comedy as 1
    int tdata[4][4] = {1, 100, 0, 1, 2, 0, 100, 0, 3, 15, 90, 0, 4, 85, 20, 1};
    // storing validation data and test data in the same format
    // validation data is used to check accuracy of predicted class
    int vdata[2][4] = {1, 10, 95, 0, 2, 85, 15, 1};
    int testd[3][3] = {1, 6, 70, 2, 93, 23, 3, 50, 50};
    // taking k as 1 (given)
    /*now calculating the square of the euclidean distance between each entry of training data and each entry of validation data and
    storing the  data in a 20x4 matrix to predict the class of the validation data in the format as: S no.,vdata,tdata & euclidean distance*/
    int eudis[20][4];
    for (int i = 0; i < 4; i++) // for 1st movie of validation data

    {
        eudis[i][0] = i + 1;
        eudis[i][1] = 1;
        eudis[i][2] = i + 1;
        eudis[i][3] = eudist(tdata[i][1] - vdata[0][1], tdata[i][2] - vdata[0][2]);
    }
    for (int m = 4; m < 8; m++) // for 2nd movie of validation data
    {
        eudis[m][0] = m;
        eudis[m][1] = 2;
        eudis[m][2] = m - 3;
        eudis[m][3] = eudist(tdata[m - 4][1] - vdata[1][1], tdata[m - 4][2] - vdata[1][2]);
    }
    for (int w = 8; w < 12; w++) // for 1st movie of test data
    {
        eudis[w][0] = w;
        eudis[w][1] = 3;
        eudis[w][2] = w - 7;
        eudis[w][3] = eudist(tdata[w - 8][1] - testd[0][1], tdata[w - 8][2] - testd[0][2]);
    }
    for (int x = 12; x < 16; x++) // for 2nd movie of test data
    {
        eudis[x][0] = x;
        eudis[x][1] = 4;
        eudis[x][2] = x - 11;
        eudis[x][3] = eudist(tdata[x - 12][1] - testd[1][1], tdata[x - 12][2] - testd[1][2]);
    }
    for (int z = 16; z < 20; z++) // for 3rd movie of test data
    {
        eudis[z][0] = z;
        eudis[z][1] = 5;
        eudis[z][2] = z - 15;
        eudis[z][3] = eudist(tdata[z - 16][1] - testd[2][1], tdata[z - 16][2] - testd[2][2]);
    }
    // then we store the squares of respective euclidean distances in 1D arrays to sort it

    int temp1[4]; // for 1st movie dataset of the validation data
    int temp2[4]; // for 2nd movie dataset of the validation data
    int temp3[4]; // for 1st movie dataset of the test data
    int temp4[4]; // for 2nd movie dataset of the test data
    int temp5[4]; // for 3rd movie dataset of the test data

    for (int p = 0; p < 4; p++)
    {
        temp1[p] = eudis[p][3];
        temp2[p] = eudis[p + 4][3];
        temp3[p] = eudis[p + 8][3];
        temp4[p] = eudis[p + 12][3];
        temp5[p] = eudis[p + 16][3];
    }

    // then we sort them

    for (int j = 0; j < 4; j++)
    {
        for (int k = 0; k < 4; k++)
        {
            if (temp1[j] > temp1[k])
            {
                swap(&temp1[j], &temp1[k]);
            }
            if (temp2[j] > temp2[k])
            {
                swap(&temp2[j], &temp2[k]);
            }
            if (temp3[j] > temp3[k])
            {
                swap(&temp3[j], &temp3[k]);
            }
            if (temp4[j] > temp4[k])
            {
                swap(&temp4[j], &temp4[k]);
            }
            if (temp5[j] > temp5[k])
            {
                swap(&temp5[j], &temp5[k]);
            }
        }
    }

    for (int v = 0; v < 4; v++)
    {
        if (eudis[v][3] == temp1[3])
        {
            switch (v)
            {
            case 0:
                printf("The predicted genre of the first movie of validation data is COMEDY\n\n");
                break;
            case 1:
                printf("The predicted genre of the first movie of validation data is ACTION\n\n");
                break;
            case 2:
                printf("The predicted genre of the first movie of validation data is ACTION\n\n");
                break;
            case 3:
                printf("The predicted genre of the first movie of validation data is COMEDY\n\n");
            default:
                break;
            }
        }

        if (eudis[v + 4][3] == temp2[3])
        {
            switch (v)
            {
            case 0:
                printf("the predicted genre of second movie of validation data is COMEDY\n\n");
                break;
            case 1:
                printf("the predicted genre of second movie of validation data is ACTION\n\n");
                break;
            case 2:
                printf("the predicted genre of second movie of validation data is ACTION\n\n");
                break;
            case 3:
                printf("the predicted genre of second movie of validation data is COMEDY\n\n");
                break;
            default:
                break;
            }
        }
        if (eudis[v + 8][3] == temp3[3])
        {
            switch (v)
            {
            case 0:
                printf("the predicted genre of first movie of test data is COMEDY\n\n");
                break;
            case 1:
                printf("the predicted genre of first movie of test data is ACTION\n\n");
                break;
            case 2:
                printf("the predicted genre of first movie of test data is ACTION\n\n");
                break;
            case 3:
                printf("the predicted genre of first movie of test data is COMEDY\n\n");
                break;
            default:
                break;
            }
        }
        if (eudis[v + 12][3] == temp4[3])
        {
            switch (v)
            {
            case 0:
                printf("the predicted genre of second movie of test data is COMEDY\n\n");
                break;
            case 1:
                printf("the predicted genre of second movie of test data is ACTION\n\n");
                break;
            case 2:
                printf("the predicted genre of second movie of test data is ACTION\n\n");
                break;
            case 3:
                printf("the predicted genre of second movie of test data is COMEDY\n\n");
                break;
            default:
                break;
            }
        }
        if (eudis[v + 16][3] == temp5[3])
        {
            switch (v)
            {
            case 0:
                printf("the predicted genre of third movie of test data is COMEDY\n\n");
                break;
            case 1:
                printf("the predicted genre of third movie of test data is ACTION\n\n");
                break;
            case 2:
                printf("the predicted genre of third movie of test data is ACTION\n\n");
                break;
            case 3:
                printf("the predicted genre of third movie of test data is COMEDY\n\n");
                break;
            default:
                break;
            }
        }
    }

    return 0;
}
int eudist(int x, int y)
{
    return pow(x, 2) + pow(y, 2);
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}