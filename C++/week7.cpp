#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	
	//define var.
float I; 
float I0;
float beta;
float phi;
float w;
float lambda;
float pi=3.14159265358979;
float theta;
float s;
float x;
float D;
float m;

float i1;
float i2;

	//given inputs
lambda=5E-7;
I0= 5E-6;
w = 170E-6;
x = 0.735E-3;
D = 5;
s = 850E-6;

	//initial calculations
theta=atan(x/D);
beta=(2*pi*w*sin(theta)/lambda);
phi=(2*pi*s*sin(theta)/lambda);
i1=(sin(beta/2)/(beta/2)); //intermediate
i2=(cos(phi/2));
I=I0*(i1*i1)*(i2*i2);


	//introduction
cout<<"Given the conditions from our assignment,"<<endl;

	//result of 1
cout<<"The intensity at the wanted point is "<<I<<"W/m^2"<<endl;
	
	//calculation of 2
theta= 0.02;
m= s*sin(theta)/lambda;
m=ceil(m);
cout<<"The required order of maximum is "<<m<<"."<<endl;


return 0;}

