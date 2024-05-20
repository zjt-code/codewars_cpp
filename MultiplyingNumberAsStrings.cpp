#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

long long  StringToNum( char * s)
{
    int len = strlen(s),cnt=0;
   long long num =0;
    for(;isdigit(s[len-1]);s--,cnt++)
        num+=(s[len-1]-0x30)*pow(10,cnt);

    return num;
}

int main()
{

printf("%ld\r\n",0xffffffff);


return 0;

}