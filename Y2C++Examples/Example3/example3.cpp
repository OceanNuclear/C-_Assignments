//example3.cpp
//Write results from Example 2 to a text file
//Tabulate the position y at time t in free fall from rest under gravity

//Include standard header files here:
//(To keep things simple, we're not using a separate header file)
#include <iostream>		//Declares cout
#include <fstream>		//Use for file output
#include <conio.h>		//Declares the _getch() function
using namespace std;	//Allows use of cout instead of std::cout

//Main program:
int main(void)
{
	//Declare parameters for the problem as constants:
	const double g=9.81;		//Standard value of g (in m/s^2) cannot be changed.
	const double y0=1000.;		//y0 = Initial position at t=0 (in m)
	const double tmax=10.;		//tmax = Maximum time (in s)
	const int npoints=100;		//npoints = Number of points
	const double dt=tmax/npoints; //dt = Time increment (in s)
	//Declare variables used in the calculation:
	double y, t;			//y = Vertical position (in m), t = time taken (in s)

	ofstream outs;				//outs is the name of the output stream
	outs.open("output.txt");	//Opens the file output.txt

	//Print a column header for the t & y values on the screen:
	cout << "t" << "\t" << "y" << endl; //Note that "\t" inserts a tab separator
	outs << "t" << "\t" << "y" << endl; //Writes to the output file

	//Loop from i=0 to npoints:
	for (int i=0; i<=npoints; i++) //Starts the ‘for’ loop (Can declare counter i here)
		{
			t = i*dt;			//Calculates the time taken
			y = y0-0.5*g*t*t;	//Calculates the position (taking y=0 at t=0)

			//Print the t & y values to the screen:
			cout << t << "\t" << y << endl;
			outs << t << "\t" << y << endl; //Saves results to output.txt
		} //End of the ‘for’ loop

	outs.close(); //Closes the output file

	cout<<"Press a key to exit...";
	_getch();	//Waits for a keystroke before closing the console window
	return 0;
} //End of main()
