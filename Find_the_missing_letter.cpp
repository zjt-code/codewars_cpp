#include<vector>
#include<iostream>


char findMissingLetter(const std::vector<char>& chars)
{
  // TODO: Find the missing char in the consecutive letter sequence and return it.
  char c_start = chars[0];

  for(size_t x=1; x<chars.size(); c_start = chars[x],x++)
  {
    if((chars[x]-c_start) > 1)
     return c_start+1;    
  }  
  return ' ';
}


int main(void)
{

    // std::vector<char> chars={'a', 'b', 'c', 'd', 'f'};

    std::vector<char> chars={'O', 'Q', 'R', 'S'};

    std::cout<< findMissingLetter(chars) <<std::endl;

    return 0;
}