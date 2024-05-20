#include<iostream>

class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window);
};


int Bouncingball::bouncingBall(double h, double bounce,double window)
{
    int cnt =0;

    if((h > 0 ) && ( bounce >0)&&( bounce <1)&&( window <h)&&(window >0))
    {
        for(h*=bounce; h > window; h*=bounce,cnt++);       
        return (cnt*2+1);
    }
    return -1;
}



int main()
{
using namespace std;


Bouncingball bb;

cout<<"hello wold"<<endl;

cout<<bb.bouncingBall(3,0.66,1.5)<<endl;

return 0;
}