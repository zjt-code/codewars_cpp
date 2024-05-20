#include<stdio.h>
#include<stdint.h>

//algo one timeout
uint64_t countOnes_new ( uint64_t left, uint64_t right )
{
    uint64_t sum=0;
    for(;left<=right;left++)
    {   
       
        uint64_t temp = left;
        while (temp)
        {
            sum+=(temp&0x01)?1:0;
            temp>>=1;
        }
        
    }
	return sum;
}

uint64_t countOnes ( uint64_t left, uint64_t right )
{
    uint64_t bit_big = 0x8000000000000000,bit_bign =~bit_big;

    uint64_t sum1=0,sum2=0;

    left = left > 0 ?left-1:0;

    for(int shift=0; shift<64;shift++)
    {
        if(bit_big&left)
        {
          if(left&bit_bign==0)
            sum1 +=  ((bit_big)*(64-shift) + 1)/2;
          else
            sum1 += left&bit_bign +1 ;

            printf("sum1=%d ,bit_bit= %d, mul = %d\r\n",sum1,(bit_big)/2,(64-shift-1));
        }

        bit_big>>=1;
        bit_bign>>=1;
    }

    bit_big = 0x8000000000000000,bit_bign =~bit_big;


     for(int shift=0; shift<64;shift++)
    {
        if(bit_big&right)
        {
          if(bit_bign&right ==0)
          sum2 +=  ((bit_big)*(64-shift) + 1)/2;
          else
          sum2+= bit_bign&right + 1;

          printf("sum2=%d ,bit_bit= %d, mul = %d\r\n",sum2,(bit_big)/2,(64-shift-1));
        }

        bit_big>>=1;
        bit_bign>>=1;
    }




	return sum2-sum1;
}


int main()
{

    printf("ones count = %ld\r\n",countOnes(4,7));
    printf("ones count newo = %ld\r\n",countOnes_new(4,7));
    return 0;
}