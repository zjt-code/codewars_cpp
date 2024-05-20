
#include<stdio.h>
#include<math.h>

unsigned long long int find_reverse_number(unsigned long long int n) {

    //  <----  hajime!

    unsigned long long int x =0;

    x = pow(10,(n-1)/10)-1; 


    return x;
}


int main()
{
    printf(" %ld",find_reverse_number(10));
    
    return 0;
}