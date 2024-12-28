#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    return (y * y - x * x) / (y * y + x * x);
}
int main()
{
    float x0, y0, xn;
    int n;
    printf("Enter the initial value: \n");
    scanf("%f%f", &x0, &y0);
    printf("Enter the number of intervals\n");
    scanf("%d", &n);
    float x;
    printf("Enter the calculating point\n");
    scanf("%f", &x);
    float h = (x - x0) / n;
    float y = y0;
    float k1, k2, k3, k4;
    printf("x\t\ty\n");
    for (int i = 0; i <= n; i++)
    {
        y0 = y;
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + (h / 2), y0 + (k1 / 2));
        k3 = h * f(x0 + (h / 2), y0 + (k2 / 2));
        k4 = h * f(x0 + h, y0 + k3);
        y = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x0 = x0 + h;
        printf("%f\t%f\n", x0, y0);
    }
    return 0;
}