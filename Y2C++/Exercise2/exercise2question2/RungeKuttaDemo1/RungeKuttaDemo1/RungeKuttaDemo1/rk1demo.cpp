//Demonstration of Runge-Kutta integration routine rk1() (N. Thomas 2012)
//Integrates the differential equation for radioactive decay
//Writes results to the file rk1out.txt for pasting into an Excel spreadsheet

#include <cmath>	//Header file for maths functions
#include <iostream>	//Allows us to use cout
#include <fstream>	//Allows us to write to a file
#include <conio.h>	//Declares _getch()
using namespace std;

//Function declarations:
inline double deriv(double t, double v);	//Function prototype for the derivative
void rk1(double& v, double t1, double t2);	//Function prototype for the Runge-Kutta algorithm

//Declare a global constant for use in both deriv() and main():
const double g = 9.81;	//Acceleration due to gravity(m/s^2).
						//Note that downward is taken as positive.
const double Cd = 0.3;	//Drag coefficient, expressed as Cd instead of alpha here.
const double m = 100;	//Mass of skydiver = 100 kg, and is constant throughout.
const double k = Cd/m;	
const double v0= 0;		//we always start from velocity = 0 at time = 0.
const double v_inf = sqrt(g/k);//velocity at time = infinity.
const double tau = 1/(k*v_inf);//time constant at

//Function definition for deriv().
inline double deriv( double t , double v ) 
{
	return (g-k*pow( v , 2 ));
}
//N.B. The short function deriv() is declared as 'inline' to eliminate the overhead of a function call

//main() program:
int main()
{
	//Parameters for integration:
	double v=v0;			//v = Initial velocity at starting time.
	double tmax=30.0;		//Total time for integration (s).
	const int nsteps=200;	//Number of steps in integration.
	double dt=tmax/nsteps;	//Length of each time step (s).
	double v_theo;			//Theoretical value of v at t.
	double t1,t2;			//Start and finish times for an integration step

	//Create the output file:
	ofstream rk1out;
	rk1out.open("rk1out.txt");

	t1=0.;

	cout<<"Integrating "<<nsteps<<" steps...\n";
	cout<<"Taking downward velocity as positive.\n";
	rk1out<<"Time\tv\tTheoretical value\n";	//Writes the file header 
	cout<<"Time\tv\tTheoretical value\n";	//Writes the console header
	rk1out<<t1<<"\t"<<v0<<"\t"<<v0<<endl;	//Saves initial conditions to disk
	cout<<t1<<"\t"<<v0<<"\t"<<v0<<endl;		//Writes initial conditions to the screen

	//Start the RK integration:
	for(int i=1;i<=nsteps;i++)
		{
			t1=(i-1)*dt;	//Starting time for this integration step
			t2=i*dt;		//Finishing time for this integration step
			rk1(v,t1,t2);	//Calls rk1() to integrate deriv() from t1 to t2

			v_theo=v_inf*tanh(t2*i/tau); 				//Analytical solution

  			rk1out<<t2<<"\t"<<v<<"\t"<<v_theo<<endl;	//Saves results to disk
  			cout<<t2<<"\t"<<v<<"\t"<<v_theo<<endl;		//Writes results to screen
		}
	//End of RK integration steps

	rk1out.close();		//Closes the output file
	cout<<"\nPress a key to exit...";
	_getch();			//Waits for a keystroke before closing the console window
	return 0;   
} 
//End of main()

/*Below is the bunch of code that I could've messed with but won't because it's not worth the time to do so.*/

