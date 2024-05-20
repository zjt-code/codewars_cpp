#include<stdio.h>
#include<math.h>

unsigned long long power_sum_dig_term(unsigned n) {

  //  <----  hajime!
        unsigned long long rest =2,sum=0;

        while (1)
        {
            for(unsigned long long x = rest; x >0; sum+=x%10,x /=10);
            /* code */

            if( rest == pow(sum,n+1))break;


            rest++;

            printf("%lu\r\n",rest);
        }
        
        return rest;
}


int main()
{


    printf("%lu\r\n",power_sum_dig_term(1));
    return 0;
}