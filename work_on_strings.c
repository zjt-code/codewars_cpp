#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>



void caculate_char_cnt( int *cnt_array, const char *a,const char *b)
{

  const char *temp_p = b;

  int a_len = strlen(a),b_len = strlen(b);


  while(a_len)
  {
       char *temp=strchr(temp_p,a[a_len-1]);

       if(temp != NULL){printf("%s\r\n",temp);}

       if( (temp!=NULL) && ((temp <=(b+b_len))))
       {
            temp_p = temp+1;
            cnt_array[a[a_len-1]]++;
            
            
       }
       else
       {
        // printf("%c  times = %d\r\n",a[a_len-1],cnt_array[a[a_len-1]]);
         temp_p = b;
         while(cnt_array[a[a_len-1]])a_len --; 
       }    
  }



}




// char *work_on_strings(const char *a, const char *b) {

//   int a_len = strlen(a),b_len = strlen(b);
//   int total_len = a_len+b_len;
 

//   int a_char_cnt[255]={0};
//   int b_char_cnt[255]={0};

//   char * p=(char *)malloc(total_len);
//   sprintf(p,"%s%s",a,b);

//   caculate_char_cnt(a_char_cnt,a,b);
//   caculate_char_cnt(b_char_cnt,b,a);


// //   while(a_len)
// //   {
// //        char *temp=strchr(temp_p,a[a_len-1]);

// //        if(temp != NULL){printf("%s\r\n",temp);}

// //        if( (temp!=NULL) && ((temp <=(b+b_len))))
// //        {
// //             temp_p = temp+1;
// //             a_char_cnt[a[a_len-1]]++;
            
            
// //        }
// //        else
// //        {
// //          printf("%c  times = %d\r\n",a[a_len-1],a_char_cnt[a[a_len-1]]);
// //          temp_p = b;
// //          a_len --; 
// //        }    
// //   }


//     //    a_len = strlen(a);

//     //    while(a_len)
//     //    {
//     //     //  printf("%c  times = %d\r\n",a[a_len-1],a_char_cnt[a[a_len-1]]);
//     //      if(a_char_cnt[p[a_len-1]]&0x01)
//     //         p[a_len-1] = islower(p[a_len-1])?toupper(p[a_len-1]) :tolower(p[a_len-1]);

//     //      a_len--;
//     //    }  
  

//        char * temp_p = p+ strlen(a);
//        while(b_len)
//        {
//          printf("%c  times = %d\r\n",temp_p[b_len-1],a_char_cnt[temp_p[b_len-1]]);
//          if(a_char_cnt[temp_p[b_len-1]]&0x01)
//             temp_p[b_len-1] = islower(temp_p[b_len-1])?toupper(temp_p[b_len-1]) :tolower(temp_p[b_len-1]);

//          b_len--;
//        } 
//   return p;
// }

// char *work_on_strings(const char *a, const char *b) 
// {
//   int a_len = strlen(a),b_len = strlen(b);
//   int total_len = a_len+b_len;
//   char * p=(char *)calloc(total_len+1,sizeof(char));
//   sprintf(p,"%s%s",a,b);
//   while(a_len)
//   {
//     char find_char = a[a_len-1];
//     int  b_find_len = b_len;
//     while(b_find_len)
//     {
//       if(tolower(find_char) == tolower(b[b_find_len-1]))
//       p[a_len-1] = isupper(p[a_len-1])?tolower(p[a_len-1]):toupper(p[a_len-1]);

//       b_find_len--;
//     }

//     a_len--;
//   }


//   while (b_len)
//   {
//      char find_char = b[b_len-1];
//      int  a_find_len = strlen(a);
//     // printf("index = %d, find_char = %c\r\n",b_len-1,find_char);
//      while(a_find_len){

//       if(tolower(find_char) == tolower(a[a_find_len-1]))
//       {
//         p[total_len-1] = isupper(p[total_len-1])?tolower(p[total_len-1]):toupper(p[total_len-1]);
//       }      
//       a_find_len--;
//      }
//      total_len--;

//      b_len--;
//   }  
//   return p;
// }

char *work_on_strings(const char *a, const char *b) 
{
  int a_len = strlen(a),b_len = strlen(b);
  int total_len = a_len+b_len;
  char * p=(char *)calloc(total_len+1,sizeof(char));
  sprintf(p,"%s%s",a,b);
  while(a_len)
  {
    char find_char = a[a_len-1];
    int  b_find_len = b_len;
    while(b_find_len)
    {
      if(tolower(find_char) == tolower(b[b_find_len-1]))
      p[a_len-1] ^=32;
      b_find_len--;
    }
    a_len--;
  }


  while (b_len)
  {
     char find_char = b[b_len-1];
     int  a_find_len = strlen(a);
     while(a_find_len){

      if(tolower(find_char) == tolower(a[a_find_len-1]))
      {
        p[total_len-1] ^=32;
      }      
      a_find_len--;
     }
     total_len--;
     b_len--;
  }  
  return p;
}


int main()
{
    clock_t t_start,t_end;

    float timeelapse =0;

    t_start = clock();

    //abcDeFGtrzWDEFGgGFhjkWqE
    //ABCDEfGTRZWDEFGgGFhjkWqEdEFgGgFHJKwQEABCdEfgTRZwdEFgGgFHJKwQE
    printf("%s\r\n",work_on_strings("abcdeFgtrzwdefgGgfhjkwqe","defgGgfhjkwqeabcdeFgtrzwdefgGgfhjkwqe"));

    t_end = clock();
    timeelapse = (float)(t_end-t_start)/CLOCKS_PER_SEC;

    printf(" running time = %fs\r\n",timeelapse);


    char test_a = 'g';
    test_a ^=32;

    int test_b =10000;

    test_b ^= 32;

    printf("test_b = %d\r\n", test_b);

    printf("%c\r\n",test_a);

    return 0;
}