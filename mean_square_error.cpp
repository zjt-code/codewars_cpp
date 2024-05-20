#include<stdio.h>
#include<math.h>

double mean_square_error(size_t n, const int *a,const int *b) {

    //  <----  hajime!
    double sum =0;

    for(size_t x =0; x< n; x++)
    {
         sum += pow((double)abs(a[x]-b[x]),2.0f);
   
    }

    return(sum/n);
}

int main()
{
  const int a[3]={1,2,3,};
  const int b[3]={4,5,6};

  printf("%f,\r\n",mean_square_error(3,a,b));   

return 0;
}