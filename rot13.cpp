#include<iostream>
#include<string>
#include<cctype>


using namespace std;

char swap(char c)
{
     char n_char;
     if(isalpha(c))
     {
        if((( c >='N')&&(c <='Z'))||(( c >='n')&&(c <='z')))
        {
            n_char = c-13;
        }
        else
        {
            n_char = c+13;
        }

        return n_char;
     }else return c;


}

std::string rot13(const std::string& str) {
  //your code here
  std::string  res;
  for( auto x: str){res+=swap(x);} 
  return res;
}



int main()
{


    // printf("%d,%d\r\n",'a','n');
    // printf("%02x,%02x\r\n",'b','o');

    // printf("%02x,%02x\r\n",'b'^0x42,'o'^0x42);

    cout<<rot13("EBG13 rknzcyr.")<<endl;


    // cout<<isalpha('=')<<endl;



    return 0;
}