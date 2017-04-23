//RandomClass.cpp
//Generates random numbers using a C++ class

#include <conio.h>	//Header for console I/O _getch()
#include <iostream>	//Header for using C++ output stream 'cout'
#include "RandomNumberGenerator.h" //Declares the RandomNumberGenerator class
#include <ctime>	//Header for time functions
using namespace std;

int main(void)
{
	clock_t start,end;				//Variables for timing the program
	const int million=1000000;		//Useful constant
	const int nsteps=10*million;	//Number of steps

	//Create random-number generators:
	RandomNumberGenerator R = RandomNumberGenerator(999); //R uses automatic storage and a fixed seed
	RandomNumberGenerator *p = new RandomNumberGenerator(); //p points to a dynamically allocated RNG
	
	cout<<"The size of RandomNumberGenerator object R is "<<sizeof(R)<<" bytes\n\n";
	cout<<"The size of dynamically allocated *p is also "<<sizeof(*p)<<" bytes\n\n";
	
	RandomNumberGenerator *q = &R; //q is a pointer to the the existing object R (&R is the address of R)
	
	//Write to the console using cout:    
	cout<<"Calculating "<<3*nsteps/million<< " million random numbers...\n";
	
	start=clock(); //Starts the clock
	//Generate millions of random numbers:
	for(int i=0;i<nsteps;i++)
	{
		R.Z(); //Calls Z() method for object R using direct addressing
		p->Z(); //Calls Z() method for object R using a pointer
		q->Z(); //Calls Z() method for the dynamically allocated RNG
	}  //End i loop

	end=clock(); //Stops the clock
	cout<<"Time taken = "<<(end-start)/(1.*CLOCKS_PER_SEC)<<" seconds\n\n"; //Prints the time taken
	delete p; //Deletes the dynamically allocated RNG

	cout<<"Press any key to exit...\n";
	_getch();	//Wait for a key to be pressed
	
	return 0;
} //End of main()
