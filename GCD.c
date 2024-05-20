#include<stdio.h>
#include<time.h>

#define MAX(a, b)  ((a>b)?a:b)
#define MIN(a, b)  ((a<b)?a:b)

unsigned gcd(unsigned a, unsigned b)
{
    unsigned max,min,diff;
    // while(a%2 ==0)
    // a = (a%2==0)? (a/2):a;

    // while(b%2 ==0)
    // b = (b%2==0)? (b/2):b;

    
    printf("a = %d, b=%d \r\n", a, b);

    max = (a>b)?a:b;
    min = (a<b)?a:b;
    while(max != min)
    {
        diff = max - min;

        max = MAX(diff,min);
        min = MIN(diff,min);
    }

    printf("max = %d\r\n",max);
    return max;

}



int main()
{
    clock_t t_start,t_end;
    double total;

    t_start = clock();

    // for(int i=0; i< 1000000000; i++)
    // {
    // }

    int a = gcd(6,8);

    int b = gcd(7,8);
    
    int lcm_a = 6*8/a;
    int lcm_b = 7*8/b;

    printf("lcm_a =%d, lcm_b = %d\r\n",lcm_a,lcm_b);

    int ab = gcd(lcm_a,lcm_b);
    

    printf(" ab = %d\r\n", ab);
    printf("lcm-ab=%d\r\n", lcm_a*lcm_b/ab);
    


    t_end = clock();

    printf("%ld\r\n",t_start);
    printf("%ld\r\n",t_end);

    total = (double)(t_end - t_start)/CLOCKS_PER_SEC;

    printf("total = %lf \r\n", total);
    



    return 0;

}