#include <stdio.h>
int main()
{
    int n;
    printf("Enter the no of points\n");
    scanf("%d", &n);
    float x[n], y[n];
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
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_x2 += x[i] * x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
    }
    float slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    float intercept = (sum_y - slope * sum_x) / n;
    printf("intercept %f , slope %f", intercept, slope);
    return 0;
}