#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n;
    printf("Enter the number of unknowns.\n");
    scanf("%d",&n);
    float a[n][n+1];
    float values[n];

    printf("Enter the elements of augmented matrix.\n");
    for( int i = 0; i<n; i++ )
    {
        for( int j = 0; j<(n+1); j++ )
        {
            printf("Enter value for a[%d][%d]: ",i,j);
            scanf("%f",&a[i][j]);
        }
    }

    for( int j = 0; j<n; j++ )
    {
        for( int i = 0; i<n; i++ )
        {
            if( i!=j )          
            {
                float ratio = a[i][j] / a[j][j];
                for( int k = 0; k<(n+1); k++ )
                {
                    a[i][k] = a[i][k] - (ratio * a[j][k]);
                }
            }
        }
    }

    printf("The diagonal matrix is below.\n");
    for( int i = 0; i<n; i++ )
    {
        for( int j = 0; j<(n+1); j++ )
        {
            printf("%.3f ",a[i][j]);
        }
        printf("\n");
    }

    for( int i = (n-1); i>=0; i-- )
    {
        values[i] = a[i][n] / a[i][i];
    }

    //print the unknowns.
    printf("Final Output.\n");
    for( int i = 0; i<n; i++ )
    {
        printf("x%d = %.3f\n",i+1,values[i]);
    }
}

