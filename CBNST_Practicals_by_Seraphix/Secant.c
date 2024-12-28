#include <stdio.h>
#include <math.h>

float f(float a)
{
    return (a * a * a) - (5 * a) + 1;
}

int main()
{
    float a, b, aerr;
    int flag = 0;
    do
    {
        printf("Enter a and b:\n");
        scanf("%f%f", &a, &b);
        if (a < b && (f(a) * f(b) < 0))
        {
            printf("True, Roots lies between %f and %f\n\n", a, b);
            flag = 1;
        }
        else
        {
            printf("Wrong Interval ,Try Again\n");
        }
    } while (flag != 1);

    printf("Enter allowed Error: ");
    scanf("%f", &aerr);
    int itr = 0;
    do
    {
        itr++;
        float x = b - f(b) * (b - a) / (f(b) - f(a));
        printf("Iteration %d | the value of x is : %f | Value of f(x) is : %f\n", itr , x , f(x));
        if(fabs(f(x))<= aerr){
            flag = 0;
            printf("The root of the equation is: %0.4f\n\n",x);
        }
        a = b;
        b = x;
    }while(flag != 0);
    return 0;
}