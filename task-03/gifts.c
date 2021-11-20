#include <stdio.h>
#include <stdlib.h>

#define M 1000000007

int main(void)
{
    long t = 0, a = 0, b = 0, c = 0, d = 0, n = 0, final = 0;
    scanf("%ld", &t);
    long* outputs = (long*) malloc(t*sizeof(long));
    {
        for(long i = 0; i < t; i++)
        {
            scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &n);

            if(n == 1)
                outputs[i] = a;
            else if(n == 2)
                outputs[i] = b;
            else
            {
                for(long j = 0; j < n; j++)
                {
                    final = (c*a) + (d*b);
                    a = b;
                    b = final;
                }
                outputs[i] = final%M;
            }
        }        
    }
    for(long i = 0; i < t; i++)
        printf("%ld\n", outputs[i]);
    return 0;
}