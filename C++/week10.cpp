#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;

int main(){
//name the program
	cout<<setw(50)<<"week 10 Accessing files"
		<<endl<<endl;

//define
ifstream atno("ae11_atoms.txt");
ifstream time("ae11_times.txt");
	//the two files are already in C++\HYW543\ADF\Storage\H\W U: drive
//define variables
int a, b, ha, hb, oa, ob;
float t;

//make the system remember the parameters.
!atno.eof();
	atno>>a;
!atno.eof();
	atno>>ha;
!atno.eof();
	atno>>b;
!atno.eof();
	atno>>hb;

//preliminary display,
cout<<"NA stands for number of atoms left in sample A,"<<endl
	<<"NB stands for number of atoms left in sample B."<<endl;
	
cout<<setw(30)<<setiosflags(ios::right)<<"Time(minutes)|"
	<<setw(10)<<setiosflags(ios::right)<<"NA|"
	<<setw(10)<<setiosflags(ios::right)<<"NB"
	<<endl;
	
//calculations
while(!time.eof()){
time>>t;
oa=a*pow(2,(-t/ha));
ob=b*pow(2,(-t/hb));
cout<<setw(30)<<setiosflags(ios::right)<<t
	<<setw(10)<<setiosflags(ios::right)<<oa
	<<setw(10)<<setiosflags(ios::right)<<ob
	<<endl;
}

return 0;}
