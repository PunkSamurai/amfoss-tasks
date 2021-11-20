````````````````````#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct _Car
{
    float position;
    int direction;
    int crashedWith; 
}
Car;

void move(void);
void bump(void);
void visualize(void); //for debugging

Car* cars;
int x = 0, n = 0, count = 0;


int main(void) 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i = 0, time = 0;
    scanf("%d %d", &x, &n);
    cars = (Car*) malloc(x * sizeof(Car));
    count = x;
    
    for (i = 0; i < x; i++)
    {
        scanf("%f", &cars[i].position);
    }
    
    for (i = 0; i < x; i++)
    {
        scanf("%d", &cars[i].direction);
        cars[i].crashedWith = -1;
    }

    visualize();
    while(count > 0)
    {
        printf("%d\n", time);
        move();
        bump();
        //visualize();
        move();
        bump();
        visualize();

        time++;
        
    }
    printf("%d", time);
}

void move(void)
{
    for( int i = 0; i < x; i++)
    {
        if(cars[i].position >= 0.0 && cars[i].position <= (float) n)
        {
            if(cars[i].position == 0.0 && cars[i].direction == -1)
            {
                cars[i].position = -2.0;
                count --;
            }

            else if(cars[i].position == (float) n && cars[i].direction == 1)
            {
                cars[i].position = (float) (n + 2);
                count --;
            }

            else
            {
                cars[i].position += (0.5)*((float) cars[i].direction);
                for( int j = 0; j < x; j++)
                {
                    if(j != i)
                    {
                        if(cars[j].position == cars[i].position)
                        {
                            cars[i].crashedWith = j;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void bump(void)
{
    for( int i = 0; i < x; i++)
    {
        if(cars[i].crashedWith != -1)
        {
            cars[i].direction = -cars[i].direction;
            int i2 = cars[i].crashedWith = -1;
            cars[i].crashedWith = -1;

            cars[i2].direction = -cars[i2].direction;
            cars[i2].crashedWith = -1;
            printf("%d and %d crashed\n", i,i2);
        }
    }
}

void visualize(void)
{
    for(int i = 0; i < n; i++)
    {
        int c = 0;
        for(int j = 0; j < x; j++)
        {
            if(cars[j].position == i)
            {
                printf("(%d %d %d)", j,(int) cars[j].position, cars[j].direction);
                c = 1;
            }
        }
        if(c == 0)
            printf("==|%d|==",i);
    }
    printf("\n");
}

