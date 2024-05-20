#include<stdio.h>
#include<stdlib.h>


//  assign divisors to array[]
//  set *length to the number of divisors

void divisors(unsigned n, size_t *length, unsigned array[]) {

    //  <----  hajime!

  size_t y =0;

  *length =0;

  // array = (unsigned *)( malloc(sizeof(unsigned) * n));
  
  for( unsigned x =2; x< n; x++)
  {
      if( n%x == 0 )
      {
        printf("x = %d", x);
        (*length )++ ;       
        array[y++]= x;
      }

  }

}


int main()
{

    size_t length =0;
    unsigned array[50];

    divisors(15,&length,array);

    printf("length =%d\r\n",length);

   for(size_t x =0; x <length; x++)
    {
        printf("array[%d] = %d\r\n", x,array[x]);
    }

    return 0;
}