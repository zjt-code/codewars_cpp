#include<stdio.h>
// #include<stdint.h>
#include<inttypes.h>

void uint32_to_ip(uint32_t number, char * IPv4)
{
 	*IPv4 = '\0';

     sprintf(IPv4,"%d.%d.%d.%d",number>>24,(number>>16)&0xff,(number>>8)&0xff,number&0xff);

}

int main()
{

    char Ipv4[20];

    uint32_to_ip(2149583361,Ipv4);

    printf("%s",Ipv4);

    return 0;
}