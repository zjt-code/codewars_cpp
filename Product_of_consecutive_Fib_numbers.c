#include<stdio.h>
#include<math.h>
#include<stdlib.h>


// The Fibonacci numbers are the numbers in the following integer sequence (Fn):

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...

// such as

// F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.

// Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying

// F(n) * F(n+1) = prod.

// Your function productFib takes an integer (prod) and returns an array:

// [F(n), F(n+1), true] or {F(n), F(n+1), 1} or (F(n), F(n+1), True)
// depending on the language if F(n) * F(n+1) = prod.

// If you don't find two consecutive F(n) verifying F(n) * F(n+1) = prodyou will return

// [F(n), F(n+1), false] or {F(n), F(n+1), 0} or (F(n), F(n+1), False)
// F(n) being the smallest one such as F(n) * F(n+1) > prod.

// Some Examples of Return:
// (depend on the language)

// productFib(714) # should return (21, 34, true), 
//                 # since F(8) = 21, F(9) = 34 and 714 = 21 * 34

// productFib(800) # should return (34, 55, false), 
//                 # since F(8) = 21, F(9) = 34, F(10) = 55 and 21 * 34 < 800 < 34 * 55
// -----
// productFib(714) # should return [21, 34, true], 
// productFib(800) # should return [34, 55, false], 
// -----
// productFib(714) # should return {21, 34, 1}, 
// productFib(800) # should return {34, 55, 0},        
// -----
// productFib(714) # should return {21, 34, true}, 
// productFib(800) # should return {34, 55, false},

typedef unsigned long long ull;


// uul my_sqrt()



ull fib(ull n)
{
   
    return (powl((0.5+sqrt(5)/2),n) - powl((0.5-sqrt(5)/2),n))/sqrt(5);

}

ull * productFib(ull prod)
{                     
    ull * result = calloc(3,sizeof(ull));
    ull  squre_v = sqrtl(prod);   
    ull n =0;

    while((result[1] = fib(n)) < squre_v){
        result[0] = result[1],n++;
        }

    if(result[1] * result[0] == prod)
    {        
        result[2] = 1;
        return result;        
    }
    else if( result[1] * result[0] > prod)
    {     
        result[2] = 0;
        return result;
        

    }else{
            result[0] = result[1];
            result[1] = fib(n+1);            
            result[2] = (result[0]*result[1]==prod)?1:0;     
            return result;

    }
}


int main(int avgn, char **arg)
{
    for(int x =0; x < avgn; x++)
    printf("%s\r\n",arg[x]);

    // for(ull x=0; x < 10; x++)
    // {
    //      printf("x=%u, fib = %u\r\n", x, fib(x));
    // }
   
   ull *result =  productFib(74049690);

    for(int x =0; x<3; x++)
    printf("%llu ", result[x]);

    printf("\r\n");

    return 0;
}