#include <stdio.h>
#include <cs50.h>

int main()
{
    //Accept number from 1 to 8
    int n;
    do
    {
        n = get_int("Enter number between (or including) 1 and 8: ");
    }
    while (n < 1 || n > 8);
    n++;


    //Draw pyramid
    int i = n - 1;
    while (i > 0)
    {
        int j;
        for (j = 1; j < i; j ++)
        {
            printf(" ");
        }

        for (j = 1; j <= (n - i); j++)
        {
            printf("#");
        }

        printf("  ");

        for (j = 1; j <= (n - i); j++)
        {
            printf("#");
        }

        printf("\n");

        i --;
    }

    return 0;
}