//random1.cpp (N.Thomas 2012)
//Modification by Hoi Wong (Ocean) 2016
//version 1: simulate a random walk of 100 steps.

#include <iostream>		//Header for C++ output stream 'cout'
#include <conio.h>		//Header for console I/O _getch()
#include <ctime>		//Header for time functions
#include <fstream>
using namespace std;

int main(void)
{
	const unsigned IM = 1664525;      //Integer constant for RNG algorithm
	const unsigned IC = 1013904223;   //Integer constant for RNG algorithm
	const double zscale = 1.0/0xFFFFFFFF; //Scaling factor for random double between 0 and 1
	unsigned iran = 9999;				//Seeds the random-number generator
	double z;						//Holds random double between 0 and 1
	int sum=0;	//a varaible to take the accumulated total(current position) of the function, initially at 0.
	const int nsteps=100;			//Number of steps
	
	iran = time(0);	//Seed the random number generator function from the system time
	
	
	//Write to console using cout    
	cout<<"Seed = "<<iran<<endl; //Print the seed
	cout<<"taking step:"<<endl;
	ofstream file;
	file.open("100_random_step4.txt");//change the number at the end before running to output separate files without overwriting the old one.
	cout<<"step number\t direction\ttotal"<<endl;
	file<<"step number\t direction\ttotal"<<endl;
	
	//generating random numbers:
	for(int i=1;i<=nsteps;i++)
	{
		cout<<i<<"\t\t";
		file<<i<<"\t\t";
		if( zscale*double(iran=IM*iran+IC) < 0.5)//The number will be smaller than 0.5 half the time, so there is 0.5 probability of stepping forward.
			{
			sum++;
			cout<<"forward \t"<<sum<<endl;
			file<<"+1\t\t"<<sum<<endl;	//use +1 to represent a forward step.
			}
		else //the remaining half of the time, it will step backwards, i.e. P(step back)=1-0.5=0.5
			{
			sum--;
			cout<<"backward \t"<<sum<<endl;
			file<<"-1\t\t"<<sum<<endl;	//use -1 to represent a backward step.
			}
		
	}
	
	file.close();
	cout<<"Press any key to exit...";
	_getch();     //Wait for a key to be pressed

	return 1;
} //End of main()
