/*Program by Ocean(Hoi Wong) (1625143)
	last updated 09/10/2016
	for	Y2 Computational Physics Laboratory 2016 Exercise 1 */
	

//Include standard header files here:
#include <iostream> //Declares cout.
#include <fstream>	//Use for file output.
#include <conio.h>	//Declares the _getch() function.
#include <cmath>	//get the sine and cos functions and squaring with pow()
using namespace std;//Allows use of cout instead of std::cout

//declare global, constant variables
const double pi= M_PI; 	//import value of pi from cmath
const double g = 9.81;	//acceleration constant on surface of the earth
const double u = 10 ;	//initial speed in meters per second.


//program for calculating X, Y, and T.
double X(double u, double theta)
	{
	double theta_radian;
	theta_radian= (2*pi/360)*theta;//value of theta in radian
	
	return pow( u , 2 )* sin(2 * theta_radian) /g;
	
	//from the equation Range = 2 * (u_y/g) * (u_x) 
	//where u_y and u_x are initial velocity in y and x direction respectively.
	//					Range = u^2 * sin(2theta)/g
	}
	
double Y(double u, double theta)
	{
	double theta_radian;
	theta_radian= (2*pi/360)*theta;
	
	return pow(u*sin(theta_radian), 2)/(2*g);
	
	//from the equaiton u_y^2 = 2*g*h where h is height
	//					u_y^2/(2*g) = h
	}
	
double T(double u, double theta)
	{
	double theta_radian;
	theta_radian= (2*pi/360)*theta;
	
	return 2*(u*sin(theta_radian))/g;
	
	//from the equation time of flight = 2*(u_y/g)
	}

//Main program:
int main(void)
	{
	//open file
	ofstream traj;
	traj.open("trajectory_at_varying_angle.txt");

	// loop to calculate the values
	double theta;		//angle in degrees
	for (theta = 0.0; theta < 90.0; theta += 0.1)
		{
		double theta_radian= (2*pi/360)*theta;//declare value of theta in radian
		
		//write to file
		traj<<theta<<"\t"<<X(u,theta_radian)<<"\t"<<Y(u,theta_radian)<<"\t"<<T(u,theta_radian)<<endl;
		}
		traj.close(); 	//Closes the output file
		
		cout<<"The results for theta in the range of 0.0 to "
			<<theta
			<<"is now given in the text file trajectory_at_varying_angle.txt"
			<<endl<<endl
			<<"Press any key to exit." ;
			//assure user that the file is printed
		
		_getch();		//hold window open until keypress
		return 0;
	}
