#include<stdio.h>
#include<math.h>


int beeramid(double bounus, double price)
{
    double sum =0;
    int level =0;
    if(bounus < price) return 0;

    while( sum <=bounus/price)
    {

        sum += pow(++level ,2);

    }

    return (level-1);
}
int main()
{

    printf("%lu\r\n", beeramid(10.00,2.00));
    return 0;
}