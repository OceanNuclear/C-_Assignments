#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;

double E(double n, double m, double L, double h, double eV);

int main(){
//name the program
	cout<<setw(50)<<"week11 error proofing"
		<<endl<<endl;
//define
double n, N;
bool r1=1, r2=1;
double lambda, m, L, h=6.6260693E-34, mp=1.67262171E-27, me=9.1093826E-31, eV=1.602E-19;
double x;
string P, error("Invalid value, please enter a positive integer only, then press enter.");

//input
cout<<"Please type in the type of the particle(p/e)."<<endl;
cin>>P;
while (r1==1){ 

if(P=="p"){
m=mp;
L=1E-14;
r1=0;
}

else if(P=="e"){
m=me;
L=1E-10;
r1=0;
}

else {
	cout<<"Please enter either 'p' or 'e'only, then press enter!";
	r1=1;
	cin>>P;
	}
}

cout<<"type in an integer value the energy level=n."<<endl;
/*
while(r2==1){
if (!(cin >> n)||(n<0)||(n==0)||(n=!(int)n)) {
 	cin.clear();
    cin.ignore(255,'\n');
	r2=1;
	cout<<error<<endl;
	}

else {
	cout<<n<<endl<<"else part"<<endl;
	cout<<setiosflags(ios::scientific)<<"energy of the particle="<<E(n,m,L,h,eV)<<endl;
	r2=0;
	}
}
*/
/*while ((x < 1) || (x > 3)) {
    cout << "Enter either 1, 2 or 3: ";
    if (!(cin >> x)) {
        cin.clear();
        cin.ignore(255,'\n');
    }
    if ((x < 1) || (x > 3)) {
        cout << "Input out of range. Please try again. " << endl;
    }
}*/
//extra loop to protect against non-integral value
while (r2==1){
	while (!(cin>>n)||(n<0)||(n==0)) {
    cin.clear();
    cin.ignore(255,'\n');
	r2=1;
	cout<<error<<endl;
	}
	//check for n to be integral,
	N=n;
	
	if (!(N==floor(N))){
	r2=1;
	cout<<error<<endl;
	}
	else{
	r2=0;
	}
}
	cout<<"energy of the particle="<<E(n,m,L,h,eV)<<"eV"<<endl;


return 0;}

double E(double n, double m, double L, double h, double eV)
	{
	double E=n*n*h*h/(8*m*L*L*eV);
	return E;
	}
