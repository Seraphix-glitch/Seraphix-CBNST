#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    float X[n], Y[n];

    printf("Enter the values of x\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &X[i]);
    }
    printf("Enter the values of y\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &Y[i]);
    }
    float x;
    float sum;
    printf("Entert the value of x\n");
    scanf("%f", &x);
    for (int i = 0; i < n; i++)
    {
        int term = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                term = term * ((x - X[j]) / (X[i] - X[j]));
            }
        }
        sum += term * Y[i];
    }
    printf("THe answer is %f\n", sum);
    return 0;
}