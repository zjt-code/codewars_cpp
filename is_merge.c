#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>


bool comapre_char( const char *s, const char *part1, const char *part2)
{

    char * new_s = (char *)malloc(strlen(s) +1);  

    strcpy(new_s,s); 

    // compare len
    if(strlen(s) != ( strlen(part1) + strlen(part2)) ) return false;

    int len =0;
   //find all character
    for( ;*s &&( strchr(part1,*s)|| strchr(part2,*s));s++,len++);
    if(len != strlen(new_s)) return false;


        //compare sequence
    char *p_s  = new_s;
    bool step1 = false;
    // compare part1 ,and remove founded char, 
    for( p_s =new_s, len =0; (*part1) &&(strchr(p_s,*part1)); len++, part1++,p_s++)
    {   
        p_s = strchr(p_s,*part1);
       *p_s = '0'; //clear found char
    } 

    // compare part2
    for( p_s =new_s; (*part2) && strchr(p_s,*part2); len++,part2++,p_s++)
    {
        p_s = strchr(p_s,*part2) ;;
    }

  
    printf("totla len = %d\r\n",len);

    if(len != strlen(new_s)){    
        return false;
    }  


	return true;




}

bool is_merge (const char *s, const char *part1, const char *part2)
{
   return comapre_char(s,part1,part2) || comapre_char(s,part2,part1);
}



int main()
{

    printf("hello world\r\n");

    printf("%d\r\n", is_merge("acab", "ab", "ac"));


    return 0;
}