/***************************************************************************/
//rk1() - Simplified Runge-Kutta integration routine
//Integrates a first-order differential equation of the form dp/dt = deriv(t,p)
//Based on odeint() in 'Numerical Recipes in C', Chapter 16
void rk1(double& p, double t1, double t2) //N.B. p is called by reference so that is can be changed by rk1()
{
	static double h=t2-t1; //Adaptive step size h is initialized to t2-t1 on the first call of rk1()
	//N.B. h is a 'static' variable whose value persists between function calls
	const double hmin=0.0; //Minimum step size
	const int maxstp = 10000; //Maximum number of steps 
	const double eps=1.0e-8; //Accuracy required in rk1() routine

	int nstp;
	double t,hnext,hdid,hrk;
	double errmax,test;
	double maxarg1,maxarg2;
	double dery;
	double pcopy,pscal,perr,ptemp;
	double ak2,ak3,ak4,ak5,ak6;
	int nok,nbad; //nok & nbad can be used to check operation of the rk1() routine

	//Constants for the RK integration:
	const double tiny = 1.0e-30;
	const double safety = 0.9;
	const double pgrow = -0.2;
	const double pshrnk = -0.25;
	const double errcon = 1.89e-4;
	const double a2=0.2,a3=0.3,a4=0.6,a5=1.0,a6=0.875,
		b21=0.2,b31=3.0/40.0,b32=9.0/40.0,b41=0.3,b42=-0.9,b43=1.2,
		b51=-11.0/54.0,b52=2.5,b53=-70.0/27.0,b54=35.0/27.0,
		b61=1631.0/55296.0,b62=175.0/512.0,b63=575.0/13824.0,
		b64=44275.0/110592.0,b65=253.0/4096.0,c1=37.0/378.0,
		c3=250.0/621.0,c4=125.0/594.0,c6=512.0/1771.0,
		dc5=-277.0/14336.0;
	const double dc1=c1-2825.0/27648.0,dc3=c3-18575.0/48384.0,
		dc4=c4-13525.0/55296.0,dc6=c6-0.25;

	//cout<<"h = "<<h; //Uncomment this line to print h for each step

	t=t1;
	hrk=(t2>t1) ? fabs(h) : -fabs(h);
	nok=nbad=0;
	pcopy=p;
	for(nstp=1;nstp<=maxstp;nstp++)
		{
			dery=deriv(t,pcopy);
			pscal=fabs(pcopy)+fabs(dery*hrk)+tiny;
			if((t+hrk-t2)*(t+hrk-t1)>0.0)hrk=t2-t;
			for(;;)
				{
					//Cash-Karp Runge-Kutta formulae:
					ptemp=pcopy+b21*hrk*dery;
					ak2=deriv(t+a2*hrk,ptemp);
					ptemp=pcopy+hrk*(b31*dery+b32*ak2);
					ak3=deriv(t+a3*hrk,ptemp);
					ptemp=pcopy+hrk*(b41*dery+b42*ak2+b43*ak3);
					ak4=deriv(t+a4*hrk,ptemp);
					ptemp=pcopy+hrk*(b51*dery+b52*ak2+b53*ak3+b54*ak4);
					ak5=deriv(t+a5*hrk,ptemp);
					ptemp=pcopy+hrk*(b61*dery+b62*ak2+b63*ak3+b64*ak4+b65*ak5);
					ak6=deriv(t+a6*hrk,ptemp);
					ptemp=pcopy+hrk*(c1*dery+c3*ak3+c4*ak4+c6*ak6);
					perr=hrk*(dc1*dery+dc3*ak3+dc4*ak4+dc5*ak5+dc6*ak6);

					errmax=0.0;
					maxarg1=errmax;
					maxarg2=fabs(perr/pscal);
					errmax=(maxarg1 > maxarg2) ? maxarg1 : maxarg2;
					errmax /= eps;
					if(errmax>1.0)
						{
							hrk=safety*hrk*pow(errmax,pshrnk);
							if(hrk<0.1*hrk)hrk*=0.1;
							test=t+hrk;
							if(test==t)cout<<"RK stepsize underflow"<<endl;
							continue;
						}
					else
						{
							if(errmax>errcon)hnext=safety*hrk*pow(errmax,pgrow);
							else hnext=5.0*hrk;
							t+=(hdid=hrk);
							pcopy=ptemp;
							break;
						}
				} //End of the for(;;) loop
			if(hdid==hrk)++nok;else ++nbad;
			if((t-t2)*(t2-t1)>=0.0)
				{
					p=pcopy;
					//Save hrk to h1 for next integration step
					h=hrk;
					//cout<<", nok = "<<nok<<", nbad = "<<nbad<<endl; //Uncomment this line to print nok & nbad
					return;
				}
			if(fabs(hnext)<=hmin)cout<<"Step size too small in rk1()"<<endl;
			hrk=hnext;
		} //End of the nstp loop
	cout<<"Too many steps in rk1()"<<endl;
		
	return;
}
//End of rk1()
