// #define _GNU_SOURCE

#include<stdint.h>
#include<stdio.h>
#include<string.h>


uint64_t pow_uint64(int cnt)
{
  int64_t mul =1;

  while (cnt)
  {   /* code */
    mul*=64;
    cnt--;
  }
  return mul;
}

// uint64_t base64_to_base10 (const char *base64) {

//   char bas64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
//   const char *p_end = base64 + strlen(base64) -1;
//   uint64_t res =0;
//   int cnt =0;
//   while (p_end >= base64)
//   {
//     res +=(strchr(bas64_table,*p_end--) - bas64_table)* pow_uint64(cnt++);      
//   }
//   return res;
// }


 uint64_t base64_to_base10 (const char *base64) {

  char bas64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  uint64_t res=0;
  int len =strlen(base64);
  
  while (*base64)
  {
    /* code */
  res+= (strchr(bas64_table,*base64++)-bas64_table)*pow_uint64(--len);
   
  }
  return res;
 }

int main()
{


    printf("%llu\r\n", base64_to_base10("HelloWorld"));

    //1 用unsigned long表示64位
uint64_t num = 4503599627370495;//0xfffffffffffff
printf("%llu\n", num); //十进制输出
// printf(“%#lx\n”, num); //十六进制输出

//2 用unsigned long long表示64位
printf("%llu\n", num); //十进制输出
// printf(“%#llx\n”, num); //十六进制输出


    return 0;
}