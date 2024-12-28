#include <stdio.h>
float f(float a)
{
    return 1 / (1 + a * a);
}
int main()
{
    float a;
    printf("Enter a : \n");
    scanf("%f", &a);
    float b;
    printf("Enter b : \n");
    scanf("%f", &b);
    int n;
    printf("Enter the number of intervals\n");
    scanf("%d", &n);
    float h = (b - a) / n;
    float sum = f(a) + f(b);
    for (float i = a + h; i < b; i = i + h)
    {
        if ((int)i % 2 == 0)
        {
            sum += 2 * (f(i));
        }
        else
        {
            sum += 4 * (f(i));
        }
    }
    sum = (h * sum) / 3;
    printf("the answer is %f\n", sum);
    return 0;
}