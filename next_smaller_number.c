#define _GNU_SOURCE

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int cmp_char(const void* elem1, const void* elem2)
{
	return *(char*)elem2-*(char*)elem1 ;
}



long long next_smaller_number(unsigned long long n){
    //insert code here
    char *n_buff =NULL,*p_end =NULL,*p_move = NULL;
    char temp;
    unsigned long long res =0;

    asprintf(&n_buff,"%llu",n);

    int zeor_cnt_seq = 0,zero_max =0;
    char * zero_max_char_addr =NULL;

    p_move = n_buff +  strlen( n_buff) -1;  
    p_end = p_move;


    for( int x =0; n_buff + x< n_buff + strlen(n_buff); x++ )
    { 
      if( *(n_buff+x) == '0')
        zeor_cnt_seq++;
    else
        zeor_cnt_seq=0;

        if( zeor_cnt_seq > zero_max)
        {
            zero_max = zeor_cnt_seq;
            zero_max_char_addr = n_buff+x;
        }
    }

    printf("zero_max = %d\r\n, addr = %d\r\n", zero_max, zero_max_char_addr);


    if( strlen(n_buff)>4 && zero_max > 1)
    {
        
        printf("qsort\r\n");

        qsort(zero_max_char_addr-zero_max+2, p_move-zero_max_char_addr+1,1,cmp_char);

    }
    else
    {
        
            printf("input n = %s\r\n", n_buff);
            while ( p_move -1 >= n_buff)
            {
                    // if(( *p_end < *(p_end-1))&&((*p_end != '0')&&(p_end-1)!=n_buff))
                    if(( *p_move < *(p_move-1)))
                    {
                        if((*p_move == '0') && (p_move-1)==n_buff && p_move < p_end)
                        {
                            printf("change 3 value\r\n");
                            if( *(p_move-1) > *(p_move+1) && *(p_move+1) !='0')
                            {
                                temp = *(p_move+1);
                                *(p_move+1) = *(p_move);                          
                                *(p_move) = *(p_move-1);
                                *(p_move-1) = temp;
                                break;
                            }
                            else
                            {

                            }
                        
                        }
                        else
                        {
                            printf("move none zero\r\n");
                            temp = *p_move;  
                            *p_move =*(p_move-1);
                            *(p_move-1) = temp; 
                            break;
                        }
                    }
                    p_move--;
                    }
    }
    
    printf("rest n = %s\r\n", n_buff);
    
    for(res =0;*n_buff != '\0';n_buff++){     
      
        res = res*10 + *n_buff - '0';

        printf("*n_buff = %c, res = %llu\r\n", *n_buff, res);
        };

    printf("fun res = %llu\r\n",res);

    //free(n_buff);
    // return res;

    return res == n  || *n_buff == '0'? -1 : res;
}


int main()
{

    printf("res=%llu\r\n", next_smaller_number(29006789));

    //  printf("res=%llu\r\n", next_smaller_number(907));
    // printf("hello world\r\n");

    return 0;
}