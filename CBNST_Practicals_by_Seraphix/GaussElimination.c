#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &n);
    float arr[n][n + 1], value[n];
    printf("Enter the matrix\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)
            {
                float ratio = arr[j][i] / arr[i][i];
                for (int k = 0; k < n + 1; k++)
                {
                    arr[j][k] = arr[j][k] - (ratio * arr[i][k]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }

    value[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        float sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum = sum + arr[i][j] * value[j];
        }
        value[i] = (arr[i][n] - sum) / arr[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%f ", value[i]);
    }
    return 0;
}