#include <stdio.h>

int main()
{
    int n;
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, a, b;
    printf("Enter the total points\n");
    scanf("%d", &n);
    float x[n];
    float y[n];
    printf("x values\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("y values\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sum1 += x[i];
        sum2 += y[i];
        sum3 += (x[i] * y[i]);
        sum4 += (x[i] * x[i]);
    }
    float table[2][3];
    table[0][0] = n;
    table[0][1] = sum1;
    table[0][2] = sum2;
    table[1][0] = sum1;
    table[1][1] = sum4;
    table[1][2] = sum3;

    float ratio = table[1][0] / table[0][0];
    for (int i = 0; i < 3; i++)
    {
        table[1][i] -= ratio * table[0][i];
    }
    printf("The upper triangular matrix is \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f ", table[i][j]);
        }
        printf("\n");
    }
    b = table[1][2] / table[1][1];
    a = (table[0][2] - table[0][1] * b) / (table[0][0]);
    printf("intercept %f , slope %f\n", a, b);
    return 0;
}