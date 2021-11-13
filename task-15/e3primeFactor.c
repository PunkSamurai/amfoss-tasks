#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    long long* outputs = (long long*) malloc(t* sizeof(long long));
    for(int a = 0; a < t; a++)
    {
        long long n, greatest = 1; 
        scanf("%lld",&n);
        
        if (n > 1)
        {
            while (n%2 == 0)
                n = n/2;
            
            if (n == 1)
                greatest = 2;
            
            else
            {    
                for(int i = 3; i <= sqrt(n); i += 2)
                {
                    if (n%i == 0)
                    {
                        greatest = i;
                        while (n%i == 0)
                            n = n/i;
                    }
                    if (n==1)
                        break;
                }
                if (n != 1)
                    greatest = n;   
            }                
        }
        outputs[a] = greatest;
    }
    for(int a = 0; a < t; a++)
        printf("%lld\n", outputs[a]);
    free(outputs);
    return 0;
}