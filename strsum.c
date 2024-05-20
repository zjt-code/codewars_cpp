#define _GNU_SOURCE

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdint.h>
#include<time.h>
#include<math.h>

char *strsum(const char *a, const char *b) {

    //  <----  hajime!
    int a_len = strlen(a),b_len = strlen(b),count=0;
    int len= ( strlen(a) > strlen(b))?(strlen(a)+1):(strlen(b)+1);
    char *p = calloc(len+1,sizeof(char));
    uint8_t sum =0;

    p[len] = '\0';
    

    printf("len =%d\r\n",len);

    while(a_len >0 || b_len >0 )
    {
        /* code */ 
        if( a_len >0 && b_len >0)       
            sum = a[a_len-1]-'0' + b[b_len-1]-'0' + sum/10; 
        else
        if(a_len>0)
            sum = a[a_len-1]-'0'  + sum/10;
        else
            if(b_len>0)
                sum =  b[b_len-1]-'0'   + sum/10; 

        p[len-1] = sum%10+'0';

       // printf("len=%d, %c\r\n", len-1,p[len-1]);
        len--;
        count++;

        a_len--;
        b_len--;
    }
    
    if(sum > 9){p[len-1] = sum/10 + '0';len--,count++;}

    // printf("sum = %d,count = %d,len = %d\r\n", sum, count, len);

    // printf("p=%s\r\n",p);

    char * new_p = calloc(count+1,sizeof(char));
    memcpy(new_p,&p[len],count+1);
    //  char *new_p;
    //  asprintf(&new_p,"%s",&p[len]);
    long long int re_value =0,new_len = strlen(new_p);


    for(int x =strlen(new_p)-1; x >0; x--)
    {
        re_value += (new_p[x]-'0') * pow(10,new_len-x-1);
    }

    printf("%llu\r\n",re_value);

    char *rest_str;

    asprintf( &rest_str,"%llu", re_value);

     free(p);
     return rest_str;
}

int main()
{

//     clock_t t_start,t_end;
//     t_start = clock();

   printf("%s\r\n",strsum("0009","0001"));

//     float *p_float =NULL;

//     for( int x=0; x <4000000;x++)
//     {
//         //  p_float = (float *)malloc( sizeof(float)*200000);

//         //  if(p_float == NULL)printf(" Fail\r\n");
//         //  else
//         //  memset((char *)p_float,0, sizeof(float)*200000);

//         p_float = calloc(200000,sizeof(float));
        
//         free(p_float);

//     }
//     t_end = clock();

//     printf(" time = %f\r\n",(float)(t_end-t_start)/CLOCKS_PER_SEC);

    // int t_array[]={1,3,4};
    // for(int x =0; x < 5; x++)
    //     printf("p[%d] = %d\r\n",x, t_array[x]);


    


  return 0;
}