#include <stdio.h>
#include <stdlib.h>

long long int findSum(long long int a, int b);

int main(void)
{
    int t = 0;
    long long int sum = 0;
    scanf("%d", &t);
    long long int* outputs = (long long int*) malloc(t*sizeof(long long int));
    for (int i = 0; i < t; i++)
    {
        long long int n = 0;
        scanf("%lld", &n);
        n--;
        sum = 3*findSum(n, 3) + 5*findSum(n, 5) - 15*findSum(n, 15);
        outputs[i] = sum;
        sum = 0;
    }
    for (int i = 0; i < t; i++)
        printf("%lld\n", outputs[i]);
    free(outputs);
    return 0;
}

long long int findSum(long long int a, int b)
{
    a = a/b;
    long long int sum = (1 + a)*(a/2);
    if(a%2 != 0)
        sum += ((a/2) +1);
    //printf("%d %d %d\n", a, a/2, sum);
    return sum;
}
