#include<iostream>
#include<sstream>

using namespace std;


std::string highestScoringWord(const std::string &str)
{

  std::stringstream ss(str);
  std::string max_str,res;

  int max_score=0,score=0;
  
  while (ss>>res)
  {
    score = 0;
    for(auto x:res)score+=x-'a'+1;    
    if(score > max_score)
    {
        max_str = res; 
        max_score = score;
    }   
  }  

  return max_str;
}



int main(int arg, char *arv[])
{

    cout<<highestScoringWord("man i need a taxi up to ubud")<<endl;


    return 0;
}