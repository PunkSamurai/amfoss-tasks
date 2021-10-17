#include <stdio.h>

int iterateThroughM(int m, int nCount, int b);

int main(void)
{
    int m = 0, n = 0 ,nCount = 0, count = 0;

    scanf("%d %d", &n, &m);

    while((n%2) == 0)
    {
        nCount++;
        n = n/2;
    }
    
    count = iterateThroughM(m,nCount,0);
    printf("%d\n" ,count);
    iterateThroughM(m, nCount, 1);

    return 0;
}

int iterateThroughM(int m, int nCount, int b)
{   
    int count = 0;
    for(int i = 1; i <= m; i++)
    {    
        int j = i;
        int jCount = 0;
        while(j%2 == 0)
        {
            jCount++;
            j = j/2;
        }
        if(jCount < nCount)
        {
            count++;
            if(b == 1)
                printf("%d ", i);
        }
    }
    return count;
}