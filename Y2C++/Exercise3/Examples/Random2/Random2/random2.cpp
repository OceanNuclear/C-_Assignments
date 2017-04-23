//random2.cpp (N.Thomas 2012)
//Simple random-number generator based on Numerical Recipes 'ranqd2'
//Constructs a histogram for distribution of pseudorandom numbers between 0 and 1

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
	const int nbin=20;				//Number of bins in histogram
	const int nsteps=nbin*1000000;	//Number of steps
	int hist[nbin];					//Array for histogram

	clock_t start,end;				//Variables for timing the program

	//Uncomment the following line to use a random seed:
	//iran=time(0); //Seeds the RNG from the system time

	//Initialize the histogram:
	for(int i=0;i<nbin;i++)hist[i]=0;

	//Write to the console using cout:    
	cout<<"Seed = "<<iran<<endl; //Prints the RNG seed
	cout<<"Calculating the histogram for "<<nbin<< " million random numbers..."<<endl;

	start=clock(); //Records the start time
	//Construct the histogram:
	for(int i=1;i<=nsteps;i++)hist[int(nbin*zscale*double(iran=IM*iran+IC))]++;
	end=clock(); //Records the finish time

	//Print the histogram on the screen:
	cout<<"bin\tcount"<<endl;
	for(int i=0;i<nbin;i++)cout<<i<<"\t"<<hist[i]<<endl;

	cout<<"Time taken = "<<(end-start)/double(CLOCKS_PER_SEC)<<" seconds\n"; //Prints the time taken

	cout<<"Press any key to exit...";
	_getch();     //Wait for a key to be pressed

	return 1;
} //End of main()
