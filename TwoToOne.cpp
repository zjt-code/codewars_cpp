#include<iostream>

class TwoToOne
{
public:
    static std::string longest(const std::string &s1, const std::string &s2);
};


std::string TwoToOne::longest( const std::string &s1, const std::string &s2)
{
    std::string result;
    

    for(char c = 'a'; c <='z'; c++)
    {
        if((s1.find(c,0) < s1.length())||(s2.find(c,0)<s2.length()))
        result.append(1,c);  
    }

    return result;
}

int main()
{
   using namespace std;

   TwoToOne test;

    cout<<test.longest("loopingisfunbutdangerous", "lessdangerousthancoding")<<endl;


    return 0;
}