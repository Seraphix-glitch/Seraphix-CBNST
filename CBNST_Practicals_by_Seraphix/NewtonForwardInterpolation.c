#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the value of n \n");
    scanf("%d", &n);

    float arr[n][n + 1];

    printf("Enter the values of x\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i][0]);
    }

    printf("Enter the values of y\n");
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
    printf("Enter the value of x \n");
    scanf("%f", &x);

    float u = (x - arr[0][0]) / (arr[1][0] - arr[0][0]);
    float y = arr[0][1];
    float u1 = u;
    float fact = 1;
    for (int i = 2; i < n + 1; i++)
    {
        y = y + (u1 * arr[0][i]) / fact;
        fact = fact * i;
        u1 = u1 * (u - (i - 1));
    }
    printf("Value at x = %f is %f\n", x, y);
    return 0;
}
