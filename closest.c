#define _GNU_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<math.h>



typedef struct closest
{
    /* data */
    int num_weight;
    int index;
    int value;
}t_closet;


void swap(t_closet ** a, t_closet **b)
{
    t_closet *s = *a;
    *a = *b;
    *b = s;        
}

void find_two_min_index(t_closet **mina, t_closet **minb, t_closet **cmp)
{ 
    t_closet *new_a = *mina,*new_b = *minb,*new_cmp = *cmp;

    if((new_a->num_weight - new_cmp->num_weight )||(new_b->num_weight - new_cmp->num_weight))return ;

    if(new_cmp->index < new_a->index)
    {
        swap(mina,minb);
        *mina = *cmp;
    }
    else{ if( new_cmp->index < new_b->index && new_cmp->index > new_a->index)
             {
                *minb = *cmp;
             } 
             }

}


char *closest(const char *strng) {
// return a heap-allocated string:
    //return calloc(1, 1);
     char *res;


    if(!strlen(strng))
    {
         asprintf(&res, "{{%d,%d,%d},{%d,%d,%d}}",0,0,0,0,0,0);

         return res;
         
    }

    // const char * test_str = strng;

    char * test_str =(char *)calloc(strlen(strng)+1,sizeof(char));
    
    if(test_str ==NULL){printf("test str malloc Fail\r\n");}

    strcpy(test_str,strng);

    int num_cnt = 0;
    // const char * str_end = strng + strlen(strng);
    t_closet **num_arry = malloc( sizeof( t_closet *));

    char *tok,*tok_end;

    int mul =0;
    tok = strtok((char *)test_str," ");
    printf("tok =%s\r\n", tok);
    while (tok)
    {
        num_arry = (t_closet **)realloc(num_arry,sizeof(t_closet *)*(num_cnt+1));

        if(num_arry ==NULL)printf("realloc is fail\r\n");

        num_arry[num_cnt] = (t_closet * )calloc(1,sizeof(t_closet));
        num_arry[num_cnt]->index = num_cnt;
    
        mul =0;
        tok_end = tok+ strlen(tok)- 1;

        printf("TOK len=%lu, tok = %c\r\n",strlen(tok),*tok);

        while (tok_end >= tok)
        {
           // printf("%d",*tok_end -'0');
            num_arry[num_cnt]->num_weight += (int)(*tok_end -'0');
            num_arry[num_cnt]->value +=  (int)pow(10,mul)* (int)(*tok_end-'0');
            tok_end--; 
            mul++;       
            /* code */
        } 
        
       // printf("\r\n");

        /* code */
        tok = strtok(NULL," ");

        num_cnt++;

        //printf("tok = %s\r\n",tok);
    }

    // t_closet *swap =NULL;

    for(int x =0; x <(num_cnt-1);x++)
      {
          for(int y=x+1; y< num_cnt; y++)
          {
             if(num_arry[x]->num_weight > num_arry[y]->num_weight)
             {
                // swap = num_arry[x];
                // num_arry[x] = num_arry[y];
                // num_arry[y] = swap;
                swap(&num_arry[x],&num_arry[y]);


             }

          }
      }


    for(int x =0; x < num_cnt; x++)
    {
        printf("x=%d , index =%d,weight=%d, value =%d\r\n",x, num_arry[x]->index,\
        
        num_arry[x]->num_weight,num_arry[x]->value);
    
    }
    
    //Cal min_diff

    int min_diff =0x7fffffff;

    for(int x=0; x < num_cnt-1; x++)
    {
        min_diff = (num_arry[x+1]->num_weight - num_arry[x]->num_weight) > min_diff ? min_diff: \
        ((num_arry[x+1]->num_weight - num_arry[x]->num_weight)) ;
        // min_diff = num_arry[x+1]->num_weight-num_arry[x]->num_weight;        
        printf("%d\r\n",min_diff);

    }

    // findout the mindifference element

   
    t_closet *min_a =NULL,*min_b = NULL;


    for(int x=0; x < num_cnt-1; x++)
    {
        if(min_diff == (num_arry[x+1]->num_weight - num_arry[x]->num_weight))
        {
            if( min_diff ==0 )
            {            

                if(min_a==NULL)
                {
                    min_a = (num_arry[x]->index > num_arry[x+1]->index) ? num_arry[x+1]:num_arry[x];
                    min_b = (num_arry[x]->index < num_arry[x+1]->index) ? num_arry[x+1]:num_arry[x];
                    // printf("min_a->index =%d\r\n",min_a->index);
                    // printf("min_b->index =%d\r\n",min_b->index);

                       
                }
                else{ 
                    
                    find_two_min_index(&min_a,&min_b,&num_arry[x]);
                    find_two_min_index(&min_a,&min_b,&num_arry[x+1]);
                }
            }
            else{  min_a = num_arry[x];
                   min_b = num_arry[x+1];break;}

  
                                                
        }

    }



    asprintf(&res,"{{%d, %d, %d}, {%d, %d, %d}}",  
                                        min_a->num_weight,
                                        min_a->index,
                                        min_a->value,
                                        min_b->num_weight,
                                        min_b->index,
                                        min_b->value
                                );
  
    free(test_str);
    for(int x =0 ; x < num_cnt; x++)
    free(num_arry[x]);
    free(num_arry);
 

                                return res;
   
}





int main()
{

// const char res[] = "456899 50 11992 176 272293  163 389128 96 290193 85 52";
// const char res[] = "2054803393 1367221478 131792738 1671153602 370158106 1182545645 1112238660 1700684261 649618224 1521935493";
// const char str[] = "315411 165 53195 87 318638 107 416122 121 375312 193 59";
// char *tok =NULL;
// const char str[] = "";
// const char str[] = "1165876279 2144313015 1426694512 1087949607 410854586 62357462 972566640 1436347678 483999364 103551651 638423485 1320118659 1264085172 2145246159 608859936 438720446 1585186047 1776413767 1440161509 536835888 836498280 731018188 968853658 1798441967 633133194 200290432 832225209";
const char str[] = "456899 50 11992 176 272293 163 389128 96 290193 85 52";

// tok = strtok( res," ");

//printf(" tok =%s\r\n", tok);

char * res = closest(str);

printf("res = %s\r\n",res);

printf("%d\r\n",0x7fffffff);


//  printf("%s\r\n",closest("456899 50  11992 176 272293 163 389128 96 290193 85 52"));
 return 0;
}