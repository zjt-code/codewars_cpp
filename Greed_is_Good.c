#include<stdio.h>
#include<stdlib.h>





int score(const int dice[5]) {

    //  <----  hajime!

    int score =0;
    int num = 1,num_cnt=0;

    for(num = 1; num <=6; num++)
    {
        num_cnt=0;

        for(int x =0; x < 5; x++)
        { 
            if(dice[x] == num)num_cnt++;            
           // printf("dice[%d] = %d, num = %d,num_cnt =%d\r\n", x,dice[x], num,num_cnt);
        }

        if(num_cnt >= 3){ score =0;break;}
    }
    //printf("num_cnt = %u\r\n", num_cnt);

    if(num_cnt >=3)
    {
    switch( num)
    {
        case 1:
        
            score+=1000 + (num_cnt - 3) *100;            
            for(int x =0; x < 5; x++){if(dice[x] == 5)score+=50;}

        break;
        case 2 ...4:
        case 6:
              score = num*100 ;
              for(int x=0; x< 5; x++)
              {
                score += ( dice[x] == 1) ? 100 : (dice[x]==5) ? 50 : 0 ;
              }
        break;
        case 5:
             score = num*100  + (num_cnt-3)*50;             
             for(int x =0; x < 5; x++){if(dice[x] == 1)score+=100;}
        break;
        default:
            score = 0;
        break;
    }
    }
    else{ 
        for(int x =0; x <5; x++)
        {
            score += ( dice[x] == 1) ? 100 : (dice[x]==5) ? 50 : 0 ;

        }
    }

    return score;
}



int main()
{

    int dice[] = {2, 4, 4, 5, 4};

    printf("score = %u\r\n", score(dice));


    printf("greed is good\r\n");

    return 0;
}