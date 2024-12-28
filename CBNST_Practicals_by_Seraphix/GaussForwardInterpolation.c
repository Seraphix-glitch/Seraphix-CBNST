#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    float arr[n][n + 1];
    printf("Enter the data points of x\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i][0]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i][1]);
    }

    for (int j = 2; j < n + 1; j++)
    {
        for (int i = 0; i < n - j + 1; i++)
        {
            arr[i][j] = arr[i + 1][j - 1] - arr[i][j - 1];
        }
    }
    float x;
    float absVal = __INT_MAX__;
    printf("Enter the value of x\n");
    scanf("%f", &x);
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        float diff = fabs(x - arr[i][0]);
        if (diff < absVal)
        {
            absVal = diff;
            index = i;
        }
    }
    float a = arr[index][0];
    float h = arr[1][0] - arr[0][0];
    float u = (x - a) / h;
    float u1 = u;
    int fact = 1;
    float y = arr[index][1];
    for (int i = 2; i <= n; i++)
    {
        y += (u1 * arr[index][i]) / fact;
        fact *= i;
        u1 *= (i % 2 == 0) ? (u - (i - 1)) : (u + (i - 2));
        if (i % 2 == 0)
            index--;
    }
    printf("%f\n", y);
}