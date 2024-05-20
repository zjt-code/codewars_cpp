#include<iostream>
#include<vector>

using namespace std;

std::vector<int> move_zeroes(const std::vector<int>& input) {
  // your code here
    std::vector<int> result(input.size(),0);
    int cnt =0;
    for(auto x:input)
    {   
        if(x)result[cnt++] = x;
    }

    return result;
}


int main()
{
    std::vector<int> res = move_zeroes({1, 0, 1, 2, 0, 1, 3});

    for(auto x:res)
    cout<< x<<endl;

    cout<<"hello world"<<endl;

    return 0;
}