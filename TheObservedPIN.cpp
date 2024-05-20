#include<stdio.h>
#include<stdlib.h>
#include<string.h>


const char** get_pins(const char* observed, size_t* count) {
    
    const char Zero_N[] =   "08";
    const char One_N[] =    "124";
    const char Two_N[] =    "1235";
    const char Three_N[] =  "236";
    const char Four_N[] =   "1457";
    const char Five_N[] =   "24568";
    const char Six_N[] =    "3569";
    const char Sev_N[] =    "478";
    const char Eight_N[] =  "05789";
    const char Nine_N[] =   "689";
    const char *num_neiber[10]={
        Zero_N,One_N,Two_N,Three_N,Four_N,
        Five_N,Six_N,Sev_N,Eight_N,Nine_N
      };
  
    size_t pin_lens=0;
    const char * p_ob = observed;
    *count =1;

    for(pin_lens =0; *observed !='\0'; observed++,pin_lens++)
        *count *=   strlen(num_neiber[*observed-'0']);
    
    char **p = (char **)malloc(*count * sizeof(char *));

     for( size_t x = 0; x< *count; x++) {
        p[x] = (char *)malloc(pin_lens+1);     
     } 
    switch (pin_lens)
    {
    case 1:
        for(size_t x =0;  x < *count; x++)
        {    
        sprintf(( char *)p[x],"%c%c",num_neiber[*p_ob-'0'][x],'\0');           
        }            
        break;
    case 2:    
         //for(int a =0;  a < *count; a++)
         { 
            int a =0;          
            for(size_t x =0; x< strlen(num_neiber[*p_ob-'0']); x++)
            {
                for(size_t y =0; y< strlen(num_neiber[*(p_ob+1)-'0']);y++,a++)
                {               
                    p[a][0] = (char )num_neiber[*p_ob-'0'][x];                   
                    p[a][1] = (char )num_neiber[*(p_ob+1)-'0'][y];                    
                    p[a][2] = (char )'\0';    
                  
                }
            }
         }        
        break;
    case 3:
        {
            size_t a =0;          
            for(size_t x =0; x< strlen(num_neiber[*p_ob-'0']); x++)
            {
                for(size_t y =0; y< strlen(num_neiber[*(p_ob+1)-'0']);y++)
                {   
                for(size_t z =0; z< strlen(num_neiber[*(p_ob+2)-'0']);z++,a++) 
                {            
                    p[a][0] = (char )num_neiber[*p_ob-'0'][x];                   
                    p[a][1] = (char )num_neiber[*(p_ob+1)-'0'][y];
                    p[a][2] = (char )num_neiber[*(p_ob+2)-'0'][z];                      
                    p[a][3] = (char )'\0';   
                } 
                  
                }
            }
        }
        break;
    
    default:
        p=NULL;
        break;
    }

    return (const char **)p;
}



int main()
{
        printf("Hello world \r\n");

        size_t count;

        const char **p;    

        p = get_pins("123", &count);

        for(int x =0; x< count; x++)
        {
            // printf("p[%d] = 0x%08x\r\n",x,p[x]);
            printf("p[%d] = %s\r\n",x,p[x]);
            free((void *)p[x]);
        }
        free(p);
  


return 0;
}