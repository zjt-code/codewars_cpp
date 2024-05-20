#include<map>
#include<iostream>
#include<set>

// excellent code 
// #include <map>
// #include <string>

// std::map<char, unsigned> count(const std::string& string) {
//   std::map<char, unsigned> r;
//   for (const char& c: string) ++r[c];
//   return r;
// }

// //#include <map>
// #include <string>
// #include <algorithm>
// #include <set>

// std::map<char, unsigned> count(const std::string& string) {
//   std::map<char, unsigned> result;
//   std::set<char> characters;
//   int count;
  
//   for (char c : string){
//     characters.insert(c);
//   }
  
//   for (char c : characters){
//     count = std::count(string.begin(), string.end(), c);
//     result.insert(std::pair<char, unsigned> (c, count));
//     std::cout << c << std::endl;
//   }
  
//   return result;
// }



using namespace std;

std::map<char, unsigned> count(const std::string& string) {

    std::map<char,unsigned>res;
    std::set<char> uiq_str{string.cbegin(),string.cend()};
    for(auto x : uiq_str)
     {
        int cnt=0;    
        for(size_t y =0; y< string.length(); y++)
            if(string.at(y)==x)cnt++;
        cout<<x<<"="<<cnt<<endl;
        res.insert({x,cnt}); 
     }  

    return res;
}


int main()
{

    std::map<char,unsigned>res;

    res = count("aba");

    for(auto x: res)
        cout<< x.first << "=" << x.second<<endl;


    cout<<"hello world"<<endl;

    return 0;
}