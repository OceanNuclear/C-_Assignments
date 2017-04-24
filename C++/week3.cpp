#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
int main() {
string p("Is there a signal on the "); string q("?(Type in 1 when there is, 0 when there isn't)");//define strings
bool m; bool h; bool e; bool t;//define detectors

cout<<p<<"muon detector"<<q;//prompt for muon input

cin>>m;

if(m==1){
	cout<<"It is a muon"<<endl;
}

else{
	cout<<p<<"hardronic calorimeter"<<q;//prompt for had input
	cin>>h;
	if (h==1){
		cout<<p<<"E/M calorimeter"<<q;
		cin>>e;
		if (e==1){
			cout<<"It is either a proton or a pion."<<endl;
				}
		else{
			cout<<"It is either a neutron or a lambda particle."<<endl;
		}
			
}
else {
	cout<<p<<"E/M calorimeter"<<q;
	cin>>e;
	if (e==1){
		cout<<p<< "tracking chamber"<<q;
		cin>>t;
		if(t==1){
			cout<<"it is an electron."<<endl;
			}
		else{
			cout<<"it is a photon."<<endl;
		}
	}
	else{
		cout<<"it is a neutrino."<<endl;
	}
}
}
	


return 0;
}

