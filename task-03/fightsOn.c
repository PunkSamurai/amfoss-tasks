#include <stdio.h>
#include <stdlib.h>

#define MAX_TESTS 30

typedef struct _Rope
{
    int bloodStart;
    int bloodEnd;
}
Rope;

int comparator (const void * p1, const void * p2)
{
  return (*(int*)p1 - *(int*)p2);
}

int main(void)
{
    int t = 0;
    int outputs[MAX_TESTS];

    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        int N = 0, M =0, v = 0, k = 0, clean = 0, pos = 0;
        scanf("%d %d %d %d", &N, &M, &v, &k);
        int* initialPositions = (int*) malloc(M*sizeof(int));
        Rope* rope = (Rope*) malloc(M*sizeof(Rope));
        int c = v*k;

        for(int j = 0; j < M; j++)
        {
            scanf("%d", initialPositions[j]);
        }

        qsort(initialPositions, M, sizeof(int), comparator);

        for(int j = 0; j < M; j++)
        {
            pos = initialPositions[j]; 
            rope[j].bloodStart = pos - c; //i am initializing each continuous portion of rope covered in blood at time t
            rope[j].bloodEnd = pos + c;
            //printf("%d %d  %d \n", rope[j].bloodStart, pos, rope[j].bloodEnd);
        }

        if(rope[0].bloodStart > 0)
            clean += rope[0].bloodStart; 

        for(int j = 1; j < M; j++)
        {
            if(rope[j].bloodStart > rope[j - 1].bloodEnd) //checking if there is clean rope between each stained segment
                clean += (rope[j].bloodStart - rope[j - 1].bloodEnd); // adding length of uncontaminated blood to 'clean'
        }

        if(rope[M - 1].bloodEnd < N)
            clean += (N - rope[M - 1].bloodEnd);

        outputs[i] = clean;
        free(rope);
    }
    
    for(int i = 0; i < t; i++)
    {
        printf("%d\n", outputs[i]);
    }
}
