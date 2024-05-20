#include "codwars_lv5.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * orderweight( const char * s)
{



return NULL;

}


char * likes(size_t n, const char * const names[n])
{
    
        const char no_one_str[] ="no one likes this";
        // const char two_more_str[]= " and 2 others like";
        char * p_likes =NULL;
        if(n)
        {
            if(n ==1)
            {
                size_t len = strlen(names[0]) + strlen(" likes this");
                p_likes = malloc(len + 1);
                strcpy(p_likes,names[0]);
                strcat(p_likes," likes this");                
            }
            else if( n==2)
            {
                size_t len = strlen(names[0]) + strlen(" and ") + strlen(names[1]) +strlen(" like this");
                p_likes = malloc(len + 1);
                strcpy(p_likes,names[0]);
                strcat(p_likes," and ");
                strcat(p_likes,names[1]); 
                strcat(p_likes," like this");   

            }
            else if( n==3)
            {
                size_t len = strlen(names[0]) + strlen(", ") + 
                strlen(names[1]) + strlen(" and ")+ strlen(names[2]) + strlen(" like this");        
                p_likes = malloc(len + 1);
                strcpy(p_likes,names[0]);
                strcat(p_likes,", ");
                strcat(p_likes,names[1]);
                strcat(p_likes," and ");
                strcat(p_likes,names[2]); 
                strcat(p_likes," like this");  
            }
            else{
                char num_str[100];
                //memset(num_str,0,100);

                sprintf(num_str," and %d others like this",n-2);

                

                size_t len = strlen(names[0]) +strlen(", ") + strlen(names[1]) +  strlen(num_str);
                p_likes = malloc(len + 1);
                strcpy(p_likes,names[0]);
                strcat(p_likes,", ");
                strcat(p_likes,names[1]);
                strcpy(p_likes + strlen(p_likes),num_str);   
            }


        }
        else{
             p_likes = malloc(strlen(no_one_str) + 1); //add null character '\0';
             strcpy(p_likes,no_one_str);
        }
    return (char *)p_likes;
}