#include<string>
#include<vector>
#include<iostream>


std::vector<std::string> solution(const std::string &s)
{
    std::vector<std::string> result;
   
    for( int x =0 ; x < s.length(); x+=2)
    {
        std::string new_str =s.substr(x,2);
        // std::cout<<new_str<<std::endl;
        result.push_back(new_str);
    }
  
    
    if(s.length()&0x01)
    {
        result[result.size()-1].append("_");
        // cout<<" length = " << s.length()<<"X= " <<x<<endl;

    }
    return result; // Your code here
}


int main()
{
    using namespace std;

    std::string test ="LovePizza";
    std::vector<std::string> result;

   
    // for( int x =0 ; x < test.length(); x+=2)
    // {
    //     std::string new_str =test.substr(x,2);
    //     std::cout<<new_str<<std::endl;
    //     result.push_back(new_str);
    // }
  
    
    // if(test.length()&0x01)
    // {
    //     result[result.size()-1].append("_");
    //     cout<<" length = " << test.length()<<"X= " <<x<<endl;

    // }

    result = solution(test);

     for( std::string x :result)
//    for(int x=0; x< result.size();x++)
   {
        cout<<x.c_str()<<endl;
   }

    
}