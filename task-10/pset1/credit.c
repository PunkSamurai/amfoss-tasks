#include <cs50.h>
#include <stdio.h>

int main()
{
    //Accept input:
    long number = get_long("Enter credit card number: ");



    //Checksum, and find length
    int digit;
    long num1 = number;
    int checksum;
    int length = 0;
    int sum1 = 0;
    int sum2 = 0;
    int x;
    int y;
    int z;

    while (number > 0)
    {
        digit  = number % 10;
        number = number / 10;
        length ++;

        if (length % 2 == 1)
        {
            sum1 += digit;
        }
        else
        {
            x = (2 * digit);
            y = x % 10;
            z = x / 10;

            sum2 += (y + z);
        }

    }

    checksum = sum1 + sum2;


    //Validate and determine card
    if (checksum % 10 == 0)
    {
        if (length == 13)
        {
            (num1 / 1000000000000) == 4 ? printf("VISA\n") : printf("INVALID\n");

        }
        else if (length == 15)
        {
            num1 = (num1 / 10000000000000);
            if (num1 == 34 || num1 == 37)
            {
                printf("AMEX\n");
            }

            else
            {
                printf("INVALID\n");
            }
        }
        else if (length == 16)
        {
            num1 = (num1 / 100000000000000);
            if (num1 == 51 || num1 == 52 || num1 == 53 || num1 == 54 || num1 == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (num1 / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }


    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}