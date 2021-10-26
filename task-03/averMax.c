#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int t = 0;
    scanf("%d", &t);
    double* outputs = (double*) malloc(t*sizeof(double));

    for(int i = 0; i < t; i++)
    {
        int n = 0, k = 0;
        scanf("%d %d", &n, &k);
        double max = -1e10, min = 1e10, x = 0.0;

        for(int j = 0; j < n; j++)
        {
            scanf("%lf", &x);
            if(x > max)
            {
                //printf("%f replaced by %f\n", max, x);
                max = x;
            }
            
            if(x < min)
            {
                //printf("%f replaced by %f\n", min, x);
                min = x;
            }
        }

        if(k > 0)
        {   
            min = fabs(min);
            max = fabs(max);

            if(min > max)
            {
                outputs[i] = min;
                //printf("%f min\n", min);
            }
            else
            {
                outputs[i] = max;
                //printf("%f max k > 0\n", max);
            }
        }
        else
        {
            outputs[i] = max;
            //printf("%f max, k = 0\n", max);
        }

    }
    for(int i = 0; i < t; i++)
    {
        printf("%lf\n", outputs[i]);
    }

    free(outputs);
    return 0;
}
