#include<stdio.h>
#include<ctype.h>


typedef struct {
    int r, g, b;
} rgb;

int get_hex(const char * c)
{
    int value = tolower(*c);
    return (( value >= 'a' && value <= 'f')?(value - 'a' +10):(value - '0') );
}

rgb hex_str_to_rgb(const char *hex_str) {

    //  <----  hajime!
    rgb abc;  

    abc.r = get_hex(&hex_str[1])<<4 | get_hex(&hex_str[2]);
    abc.g = get_hex(&hex_str[3])<<4 | get_hex(&hex_str[4]);
    abc.b = get_hex(&hex_str[5])<<4 | get_hex(&hex_str[6]); 

    return abc;
}


int main()
{
    rgb abc ;

    abc = hex_str_to_rgb("#FF9933");

    printf("r:%d, g:%d, b:%d\r\n", abc.r,abc.g,abc.b);

    return 0;
}