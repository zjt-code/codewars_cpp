#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<math.h>
#include<time.h>



typedef struct diver
{
    long  value;
    struct diver *p_next;

}t_diver;


/**
 **@return true: can't be
 *         false: can be dived
 * 
*/
// bool compare_list(long input, t_diver *p, long cnt)
// {    
//     // while( p->p_next !=NULL && ((input % p->value) !=0)){ p = p->p_next;};
    
//     while(cnt)
//     {   
//         // printf("p->value =%d\r\n",p->value);
//         if((input % p->value)==0) return false;
//         p= p->p_next;
//         cnt--;
//     }

//     return true;

//     // if((input%p->value)==0)
//     // return true;
//     // else
//     // return false;
// }


long compare_list(long input, t_diver *p, long cnt)
{        
    long res=0,muti_div_sum =0,backcnt = cnt;
    t_diver *header = p;

    long *div_array = (long *)malloc(sizeof(long) * cnt);

    for(long x =0; x<backcnt; x++)
    {
        div_array[x] = p->value;
        p = p->p_next;

        printf("div_array[%d] = %d\r\n",x,div_array[x]);
    }
    p = header;

    // get all diver numbers sum

    while(cnt)
    { 
        res+= (input-1)/p->value;
        p= p->p_next;
        cnt--;
    }
    //  get all min multiplyer sum

    for(long x =0; x<(backcnt-1); x++ )
    {
        for( long y=x+1; y<backcnt; y++)
        {   
            long mul_value  =div_array[x]*div_array[y];

            // for(long z = input; z>( mul_value * mul_step);mul_step++)
            // {
            //     printf("mul_vlue*step=%d\r\n",mul_value * mul_step);
            // } 

            printf("div_array[%ld] = %d, div_array[%d]= %ld, div_v=%ld\r\n",
            
            x,div_array[x],y,div_array[y],(input-1)/mul_value);       

            muti_div_sum+=(input-1)/mul_value;  
            
        }
    }

    printf("mulit_div_sum =%d\r\n",muti_div_sum);


    free(div_array);

    printf(" RES = %ld\r\n", res-muti_div_sum);

    return (res-muti_div_sum);
}

 bool isPrime(long num) {
    if (num <= 3) {
        return num > 1;
    }
    // 不在6的倍数两侧的一定不是质数
    if (num % 6 != 1 && num % 6 != 5) {
        return false;
    }
    long qv = (long)sqrt(num);
    for (long i = 5; i <= qv; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

long properFractions(long n)
{
    long div_cnt =0,half_v=(n+1)/2,result =0;  

    if(n < 3) return (n==1)? 0:1;
   
   //creat signle list
    t_diver *p =(t_diver *)malloc(sizeof(t_diver));
    t_diver *header = p;

    if(isPrime(n) == false)
    for(long x=2; x<half_v; x++)
    {
        if((n%x) == 0)
        {
            if(isPrime(x))
            {
            // ********add signle List*********
                p->value = x;
                p->p_next = (t_diver *)malloc(sizeof(t_diver));
                p=p->p_next;
                //************************
                div_cnt++;  

                printf("x =%d \r\n",x);  
            }        
        }
        
    }   
     printf("div_cnt = %d\r\n",div_cnt);


    if(div_cnt)
    {     
        
        result = n-1- compare_list(n,header,div_cnt)-((div_cnt >2)?(div_cnt-1):0);
    }
    else
    { result= n-1;}  

    return result;
}


// long max_diveder(long m, long n)
// {
//     long temp = n;
//     while( m%n != 0)
//     {   
//         temp = m%n;
//         m = n;
//         n = temp;        
//     }
//     return temp;
// }



// long properFractions(long n)
// {
//     long cnt =0, half_v = (n+1)/2;    



//     if(n < 2) return 0;
//     else
//     {
//         for(long x = 1; x <half_v; x++ )
//         {
//              if(max_diveder(n, x) ==1)cnt++; 
//             //if(n%x ==0){printf("X=%d\r\n",x);}                         
            
//         }
//         return cnt;
//     }    
// }




int main(int arg, char *arv[])
{

    long res;
    //time_t t_start =  time(NULL);
    clock_t t_start = clock();

    //res = properFractions(25);

    printf("len sizeof(long)= %d\r\n",sizeof(long));
    // res = properFractions(1532420);

    // printf("%ld\r\n",0x7fffffff);
    
      for( long x =0; x<100;x++)
      if(isPrime(x)) printf("%ld\r\n",x);

     clock_t t_end = clock();

    // printf("res =%d\r\n",res);

  

    //time_t t_end = time(NULL);

    printf("%.3f\r\n",(float)(t_end-t_start)/CLOCKS_PER_SEC);


    return 0;
}