#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;

//variables
	double K=591507860200;
//conversion constants for programmes
 	double AU;
	
	bool z=1;
	string i;

//P2R, input period in days, turn into seconds, compute into meters, convert into AU.
float P2R(float D, float k){
	double T=86400*D;
	double r;
    r=cbrt(T*T/k);
    float rinAU=(r/(1.496E11));
    return rinAU;
}
	
//R2P, input in AU, turn into metres, compute into seconds, output in days.
float R2P(float r, float k){
	float AU=1.496E11;
	float rinm=r*AU;
	float T;
	T=sqrt(k*rinm*rinm*rinm);
	
	float days=T/86400;
	return days;
}

int main(){
//name the program
	cout<<setw(50)<<"Kepler's 3rd Law"<<endl<<endl;
	
//define var.
	float M1, M2, r, D, k;
	
//prompt input
	cout<<"What is the mass of the star, in kg?"<<endl;
	cin>>M1;
	cout<<"What is the mass of the planet, in kg?"<<endl;
	cin>>M2;
	
	k=((float)K/(M1+M2));
//all variables values inputted.

//prompt input;
	cout<<"Do you want the radius or the period of orbit?(R/P)";
	cin>>i;	

//error proofing loop
 do{

	
if(i=="R"){
	cout<<"Please enter the period of orbit, in number of days.";
	cin>>D;
	cout<<"The radius is "<<P2R(D,k)<<"AU"<<endl;
z=0;}

else if(i=="P"){
	cout<<"Please enter the length of radius, in Astronomical Units.";
	cin>>r;
	cout<<"The period is "<<R2P(r,k)<<"days"<<endl;
z=0;}

else {
	cout<<"please enter either 'R' or 'P'only, then press enter!";
	cin>>i;
}
}while(z==1);


return 0;}
