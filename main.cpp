
#include<stdio.h>
#include<stdint.h>
#include"aes.h"
#include"cgms_crc.h"
#include<iostream>
#include<float.h>
#include"codwars_lv5.h"
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


//static uint8_t aes_ecb_128_key[16]={0x2B,0x7E,0x15,0x16,0x28,0xAE,0xD2,0xA6,0xAB,0xF7,0x15,0x88,0x09,0xCF,0xAC,0xEF};

static uint8_t plain_set_psw[16]={0X12,0X34,'A','B','C',0XD2,0X04,0X09,0X09,0X09,0X09,0X09,0X09,0X09,0X09,0X09};

static uint8_t aes_ecb_128_key[16]={0x2B,0x7E,0x15,0x16,0x28,0xAE,0xD2,0xA6,0xAB,0xF7,0x15,0x88,0x09,0xCF,0x56,0x78};
uint8_t cipher[16] = {0x92,0xb9,0x03,0xf3,0x59,0xc4,0x9d,0x01,0x6b,0xba,0x34,0xc4,0x48,0x70,0xcd,0x3a};

uint8_t cipher_2[16]={0X23,0X3e ,0X72 ,0X2f ,0X52 ,0X5e ,0X86 ,0X49 ,0Xe2 ,0X0c ,0X4b ,0X96 ,0X2d ,0Xc7 ,0Xa1 ,0X24};


uint8_t cipher3[16]={0X3a,0X0f,0X17,0X04,0Xbb,0X1c,0Xb4,0Xe5,0Xe7,0X79,0X08,0Xfe,0X1b,0Xe8,0X5d,0x55};

//uint8_t cipher_2[16]={0x7c,0x84 ,0x44 ,0xde ,0x22 ,0x62 ,0x60 ,0xf8 ,0x49 ,0x67 ,0xb9 ,0x61 ,0x02 ,0xef ,0xf7 ,0x4e};
uint8_t text_plain[16];

uint8_t test_array[6]={0,2,2,4,5};

//uint8_t test_crc[4] ={0x1C04044138};
uint8_t test_crc[7] ={0x04,0x86,0x00,0x2F,0x00,0x97,0xDB};
uint8_t test_crc2[] = {0x0d,0x43,0x09,0x02,0x00,0x0f,0x80,0xe5,0x04,0x8f,0x02,0x00,0x00,0x00,0x1a,0x3b};

char *incrementString(const char *str);
char *camel_case(const char *s);

static const float current_value[]=
{       655.36,
		15.01,	
		8.86,
		8.73,
		9.19,
};


uint16_t ftoint16_t( float value)
{
    uint32_t to_int32 =(uint32_t)(value*10.0f);
    // uint16_t to_int16_t =0;
   // printf("to_int32=%d\r\n ", to_int32);
    if( to_int32%10 >=5)
    {
        to_int32+=10;
    }

    if((to_int32/10) >65535)to_int32=512000;
   // printf("to_int32=%d\r\n ", (uint16_t)(to_int32/10));

    return (uint16_t)(to_int32/10);
}


int nbYear(int p0, double percent, int aug, int p) {
  
  int new_p=p0,year=0;
  
    while( new_p < p)
    {
      
      new_p = new_p*(1 + percent/100.0f)+ aug;
      
      year++;
      
    }
      
      
    return year;
}

int digit_root( int n)
{
    int sum =0;
    if ( n <10) return n;
    else 
    while(n > 0)
    {
        sum+= n%10;
        n /=10;
       
    }
 
    return digit_root(sum);
}

int countDigitOne(int n) {
    
     int cnt =0;

    // while (n)
    // {
    //     /* code */
    //     int m = n;
    //     while (m)
    //     {
    //         if(m%10 == 1)cnt++;
    //         m/=10;
    //     }
    //     n--;        
    // }
    
    char  p[12],loop=0;

    while (n)
    {
     /* code */

        sprintf(p,"%d",n);
   

        while (p[loop] !='\0')
        {
            /* code */
            if(p[loop++]=='1')cnt++;
        }
        n--;
        loop=0;
        
    }
    

    return cnt;
}

