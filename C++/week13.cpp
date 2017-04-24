#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<assert.h>
using namespace std;

int a, b;
int bin(int a){
	if (a==1) return 0;
	else if (a==0) return 1;
	else if (a%2==1) {cout<<"1"; a=(a-1)/2; return bin(a);}
	else if (a%2==0) {cout<<"1"; a=(a/2); return bin(a);}//shit have to invert the order.
}

int main(){
//name the program
	cout<<setw(50)<<"week 13 recursive calls"
		<<endl<<endl;
//define
cout<<"Type in the positive integer in base-10."<<endl;
cin>>a;
assert (a>0);
cout<<bin(a);

return 0;}

