#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float arr[n][n + 1]; 
    printf("Enter the values of x:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i][0]);
    }

    printf("Enter the values of y:\n");
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
    printf("Enter the value of x: ");
    scanf("%f", &x);

    float a = arr[n - 1][0];        
    float h = arr[1][0] - arr[0][0]; 
    float u = (x - a) / h;
    float u1 = u;
    float y = arr[n - 1][1]; 
    int fact = 1;
    int j = 2;

    for (int i = n - 2; i >= 0; i--)
    {
        y += (u1 * arr[i][j]) / fact;
        fact *= j;
        u1 *= (u + (j - 1)); 
        j++;
    }

    printf("Value at x = %f is %f\n", x, y);
    return 0;
}
