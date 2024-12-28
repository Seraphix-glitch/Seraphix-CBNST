#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float f(float a) {
    return exp(sin(a)); 
}

int main() {
    float a = 0;           
    float b = M_PI / 2.0;   
    int n;

    printf("Enter the number of intervals (multiple of 3): \n");
    scanf("%d", &n);

    if (n % 3 != 0) {
        printf("Number of intervals must be a multiple of 3 for Simpson's 3/8 rule.\n");
        return 1;
    }

    float h = (b - a) / n;
    float sum = f(a) + f(b);

    for (int k = 1; k < n; k++) {
        float x = a + k * h; 

        if (k % 3 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 3 * f(x); 
        }
    }

    sum = (3 * h / 8) * sum; 
    printf("The integral value is: %f\n", sum);

    return 0;
}
