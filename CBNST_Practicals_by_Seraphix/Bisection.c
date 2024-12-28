#include <stdio.h>
#include <math.h>

float f(float x)
{
    float eq = (x * x * x) - x - 1;
    return eq;
}
float f1(float x)
{
    float eq = x * log10(x) - 1.2;
    return eq;
}

int main()
{
    float a, b;
    float aerr;
    int flag = 0;

    do
    {
        printf("Enter a and b\n");
        scanf("%f%f", &a, &b);
        if (a < b && (f1(a) * f1(b) < 0))
        {
            printf("Root lies between %f and %f \n\n", a, b);
            flag = 1;
        }
    } while (flag != 1);
    printf("Enter the allowed error\n");
    scanf("%f", &aerr);

    int itr = 0;

    do
    {
        itr++;
        float x = (a + b) / 2.0;
        printf("Iteration %d | The value of x : %f | value of f(x) is : %f \n", itr, x, f(x));
        if (fabs(f1(x)) <= aerr)
        {
            flag = 0;
            printf("The root of the given equation is %.4f\n\n", x);
        }
        else if (f1(a) * f1(x) < 0)
        { 
            b = x;
        }
        else
        {
            a = x;
        }
    } while (flag != 0);
    return 0;
}