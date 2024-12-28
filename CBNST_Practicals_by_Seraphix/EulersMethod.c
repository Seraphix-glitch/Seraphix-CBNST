#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    return x + y;
}
int main()
{
    float a, b, xn, h;
    int n;
    printf("Enter a  and b : \n");
    scanf("%f%f", &a, &b);
    printf("Enter the number of intervals: \n");
    scanf("%d", &n);
    float c;
    printf("Enter the calculating point\n");
    scanf("%f", &c);
    h = (c - a) / n;
    float y = b;
    printf("x\ty\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%f\t%f \n", a, y);
        y = y + h * f(a, y);
        a += h;
    }
    return 0;
}