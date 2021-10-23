#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0, q = 0;
    scanf("%d", &n);
    int* cities = (int*) malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &cities[i]);
    }

    scanf("%d", &q);
    int start = 0, end = 0;

    for(int i = 0; i < q; i++)
    {
        int sum = 0;
        scanf("%d %d", &start, &end);
        for(int j = (start-1); j < end; j ++)
            sum += cities[j];
        printf("%d\n", sum);
    }
    return 0;
}