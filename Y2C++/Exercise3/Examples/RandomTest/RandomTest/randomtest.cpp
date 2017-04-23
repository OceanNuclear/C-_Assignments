//randomtest.cpp (N.Thomas 2012)
//Use this program to test that your PC (or Mac) produces the correct random sequence


#include <iostream>		//Header for C++ output stream 'cout'
#include <conio.h>		//Header for console I/O _getch()
using namespace std;

int main(void)
{
const unsigned IM=1664525;      //Integer constant for RNG algorithm
const unsigned IC=1013904223;   //Integer constant for RNG algorithm
unsigned iran=0;				//Seeds the random-number generator with iran=0 for this test
const int nsteps=11;			//Number of steps

//Write to console using cout:    
cout<<"Testing the simple random-number generator with seed iran="<<iran<<endl; //Prints the RNG seed
cout<<"\nCalculating "<<nsteps<< " random numbers..."<<endl;
cout<<"i\t"<<iran<<"\n"; //Prints the column header

//Generate the random numbers:
for(int i=1;i<=nsteps;i++)
{
	iran=IM*iran+IC; //RNG algorithm
	cout<<dec<<i<<"\t"<<hex<<iran<<endl; //N.B. Outputs iran in hex format
}

cout<<"\nThe expected sequence is:\n"
	<<"00000000, 3C6EF35F, 47502932, D1CCF6E9, AAF95334, 6252E503,\n"
	<<"9F2EC686, 57FE6C2D, A3D95FA8, 81FDBEE7, 94F0AF1A, CBF633B1.\n\n"
	<<"If your PC doesn't produce this sequence, you need to modify the RNG algorithm.\n"
	<<"See 'Numerical Recipes in C', p284.\n\n";

cout<<"Press any key to exit...";
_getch();     //Waits for a key to be pressed

return 1;
} //End of main()
