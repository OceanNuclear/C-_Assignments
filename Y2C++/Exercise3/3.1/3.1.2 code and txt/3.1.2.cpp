//random2.cpp (N.Thomas 2012)
//Simple random-number generator based on Numerical Recipes 'ranqd2'
//Constructs a histogram for distribution of pseudorandom numbers between 0 and 1

#include <iostream>		//Header for C++ output stream 'cout'
#include <conio.h>		//Header for console I/O _getch()
#include <fstream>		//Header for writing to a file
#include <ctime>		//Header for time functions
using namespace std;

int main()
{	//declarations for generating the random number
	const unsigned IM=1664525;      //Integer constant for RNG algorithm
	const unsigned IC=1013904223;   //Integer constant for RNG algorithm
	const double zscale=1.0/0xFFFFFFFF; //Scaling factor for random double between 0 and 1
	unsigned iran=time(0);			//Seeds the random-number generator with the system time.
	double z;						//To hold a random double between 0 and 1 to decide whether to go forward or backwards.
	const int nbin=201;				//Number of bins in histogram ranges from -100 to +100, inclusive.
	const int nsteps=100;			//Number of steps walked for 
	const int M=1000000;			//Number of step

	
	//Initialize the histogram:
	int hist[nbin];					
	for(int i=0;i<=nbin;i++)hist[i]=0;
	
	clock_t start,end;				//Variables for timing the program
	//Write to the console using cout:    
	cout<<"Seed = "<<iran<<endl; //Prints the RNG seed
	cout<<"Calculating the histogram for "<<nsteps<< " random numbers..."<<endl;

	start=clock(); //Records the start time
	
	//Construct the histogram:
	for(int i=1;i<=M;i++)
	{int displacement = 0;			//initialize variable which represents the number of steps forward.
	
	for(int x=0; x<nsteps; x++)		//for loop to simulate the 100 steps walk.
		{
		if(zscale*double(iran = IM*iran +IC)>0.5) {displacement++;}
		else displacement--;
		}
		
	hist[displacement+100]++;//tally the result
		//The +100 is used for shifting the range from -100 --> +100 to 0 --> 200
		//(using the given rules)If we take x steps forwards then we have to take N-x = 100-x steps back
		//thus the final displacement = x - 100 + x = 2x - 100
		//The final displacement must be an even number, i.e. D = -100, -98, ..., 0 , ..., 98, 100.
	}
	end=clock(); //Records the finish time


	//Print the histogram numerically (to file and on screen):
	//Print header.
	cout<<"bin\tcount"<<endl;
	
	ofstream histogram;
	histogram.open("histogram.txt");
	histogram<<"bin\tcount"<<endl;
	
	//For easier editing in Excel, I will print a "version two" of the same histogram 
	//which only has even numbered boxes, since we know that the odd numbered ones are always 0 (line50)
	ofstream histogram2;
	histogram2.open("histogram2.txt");
	histogram2<<"bin\tcount"<<endl;	
	
	for(int i=0;i<=nbin;i++)//for loop to print out the content
	{cout<<i-100<<"\t"<<hist[i]<<endl;
	histogram<<i-100<<"\t"<<hist[i]<<endl;}

	for(int i=0;i<=nbin;i+=2) histogram2<<i-100<<"\t"<<hist[i]<<endl; 
	
	cout<<"Time taken = "<<(end-start)/double(CLOCKS_PER_SEC)<<" seconds\n"; //Prints the time taken
	
	histogram.close();
	histogram2.close();
	
	cout<<"Press any key to exit...";
	_getch();     //Wait for a key to be pressed

	return 0;
} //End of main()
