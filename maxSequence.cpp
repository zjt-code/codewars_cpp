#include<vector>
#include<iostream>



using namespace std;



int maxSequence(const std::vector<int>& arr){
  //...
  if(!arr.size())return 0;

  int minus_sum =0,pos_sum =0,min =0; max=0;

  for(int x : arr) 
  {(x>0) ? (pos_sum+=x) : (minus_sum+=x);
    min = (min < x)?min:x;
    max = (max > x)?max:x;
  }

  if(minus_sum ==0) 
    return pos_sum;
  else
  {

    return 0;
  }


}


int main()
{
    

    cout<<"hello world"<<endl;

    return 0;

}