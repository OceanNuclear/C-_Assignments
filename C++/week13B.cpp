#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<assert.h>
using namespace std;

int n, b=2;
int bin(int n){
	if (n<b) return n;
	else {cout<<bin(n/b); return n%b;}
	}


int main(){

	cout<<setw(50)<<"week 13 recursive calls"
		<<endl<<endl;

cout<<"Type in the positive integer in base-10."<<endl;
cin>>n;

assert (n>-1);

cout<<bin(n);

return 0;}

