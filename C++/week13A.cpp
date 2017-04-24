#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<assert.h>
using namespace std;

int a;
int b;
int GCD(int a, int b){
	if (b==0)
	return a;
	if (b>0)
	return GCD(b,a%b);
}

int main(){
//name the program
	cout<<setw(50)<<"week 13 recursive calls"
		<<endl<<endl;
//define
cout<<"Type in values of a and b respectively."<<endl;
cin>>a;
cin>>b;
assert (a>0);
cout<<GCD(a,b);


return 0;}
