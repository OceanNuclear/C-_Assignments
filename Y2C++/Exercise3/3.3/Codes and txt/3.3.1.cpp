//Geiger Counter histogram comparison with Poisson distribution

#include <cmath>		//Header for Log function and sqrt.
#include <fstream>		//Header for writing to a file
#include <iostream>		//Header for C++ output stream 'cout'
#include <conio.h>		//Header for console I/O _getch()
#include <ctime>		//Header for time functions
using namespace std;

	//declarations for generating the random number
	const unsigned IM=1664525;      //Integer constant for RNG algorithm
	const unsigned IC=1013904223;   //Integer constant for RNG algorithm
	const double zscale=1.0/0xFFFFFFFF; //Scaling factor for random double between 0 and 1
	unsigned iran=time(0);			//Seeds the random-number generator with the system time.
	double z;						//To hold a random double between 0 and 1.
	const int nbin=21;				//Number of bins in histogram.(from 0 to 20 inclusive)  
	const int n_interval=10000;		//Number of intervals to be simulated
	const int dt=1;					//Interval size dt=1s.
	double tau = 0.2;				//As explained, tau is the average time delays between counts
main()
{
	//Prints the RNG seed:
	cout<<"Seed = "<<iran<<endl; 
	//Initialize the histogram array:
	int hist[nbin];		
	for(int i=0;i<=nbin;i++)hist[i]=0;

	//Simulation 
	int count = 0;
	double t = 0.;
		//run the simulation for the first interval:
	while((t-=tau*log(zscale*double(iran=IM*iran+IC)))<dt) count++;
	hist[count]++; //Add up the counts until t> the interval dt=1s.
	
	for(int i =1; i <n_interval; i++)
		{count = 1; //starting at count =1 since the previous loop has already "planned" another click at t>1s,
		t = remainder(t, 1);//So the next click will be at Deltat+t'=Deltat+(t)mod(1) seconds later.
							//Note: Deltat here is the interval between two decay events.
		while((t-=tau*log(zscale*double(iran=IM*iran+IC)))<dt)count++;
		hist[count]++;} //Add up the counts until t> the interval.
	
	//Calculating the mean and sigma:
	double Mean =0;
	double Sigma=0;
	for (int i=0;i<=nbin;i++) Mean += i*hist[i];
	Mean = Mean/(n_interval);
	for (int i=0;i<=nbin;i++) Sigma += (hist[i]-Mean)*(hist[i]-Mean);
	Sigma = sqrt(Sigma)/n_interval;
	
	//Print the histogram on the screen and file:
	ofstream Geiger;
	Geiger.open("Geiger_histogram.txt");
	
	//Header
	cout<<"After simulating for "<<n_interval*dt<<"s of step size "<<dt<<"s"<<endl;	
	cout<<"count\tnumber of intervals"<<endl;
	Geiger<<"count\tnumber of intervals"<<endl;
	for(int i=0;i<nbin;i++)
		{cout<<i<<"\t"<<hist[i]<<endl;
		Geiger<<i<<"\t"<<hist[i]<<endl;}
	cout<<"Mean ="<<Mean<<" counts"<<endl;
	cout<<"Standard Devaition ="<<Sigma<<" counts"<<endl;
	Geiger<<"Mean ="<<Mean<<" counts"<<endl;
	Geiger<<"Standard Devaition ="<<Sigma<<" counts"<<endl;
	
	
	//End the program
	Geiger.close();
	_getch();
	return 0;
}
