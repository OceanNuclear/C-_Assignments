//random1.cpp (N.Thomas 2012)
//Simple random-number generator based on Numerical Recipes 'ranqd2'
//Generates pseudorandom numbers between 0 and 1

#include <iostream>		//Header for C++ output stream 'cout'
#include <conio.h>		//Header for console I/O _getch()
#include <ctime>		//Header for time functions
using namespace std;

int main(void)
{
	const unsigned IM=1664525;      //Integer constant for RNG algorithm
	const unsigned IC=1013904223;   //Integer constant for RNG algorithm
	const double zscale=1.0/0xFFFFFFFF; //Scaling factor for random double between 0 and 1
	unsigned iran=9999;				//Seeds the random-number generator
	double z;						//Holds random double between 0 and 1
	const int nsteps=20;			//Number of steps

	//Uncomment the following line to use a random seed:
	//iran=time(0); //Seeds the RNG from the system time

	//Write to console using cout    
	cout<<"Seed = "<<iran<<endl; //Prints the RNG seed
	cout<<"Calculating "<<nsteps<< " random numbers..."<<endl<<endl;
	cout<<"Number\tiran\t\tz"<<endl; //Prints a column header

	//Generate random numbers:
	for(int i=1;i<=nsteps;i++)
	{
		z=zscale*double(iran=IM*iran+IC); //RNG algorithm based on Numerical Recipes 'ranqd2'
		cout<<i<<"\t"<<iran<<"\t"<<z<<endl; //Print result to the console
	}

	cout<<"Press any key to exit...";
	_getch();     //Wait for a key to be pressed

	return 1;
} //End of main()
