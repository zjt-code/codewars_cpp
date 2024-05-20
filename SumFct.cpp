#include<iostream>

using namespace std;

typedef unsigned long long ull;
class SumFct
{
  public:


  static ull perimeter(int n)
  {
        ull f0=0, f1 =1,f_s =0, sum = 1;

        for(int x=0; x< n; x++)
        {
            f_s = f0 + f1;
            cout<< " "<<f_s;
            f0 = f1;
            f1 = f_s;
            sum+=f_s;
        }

        cout<<endl;

        return sum * 4;
  }

   
};



int main()
{

SumFct A;

cout<<A.perimeter(2)<<endl;


return 0;
}