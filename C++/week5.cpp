#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int main(){

float n; int N; int m; int t;//n is initial, N integer-ed, m is interval no., t is time.
cout<<"What is the number of atoms at 0th minute?";//prompt inupt
cin>>n;

cout<<setw(10)<<setiosflags(ios::right)<<"Time(minutes)|"
	<<setw(10)<<setiosflags(ios::right)<<"Number of atoms"
	<<endl;

cout<<setw(10)<<setiosflags(ios::right)<<0
	<<setw(10)<<setiosflags(ios::right)<<n
	<<endl;
for(m=1; m<9; m++){
	
	n=n/sqrt(2);
	t=30*m;
	N=(int)n;
	
	cout<<setw(10)<<setiosflags(ios::right)<<t
		<<setw(10)<<setiosflags(ios::right)<<N
		<<endl;
}
 
cout<<"*Decimal numbers are rounded down.";
return 0;}
