#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

float x;
float X;
float y;
float Y;
float r;

int main(){

srand(time(0));
(float)RAND_MAX;

int D=0;
int N=0;
float f;
int Doomsday;

//prompt input
cout<<"please type in the number of random trials you want"<<endl;
cout<<"hint: 10000 is a large enough number to give accurate approximation without too much runtime."<<endl;
cin>>Doomsday;

//loop
while(D<Doomsday){
X=rand();
Y=rand();

x=((2*(float)X/(float)RAND_MAX)-1);
y=((2*(float)Y/(float)RAND_MAX)-1);

r=sqrt(x*x+y*y);
cout<<r<<endl;

if(r<=1){
N++;
}

else{}

D++;
}
//</loop>

cout<<N<<endl;
cout<<D<<endl;
f=4*((float)N/(float)D);
cout<<"from this approximation of pi we have pi ="<<f<<endl;

return 0;}
