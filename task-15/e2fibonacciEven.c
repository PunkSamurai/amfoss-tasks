#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
    int t; 
    scanf("%d",&t);
    long long * outputs = (long long*) malloc(t*sizeof(long long));
    for(int a = 0; a < t; a++)
    {
        long long n, sum = 0; 
        scanf("%lld",&n);
        if (n < 2)
            sum = 0;
        else if (n < 8)
            sum = 2;
        else if (n < 34)
            sum = 10;
        else
        {
            long long a = 2, b = 8, c = 8;
            sum = 2;
            
            while (c < n)
            {   
                //printf("%lld %lld %lld\n", a, b, c);
                sum += c;
                c = 4*b + a;
                a = b;
                b = c;
                //printf("%lld %lld %lld\n", a, b, c);
            }
        }
        outputs[a] = sum;
    }
    for(int a = 0; a < t; a++)
        printf("%lld\n", outputs[a]);
    free(outputs);
    return 0;
}
