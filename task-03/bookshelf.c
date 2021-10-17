#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long n = 0;
    int count = 1;
    scanf("%lld", &n);
    if(n>=1 && n<=1e12)
    {
        long long i = n/2;
        while (i > 0)
        {
            if(n%i==0)
                count++;
            i--;
        }
        printf("%d", count);
    }
    return 0;
}