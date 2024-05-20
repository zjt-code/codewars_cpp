#include<stdio.h>
#include<stdint.h>

bool scramble(const char *str1, const char *str2)
{

  const char * p_str1 = str1;


  while(*str2 != '\0')
  {
    p_str1 = str1;

    while(*p_str1 != '\0')
    {
        if( *str2 == *p_str1)break;
        p_str1++;
    }

    if(*p_str1 == '\0')return false;
    str2++;
  }
  return true;
}


int main()
{

    // if(scramble("katas", "codewars"))
    //     printf(" true\r\n");
    // else
    //     printf(" false\r\n");

    const int i =0;

    int *p =(int *)&i;
    
    *p =1;

    printf("i=%d, *p =%d\r\n",i,*p);

    printf("p=0x%08x,&i =0x%08x\r\n",p,&i);

    float a[10] = {
        10.05,
		7.82,
		10.32,
		9.44,
		9.72,
		10.28,
		9.26,
		10.28,
		9.7,
		9.32
		};

    printf("sizeof(float) = %d\r\n",sizeof(float));

    printf("sizeof( a[10])=%d\r\n", sizeof(a));

    printf("a[%d]= 0x%08x\r\n",1, a[1]);
    printf("a[%d]= 0x%08x\r\n",2, a[2]);
    printf("a[%d]= 0x%08x\r\n",3, a[3]);
    char *p_float =(char *) &a[1];

    printf("0x%02x%02x%02x%02x",(uint8_t)*(p_float +3),(uint8_t)*(p_float +2),(uint8_t)*(p_float +1),(uint8_t)*p_float);
   



    return 0;
}