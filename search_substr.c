#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int search_substr(const char *full_text, const char *search_text, bool allow_overlap) 
{
  
    int res =0;  
    int len_full_text = strlen(full_text), len_search_text = strlen(search_text);
  
    if( !len_full_text || !len_search_text) return 0;      

    while( len_full_text>0 && *full_text )
    {
        if(!strncmp(full_text,search_text,strlen(search_text)))
           { 
            res++;
            if(!allow_overlap)
            {
                  full_text += len_search_text;
                  len_full_text -= len_search_text;
            }
            else
            {
                full_text++; 
            }

           }else full_text++;        
    }  
   
    return res;
}



int main()
{

    printf("%lu\r\n",search_substr("abcabcabc", "abc",false));

    printf("%d\r\n", !strncmp("bbbcccc","bbb", strlen("bbb")));
    return 0;
}