bool slibing_window( char *start, char * end , int offset, int *same_pos)
{

    int x =0;

    while (x< offset)
    {
        /* code */
        if(*(start+x) == *end){ *same_pos= x; return  true;}
        x++;
    }

    return false;
}


int lengthOfLongestSubstring(char* s) {
    
    int start_cnt =0, end_cnt =1,same_pos =0;

    char * p_start = s;
    char * p_end = s+end_cnt;
    int total_len = strlen(s),max_len=0;

    for(; end_cnt < total_len; end_cnt++)
    {

        int loop=0;

         p_end=s+end_cnt;

         if(slibing_window(p_start,p_end,end_cnt-start_cnt,&same_pos))
         {
            printf("find same;start_cnt=%d, same_pos=%d,end_cnt=%d\r\n",start_cnt,same_pos,end_cnt);
            start_cnt += same_pos + 1;
            p_start = start_cnt+s;
            
         }
         else
         {
             if(max_len < (end_cnt-start_cnt)) max_len=end_cnt-start_cnt +1;
         }

        
        printf("start_cnt=%d, max_len=%d\r\n",start_cnt,max_len);
    }

    return max_len;
}


uint8_t cipher4[16]={0X3a,0X0f,0X17,0X04,0Xbb,0X1c,0Xb4,0Xe5,0Xe7,0X79,0X08,0Xfe,0X1b,0Xe8,0X5d,0x55};


int main(void)
{
   // uint8_t psw_ciper[16];

    // AES128_ECB_encrypt(plain_set_psw,aes_ecb_128_key,psw_ciper);

    //  for(uint8_t i=0; i<16;i++)printf("%02x ",psw_ciper[i]);

    // printf("__________________________\r\n");



    AES128_ECB_decrypt(cipher3,aes_ecb_128_key,text_plain);

    for(uint8_t i=0; i<16;i++)printf("%02x ",text_plain[i]);

    printf("\r\n__________________________\r\n");
 
}




char *camel_case(const char *s)
{
char * p = (char *) malloc( strlen(s));
int  loop =0;
  
while (*s == ' ')s++;

if( strlen(s))
 {
    p[loop++] = toupper(*s);
  
     while(*s++ !='\0')
     {
         printf("%c\r\n", *s); 

         if(isalpha(*s))
         {
            // printf("p = %c \r\n", p[loop]);
            if(*(s-1) == ' ')
             p[loop++]= toupper(*s);
             else
             p[loop++]= *s;            
         }      
     }
     p[loop] = '\0';     
 }
else     
    return NULL;
    
  printf("ps =%s\r\n",p);

  return p;
}



char *incrementString(const char *str)
{
    int len =strlen(str);
    int num_len =0,c_len=0;
    int num =0;
    char format_str[12];

    while (len)
    {        /* code */
        if(str[len-1]>='0' && str[len-1]<= '9')
        {
           
            num+= pow(10,num_len)*(str[len-1]-'0');
            num_len++;
        }
        else break;
        len--;
    };
    char *p ;
    len = strlen(str);
    c_len = len-num_len;

    if(num_len)
    {
        if( num >= (pow(10,num_len)-1))
        {          
            num_len++;
            len++;           
        }
        num++;
        
        sprintf(format_str,"%%0%dd",num_len);
        p = (char *) malloc(len + 1);
        memcpy(p,str,c_len);
        sprintf(p + c_len,format_str,num);
        // printf("c_len=%d\r\n",c_len);
        // printf("format_str=%s\r\n",format_str);
        // printf("num=%d\r\n",num);
    }
    else
    {
        p = (char *) malloc(len + 2);
        sprintf(p,"%s1",str);

    }

    return p;
}