#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float f(float x)
{
    return (2 * x - (log10(x)) - 7);
}
float g(float x)
{
    return (7 + log10(x)) / 2.0;
}
float d(float x)
{
    return (1 / (2 * x * log(10)));
}

int main()
{
    float x, x1;
    int itr = 0;
    while (1)
    {
        printf("Enter the value of x0.\n");
        scanf("%f", &x);
        x1 = d(x);
        if (fabs(x1) < 1)
        {
            printf("Continued to the further process.\n");
            break;
        }
        else
        {
            printf("Change the g(x) and d(x) further and try again.\n");
            exit(0);
        }
    }
    float aerr;
    printf("Enter the allowed error.\n");
    scanf("%f", &aerr);

    float y;
    while (1)
    {
        itr++;
        y = g(x);
        if (fabs(y - x) <= aerr)
        {
            break;
        }
        else
        {
            x = y;
        }
        printf("After %d iteration, the root is %f.\n", itr, y);
    }
    printf("After %d iteration, the root is %f.\n", itr, y);
    return 0;
}
