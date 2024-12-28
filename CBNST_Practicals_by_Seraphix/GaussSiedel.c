#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int n;
float aerr;

int diagonallyDominant(float a[n][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        float sum = 0.0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                sum += fabs(a[i][j]);
            }
        }
        if (sum >= a[i][i])
            return 0;
    }
    return 1;
}

void findValue(float a[n][n + 1], float old_values[n])
{
    float new_values[n];
    for (int i = 0; i < n; i++)
    {
        new_values[i] = 0;
    }
    int itr = 0;
    while (1)
    {
        itr++;
        for (int i = 0; i < n; i++)
        {
            float sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum += (a[i][j] * new_values[j]);
                }
            }
            new_values[i] = (a[i][n] - sum) / a[i][i];
        }

        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (fabs(new_values[i] - old_values[i]) <= aerr)
            {
                continue;
            }
            else
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            printf("After %d iterations, final values of roots are: \n", itr);
            for (int i = 0; i < n; i++)
            {
                printf("x%d = %.4f\n", i + 1, new_values[i]);
            }
            return;
        }

        printf("After %d iteration, the values of roots are: \n", itr);
        for (int i = 0; i < n; i++)
        {
            printf("x%d = %.4f\n", i + 1, new_values[i]);
        }

        for (int i = 0; i < n; i++)
        {
            old_values[i] = new_values[i];
        }
    }
}

int main()
{
    printf("Enter the number of unknowns.\n");
    scanf("%d", &n);
    float a[n][n + 1];
    float old_values[n];

    printf("Enter the augmented matrix.\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n + 1); j++)
        {
            printf("Enter a[%d][%d] : ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    printf("Enter the allowed error.\n");
    scanf("%f", &aerr);

    for (int i = 0; i < n; i++)
    {
        old_values[i] = 0.0;
    }

    if (diagonallyDominant(a) == 0)
    {
        printf("The matrix is not diagonally dominant. Kindly rearrange the matrix.\n");
        exit(0);
    }

    findValue(a, old_values);
    return 0;
}
