#include<vector>
#include<iostream>

using namespace std;

int find_even_index (const vector <int> numbers) {

 size_t sum0=0,sum1=0;
 for(size_t x =0; x< numbers.size(); x++)
   {        //reset sum
            sum1=0;
            sum0=0;
            //cal sum0
            for(size_t y=0; y<= x; y++){sum0+=numbers[y];}
            //cal sum1
            for(size_t y=x; y< numbers.size();y++){sum1+=numbers[y];}
            if(sum0==sum1)return x;
   }

  return -1;
}

vector <int> numbers {  1,2,3,4,5,6 };

int main()
{
    int res;

    res= find_even_index(numbers);

    cout<<"result = "<<res<<endl;

}
