#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 3 * x - cosf(x) - 1;
}
float df(float x)
{
    return 3 + sinf(x);
}

int main()
{

    float a, b, aerr, x0;
    int flag = 0;
    do
    {
        printf("Enter the value of a and b : \n");
        scanf("%f%f", &a, &b);

        if (a < b && (f(a) * f(b) < 0))
        {
            flag = 1;
            printf("root lies between a and b\n");
            printf("Enter x0 between %f and %f \n", a, b);
            scanf("%f", &x0);
        }
        else
        {
            printf("Root does not lie between a and b\n");
        }
    } while (flag != 1);

    printf("Enter the allowed error\n");
    scanf("%f", &aerr);
    int itr = 0;
    do
    {
        itr++;
        float x = x0 - (f(x0) / df(x0));

        printf("Iteration %d | value of x is %f | value of f(x) %f \n", itr, x, f(x));

        if (fabs(f(x)) < aerr)
        {
            flag = 0;
            printf("The root of the given equation is %.4f \n\n", x);
        }
        else
        {
            x0 = x;
        }
    } while (flag != 0);
    return 0;
}