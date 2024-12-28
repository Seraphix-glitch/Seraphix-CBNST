#include <stdio.h>

void convertToUpperTriangular(float arr[3][4], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)
            {
                float ratio = arr[j][i] / arr[i][i];
                for (int k = 0; k < n + 1; k++)
                {
                    arr[j][k] -= ratio * arr[i][k];
                }
            }
        }
    }
}

void backSubstitution(float arr[3][4], float values[3], int n)
{
    values[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        float sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += arr[i][j] * values[j];
        }
        values[i] = (arr[i][n] - sum) / arr[i][i];
    }
}

int main()
{
    int n;
    printf("Enter total number of points\n");
    scanf("%d", &n);
    float sx = 0, sy = 0, sxy = 0, sx2y = 0, sx2 = 0, sx3 = 0, sx4 = 0;
    float x[n];
    float y[n];
    printf("Enter the values of x\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("Enter the values of y\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sx += x[i];
        sx2 += (x[i] * x[i]);
        sx3 += (x[i] * x[i] * x[i]);
        sx4 += (x[i] * x[i] * x[i] * x[i]);
        sxy += (x[i] * y[i]);
        sx2y += (x[i] * x[i] * y[i]);
        sy += y[i];
    }
    float table[3][4] = {{n, sx, sx2, sy}, {sx, sx2, sx3, sxy}, {sx2, sx3, sx4, sx2y}};
    convertToUpperTriangular(table, 3);
    float value[3];
    backSubstitution(table, value, 3);
    printf("The values are %f , %f , %f", value[0], value[1], value[2]);
    return 0;
}