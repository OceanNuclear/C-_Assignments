//RandomNumberGenerator class implementation
#include "RandomNumberGenerator.h"
#include <ctime>	//Header for time functions

//Constants used by RandomNumberGenerator:
const unsigned IM=1664525;      //Integer constant for LCG algorithm
const unsigned IC=1013904223;   //Integer constant for LCG algorithm
const double zscale=1.0/0xFFFFFFFF; //Scaling factor for random double between 0 and 1

//Constructor definition
RandomNumberGenerator::RandomNumberGenerator(unsigned iseed)
{
	Init(iseed);
} //End of constructor

//Default constructor:
RandomNumberGenerator::RandomNumberGenerator()
{
	Init(unsigned(time(0)));	//Seeds the RNG using the system time
} //End of default constructor

//Define the Init() method:
void RandomNumberGenerator::Init(unsigned iseed)
{
	iran=iseed; //Seeds the RNG
	for(int i=0;i<32;i++)ztable[i]=zscale*double(iran=IM*iran+IC); //Initializes the shuffle table
} //End of Init()

//Z() returns a random double between 0 and 1:
double RandomNumberGenerator::Z()
{
	int index=iran % 32;//iran modulo 32 -> random index from 0 to 31
	//int index=iran & 0x0000001F;//Bitwise '&' -> random index from 0 to 31
	//int index=iran>>27;	//Right-shifts iran by 27 bits -> random index from 0 to 31
	double z=ztable[index];	//Chooses z at random from the shuffle table
	ztable[index]=zscale*double(iran=IM*iran+IC); //Generates a new random number for the shuffle table
	return z; //Returns random z between 0 and 1
} //End of Z()
