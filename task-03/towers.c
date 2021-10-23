#include <stdio.h>
#include <stdlib.h>

int comparator (const void * p1, const void * p2)
{
  return (*(int*)p1 - *(int*)p2);
}
 int main(void)
 {
    int n = 0, weight = -1, height = 0, number = 0, maxheight = 0;
    scanf("%d", &n);
    int* blocks = (int*) malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &blocks[i]);
    }

    qsort(blocks, n, sizeof(int), comparator);

    for(int i = 0; i < n; i++)
    {
        if(blocks[i] == weight)
        {
            height++;
            if(height > maxheight)
                maxheight = height;
        }
        else
        {
            number++;
            weight = blocks[i];
            height = 1;
            if(height > maxheight)
                maxheight = height;
        }
    }
    printf("%d %d", maxheight, number);
    free(blocks);
    return 0;
}