#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main(){

	int T;
	float t;
	
	cout<<"What is the temperature of the star(in Kelvin(K))?";
	cin>>T;
	
if (T<=0){
	cout<<"Theoratically impossible temperature!"<<endl;
}

else if(T>60000){
	cout<<"Inputted temperature is out of range";
}

else if(T>=30000){
	cout<<"It is a class O star.";
}

else if(T>=10000){
	cout<<"it is a class B star.";
}

else{

	t=T/500;
	
	cout<<"It is a class ";
	
	int x;
	x= (int)t;

if (x<10){

			
switch(x){
	
	case 0 :	
	case 1 :
	case 2 :
	case 3 :	
	case 4 :
	case 5 :	
	case 6 :
	cout<<"M";
	break;
	
	case 7 :	
	case 8 :	
	case 9 :
	cout<<"K";
	break;

}}
else {
	x -= 10;
	switch (x){
	
	case 0:
	case 1:
	cout<<"G";
	break;
		
	case 2:
	case 3:		
	case 4:
	cout<<"F";
	break;
		
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	cout<<"A";
	break;
	}
			
}
cout<<" star."<<endl;
}
return 0;}
