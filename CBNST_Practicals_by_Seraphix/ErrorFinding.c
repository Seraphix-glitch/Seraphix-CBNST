#include <stdio.h>
#include <math.h>

int main()
{
    /*
    float a = 1.414;
    float b = sqrt(2);

    float absError = fabs(b - a);
    float reError = absError / b;
    float peError = reError * 100;
    printf("%f , %f , %f \n", absError, reError, peError);
    */

    float realValue = 1.0 / 3.0;
    float a = 0.30, b = 0.33, c = 0.34;

    float abs1 = fabs(realValue - a);
    float abs2 = fabs(realValue - b);
    float abs3 = fabs(realValue - c);

    if (abs1 <= abs2 && abs1 <= abs3)
    {
        printf("the best approximation is %f \n", abs1);
    }

    else if (abs2 <= abs1 && abs2 <= abs3)
    {
        printf("the best approximation is %f \n", abs2);
    }

    else
    {
        printf("the best approximation is %f \n", abs3);
    }

    return 0;
}