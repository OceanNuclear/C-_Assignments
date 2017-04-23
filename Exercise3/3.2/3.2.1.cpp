//Geiger Counter simulation

#include <iostream>		//Header for C++ output stream 'cout'
#include <conio.h>		//Header for console I/O _getch()
#include <fstream>		//Header for writing to a file
#include <ctime>		//Header for time functions
#include <cmath>		//Header for the ln function
#include <Windows.h>	//Header file for Windows API functions
#pragma comment(lib,"Winmm.lib") //Library for playing a wav file
using namespace std;

	//variables for random number generation
	const unsigned IM=1664525;      //Integer constant for RNG algorithm
	const unsigned IC=1013904223;   //Integer constant for RNG algorithm
	const double zscale=1.0/0xFFFFFFFF; //Scaling factor for random double between 0 and 1
	unsigned iran=time(0);			//Seeds the random-number generator with the system time.
	double z;						//to hold the random double between 0 and 1
	
main(){
	double tau = 0.2;	//tau is the average time delays between counts, i.e. tau = 1/5(s^-1) =0.2s
	double T = 0;		//Total time counting variable.
	int i = 0;			//variable to count total number of clicks that has been simulated.
	
	cout<<"interval(s)"<<endl;
	while (i<50)		//Repeat the following loop until it reaches 50 counts:
	{
		double dt = -tau*log(zscale*double(iran=IM*iran+IC)); //Time to next event (s)

		cout<<dt<<endl;	//Print the wait time (in s) to the console.
		Sleep(1000*dt); //Waits for the said amount of time (delay is in ms)
//		PlaySound(L"click.wav",0,SND_FILENAME|SND_ASYNC); //Plays the click.wav sound 
//**line 31 won't work! I followed all the instructions that I can but still it refuse to work!
		
		T+=dt;			//Tally total time in s
		i++;			//Tally total number of counts

	}
	
	cout<<"Time elapsed between the 0th to 50th click ="<<T<<"s"<<endl;
	_getch();//wait for stroke
	return 0;
}	//end of program

