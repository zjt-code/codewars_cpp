#include<stdio.h>
#include<ctype.h>

bool is_valid_ISBN_10 (const char *ISBN)
{
    size_t sum =0,index;

    for(index =1;*ISBN != '\0';ISBN++,index++)
    {
        size_t value =  isdigit(*ISBN)?(*ISBN-'0'):(*ISBN == 'X' && index ==10 ?10:(0-1));

        printf("value = %d \r\n", value);

        if( value < 0 ) return false;
        else
        sum += value * index;

    }
    if(index !=11)return false;
-   printf("sum =%d\r\n",sum);
    return (sum%11==0);
}


int main()
{

    if(is_valid_ISBN_10("X123456788"))
    {
        printf(" ISBN OK\r\n");
    }
    else{printf(" ISBN FAIL\r\n");}


    printf("%d\r\n", isdigit('4'));

    return 0;
}