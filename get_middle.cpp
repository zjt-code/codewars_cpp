#include<iostream>

using namespace std;


std::string get_middle(std::string input) 
{

    size_t x = (((input.length())&0x01))? 1 : 2;
    size_t pos = ( x ==1)? input.length()>>1 : (input.length()>>1)-1;
    return input.substr(pos,x);
  // return the middle character(s)
}


int main()
{

    cout<<get_middle("test")<<endl;

    return 0;
}