#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<time.h>

typedef unsigned long long ull;


#define MAX(a, b)  ((a>b)?a:b)
#define MIN(a, b)  ((a<b)?a:b)

ull gcd(ull a, ull b)
{
    // unsigned max,min,diff;
    // max = (a>b)?a:b;
    // min = (a<b)?a:b;
    // while(max != min)
    // {
    //     diff = max - min;

    //     max = MAX(diff,min);
    //     min = MIN(diff,min);
    // }
  
    // return max;

      
    ull t = 1;
	while (t)
	{
		t = a % b;
		a = b;
		b = t;
	}

    return a;
}

ull args_LCM (unsigned n, ...)
{
// all arguments have type unsigned

   
    unsigned *p = (unsigned * )calloc(n,sizeof(unsigned)),uni_val_num =0;
    ull max =1;

    va_list args;
    va_start(args,n);

    if(n==1)
    {   
         max = va_arg(args,unsigned);
      
    } else
    if(n==0)
    { 
         max = 1;
        
    }else
    {
            for(unsigned x = 0; x< n; x++)
            {
                unsigned temp =0;
                unsigned y = 0;    
            
                p[x] = va_arg(args,unsigned);
                uni_val_num++;                      
               
                if(p[x]==0){max=0; break;}   
            }

            for(unsigned x = 0; x<uni_val_num;x++)
            printf("p[%d]= %u\r\n",x,p[x]);

            if( max !=0)
            {
            
                max =(p[0]*p[1])/ gcd(p[0],p[1]);

                for(unsigned x=2; x<uni_val_num; x++)
                {
                max = max * p[x] /gcd(max,p[x]);

                }
            }
    }
    va_end(args);
    free(p);
    return max;
}


int main()
{
    clock_t t_start, t_end;
    float total =0;

    ull lcm =0;
    t_start = clock();

    lcm = args_LCM(5, /* args */ 559, 844, 869, 506, 105);

    printf("lcm = %lu\r\n",lcm);
    t_end = clock();

    total = (float)(t_end-t_start)/CLOCKS_PER_SEC;
    printf("total = %f\r\n",total);


    return 0;
}