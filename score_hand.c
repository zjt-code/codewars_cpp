
#include<stdio.h>



int score_hand(size_t n, const char cards[n]) {

    //  <----  hajime!
    int a_cnt =0,sum=0;
    for(int x =0; x < n; x++)
    {  
         switch(cards[x])
        {
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            
                sum +=cards[x]-'0';
            break;
            case 'A':
                a_cnt++;
            break;
            case 'J':
            case 'Q':
            case 'K':
            case 'T':
                sum+=10;
            break;
            default:
            break;
        }

    }
    
   if(a_cnt)
    {
         if(a_cnt ==1)
         return (sum + 11) >21 ? (sum+ a_cnt):(sum+11 );
     
          if(a_cnt > 1)
          return (sum + 11) >=21 ? (sum+ a_cnt):(sum+11 + a_cnt -1 );

    }
    return sum;        
}



int main()
{
    char cards[]= {'8', 'A', 'A'};

    printf("%lu\r\n",score_hand(sizeof(cards),cards));
    return 0;
}