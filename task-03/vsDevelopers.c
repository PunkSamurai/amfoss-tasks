#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 101

typedef struct _ProbSolver
{
    int power;
    int hasKilled;
}ProbSolver;

int main(void)
{
    int n = 0, m = 0, sum = 0;   
    ProbSolver pSolvers[MAXNUM];
    int developers[MAXNUM];

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &developers[i]);
    }

    for(int i = 0; i < m; i++)
    {
        scanf("%d", &pSolvers[i].power);
        pSolvers[i].hasKilled = 0;
    }

    if(m > n)
    {
        for(int i = 0; i < n; i++)
        {               
            int difference = 0, minDifference = 2147483647, index = -1;
            for (int j = 0; j < m; j++)
            {
                if(pSolvers[j].hasKilled == 0)
                {
                    if(pSolvers[j].power > developers[i])
                    {
                        difference = pSolvers[j].power - developers[i];
                        if(difference < minDifference)
                        {
                            minDifference = difference;
                            index = j;
                        }
                    }       
                }
            }
            if(index == -1)
            {
                printf("NO\n");
                return 0;
            }
            else
            {
                pSolvers[index].hasKilled = 1;
                sum += pSolvers[index].power;                
            }
        }
    }
    else
    {
        printf("NO\n");
        return 0;
    }
    
    printf("YES\n%d\n", sum);
    return 0;
}