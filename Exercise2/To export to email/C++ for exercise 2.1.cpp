//Exercise 2.1: recursion mediated differential equations solving: radioactive decay


#include <iomanip>		//Allow the use of setw for better formatting.
#include <iostream>		//Declares cout.
#include <conio.h>		//Declares the _getch() function.
#include <string>		//Allow the use of string to write file names.
#include <fstream>		//Allow writing to file, so that the values can be 
						//exported and plotted on Excel.
using namespace std;	//Allows use of cout instead of std::cout.

//Declare parameters that are constant throughout the problem:
const	double	N = 1000.0		;//N = starting value of number of atoms, (dimensionless)
								//declared with a double because 
								//as we decrement the value in the program below, 
								//it will have to pass through decimal values. 
const	double	lambda = 0.1	;//Declare decay constant. (unit: 1/s)
const	double	end_time = 100.0;//End_time is the step at which the calculation loop stops,
								//and we obtain our final value. (unit: s)

// Main program:
int main(void)
{
	//Declare variables used in main program:
	double time		;//Declare time, the current value of t. (unit: s)
	double	N_t	= N	;//Declare current value of the number of remaining atoms,
					//initially N_t = 1000 = N. (dimensionless)
	double dt		;//Declare the step size variable dt,
					//to be inputted by user later.(unit: s)
	string FileName	;//Declare a file name for naming the final file.
	
	cout<<"Please enter a value for dt(step size of Euler's approximation) in s."<<endl;

	cout<<"Suggested values are"<<endl<<"0.1"<<setw(10)<<"1"<<setw(10)<<"5"<<endl;

	cin>>dt;
	
	//foolproofing user interface:
	
	if ( dt == 0.1 )
	{
	FileName = ("Euler0_1.txt");
	}
	
	else if ( dt == 1 )
	{
	FileName = ("Euler1.txt");
	}
	
	else if ( dt == 5 )
	{
	FileName = ("Euler5.txt");
	} 
	
	else if (dt >= 0 && dt < 100 )			//for all other reasonably sized step:
	{
	FileName = ("Euler.txt");				//Use a generic file name.
	}

	else 									//To prevent out of range/invalid input.
	{
		cout<<"INVALID INPUT!"<<endl;
		cout<<"Please re-start the program and enter a real positive number under 100.";
		return 1;
	}
	
	ofstream approx_file;
	approx_file.open(FileName.c_str());		//Open a file with the specified file name.
	
	cout<<"Time"<<setw(10)<<"Number of remaining atoms"<<endl;
	
	//Calculation and print loop:
	//Starting with N = 1000 which was declared earlier.	
	for (time = 0; time < end_time; time += dt)
	{
		cout<<time<<'\t'<<N_t<<endl;		//Print the remaining no. of atoms at the moment.
		approx_file<<time<<'\t'<<N_t<<endl;	//Save value to file.
		
		N_t = N_t * (1.0 - lambda*dt);		//then calculate the number of atoms
											//remaining in the next step.
	}
		cout<<time<<'\t'<<N_t<<endl;		//write out the very last line of results
		approx_file<<time<<'\t'<<N_t<<endl;	//, which is usually t=100.
		
	approx_file.close();					//Close the file.
	
	cout<<"By Euler's approximation, we have that the remaining number of atoms is "<<N_t
		<<" ."<<endl;						//Print the final resulting number of atoms.

	cout<<"This result is now printed to "<<FileName<<"."<<endl;//Assure user that it is saved.
	cout<<"Press a key to exit...";
	
	//Wait for a keystroke before closing the console window in Microsoft Visual Studio.
	_getch();
	return 0;
}	// End of main
//End of Exercise 2.1
