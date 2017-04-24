#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
int main(){
	//define var.
float c;
float gamma=1.6666667; 
float P;  
float k=1.38064852E-23; 
float T; 
float m=1.673E-27; 
float t=0;
float v;

	//introductory display
cout<<"A spacecraft accelerating in a cloud of neutral hydrogen,"
	<<endl;
cout<<"it will cause a shockwave at ";

	//declare values of c and v,
v=(300+10*t);
T=100;
c=sqrt((gamma*k*T)/m);

	//calculation by loop
while(v<c){
	t++;
	T=(100+0.3*t);
	c=sqrt((gamma*k*T)/m);
	v=(300+10*t);
}

	//displays
cout<<"time="<<t<<"s"<<endl;
cout<<endl;
cout<<"at that second,"<<endl;
cout<<"speed="<<v<<"m/s"<<endl;
cout<<"speed of sound="<<c<<"m/s"<<endl;
cout<<"temperature="<<T<<"K"<<endl;

return 0;}
