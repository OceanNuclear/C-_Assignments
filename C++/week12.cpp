#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;

//define program:


int main(){
//name the program
	cout<<setw(50)<<"week 12 Point Charges."
		<<endl<<endl;

//define
double k=8987551788;
float n, N; 

//array
float c[10], p[10], q=1, F=0;



int n2=0, n3=0, n4=0, n5=0, z=0;
	//for error proofing:
bool r1=1, r2=1, r3=1, r=0, d=0;//d for dummy;
string 	pinterrorn("Invalid value, please enter a positive integer within range"),
		interror("The value entered is not an integer, please reenter!");
		
		
//output and calculations
cout<<"how many point charges do you want to compute?"<<endl;

while (r1==1){
	while (!(cin>>n)||(n<0)||(n==0)) {
    cin.clear();
    cin.ignore(255,'\n');
	r1=1;
	cout<<pinterrorn<<endl;
	}
	//check for n to be integral,
	N=n;
	
	if (!(N==floor(N))){
	r1=1;
	cout<<interror<<endl;
	}
	else if(n>10){
	r1=1;
	cout<<"the maximum number you can enter is 10!"<<endl;
	}
	else{
	r1=0;
	cout<<endl;
	}
}
while(n2<n){
	cout<<"what is the charge of particle "<<n2<<" in Coulombs?"<<endl;
while (r2==1){
	while (!(cin>>c[n2])) {
    cin.clear();
    cin.ignore(255,'\n');
	r2=1;
	cout<<"please enter a number only!"<<endl;
	
	}
	r2=0;
	cout<<endl;
	}
r2=1;
cout<<"what is the position of the particle "<<n2<<" in meters?"<<endl;
while (r3==1){
	while (!(cin>>p[n2])) {
    cin.clear();
    cin.ignore(255,'\n');
	r3=1;
	cout<<"please enter a number only!"<<endl;
	}
	r3=0;
	cout<<endl;
	}

r3=1;
n2++;
cout<<endl;
}

cout<<endl;

//table
/*
cout<<setw(30)<<setiosflags(ios::right)<<"Charge"
	<<setw(30)<<setiosflags(ios::right)<<"Position"
	<<endl;
while (n3<n){
cout<<setw(30)<<setiosflags(ios::right)<<c[n3]
	<<setw(30)<<setiosflags(ios::right)<<p[n3]
	<<endl;
n3++;
*/

//table 2
cout<<"A test particle of charge=1 C is placed at the origin i.e. position 0."<<endl;
while(d==0){
cout<<endl<<endl<<endl<<endl;
cout<<"Which of the following task do you want to do?"<<endl;

cout<<"1. Edit the charge of the test particle at position 0."<<endl
	<<"2. Edit the charge of a (previously inputted) point charge."<<endl
	<<"3. Edit the position of a (previously inputted) point charge."<<endl
	<<"4. Show a table of the point charges and their positions on the screen."<<endl
	<<"5. Show the force on the test particle."<<endl
	<<"6. Exit the program."<<endl;


cin>>z;


switch (z) {

case 1:
	cout<<"Please enter the new charge for the test particle in Coulombs.";
	r1=1;
    while (r1==1){
	while (!(cin>>q)) {
    cin.clear();
    cin.ignore(255,'\n');
	r1=1;
	cout<<pinterrorn<<endl;
	}
	r1=0;}
break;

case 2:
        cout<<"which particle's charge do you want to change?"<<endl;
        r1=1;
	while (r1==1){
	while (!(cin>>n4)||(n4<0)||(n4>n)||(n4==n)) {
    cin.clear();
    cin.ignore(255,'\n');
	r1=1;
	cout<<pinterrorn<<endl;
	}
	//check for n4 to be integral,
	N=n4;
	
	if (!(N==floor(N))){
	r1=1;
	cout<<interror<<endl;
	}
	else{
	r1=0;
	}
	cout<<endl;
	cout<<"please type in the new charge for particle "<<n4<<endl;
	cin>>c[n4];
	cout<<endl;
	}
break;

case 3:
         cout<<"which particle's position do you want to change?"<<endl;
        r1=1;
    while (r1==1){
	while (!(cin>>n4)||(n4<0)||(n4>n)||(n4==n)) {
    cin.clear();
    cin.ignore(255,'\n');
	r1=1;
	cout<<pinterrorn<<endl;
	}
	//check for n4 to be integral,
	N=n4;
	
	if (!(N==floor(N))){
	r1=1;
	cout<<interror<<endl;
	}
	else{
	r1=0;
	}
	cout<<endl;
	cout<<"please type in the new position for particle "<<n4<<endl;
	cin>>p[n4];
	cout<<endl;
	}
break;

case 4:
    cout<<setw(30)<<setiosflags(ios::right)<<"Charge"
		<<setw(30)<<setiosflags(ios::right)<<"Position"
		<<endl;
	n3=0;
	while (n3<n){
		cout<<setw(30)<<setiosflags(ios::right)<<c[n3]
		<<setw(30)<<setiosflags(ios::right)<<p[n3]
		<<endl;
		n3++;
    }
    cout<<endl;
break;

case 5:
    while (n5<n){
    F+=q*k*c[n5]/(p[n5]*abs(p[n5]));
	n5++;}
	cout<<"Force on the Particle="<<F<<"N"<<endl;
break;

case 6:
    return 0;
break;

	
default:
        cout<<"wrong value, please reenter!"<<endl;
        cin.clear();
    	cin.ignore(255,'\n');
break;
}
}
}
