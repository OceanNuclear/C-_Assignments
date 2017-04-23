//rk2demo.cpp - Demonstration of the Runge-Kutta integration routine rkint() (N. Thomas 2012)
//Based on the routine odeint() from 'Numerical Recipes in C' Chapter 16.
//Integrates differential equations for damped simple-harmonic motion
//Writes results to the file rk2out.txt for pasting into an Excel spreadsheet

#include <iostream>	//Allows us to use cout
#include <fstream>	//Allows us to write to a file
#include <conio.h>	//Declares _getch()
#include <time.h>	//Header for time functions
#include <cmath>	//Header for maths functions
using namespace std;

//Function declarations tell the compiler about a function's return type and parameters:
//1. Function declaration for the differential equations:
void derivs(double t,double x[],double dery[]);
//2. Function declaration for the Runge-Kutta algorithm:
void rkint(double[],int,double,double,double,double&,double,int&,int&,void (*derivs)(double,double[],double[]));

//Declare global constants, which can be used in both derivs() and main():
const double omega=30.; //Angular frequency for SHM (rad/s)
const double gamma=3.; //Damping constant for SHM (/s)
//N.B. In general, the use of global variables is deprecated in C++ because they can be changed from anywhere.
//However, variables declared as 'const' cannot be changed during program execution (a useful safety feature of C++)

//Function definition for derivs(), which contains the differential equations:
void derivs(double t,double x[],double dery[])
{
	//x[1] is the position, and x[2] is the velocity
	//The 2nd-order differential equation for SHM becomes two coupled 1st-order differential equations:
	dery[1]=x[2];
	dery[2]=-omega*omega*x[1]-2.*gamma*x[2];
	return;
}
//End of derivs()

//main() program:
int main(void)
{
	clock_t start,end;			//Useful variables for timing the program

	//Parameters for integration:
	double x0=1.;				//Initial position  (m)
	double v0=0.;				//Initial velocity  (m/s)
	double dt=0.001;			//Length of time step (s)
	const int N=1000;			//Number of steps in integration
	const int NDIFF=2;			//Number of differential equations
	//Array for variables of integration:
	double x[NDIFF+1];			//Note that we don't use x[0] here	  
	//Constants for RK integration:
	double h1=0.1*dt;			//Suggested step size
	const double hmin=0.0;		//Minimum step size
	const double eps=1.0e-4;	//Accuracy required
	//Other useful variables:
	int i,nok,nbad; //nok & nbad can be used to check operation of rkint() routine
	double t0,t;

	//Output file:
	ofstream rk2out;
	rk2out.open("rk2out.txt");
	rk2out<<"Time\tx\tdx/dt"<<endl;	//Writes the file header using the tab character '\t' to separate the columns 

	//Set the initial conditions for x[1] and x[2]:
	x[1]=x0;
	x[2]=v0;
	t=0.;
	//Save initial conditions to disk:
	rk2out<<t<<"\t"<<x0<<"\t"<<v0<<endl;
  
	//Start RK integration:
	cout<<"Integrating "<<N<<" steps..."<<endl;
	start=clock();		//Start the clock

	for(i=1;i<=N;i++)
		{
			t0=(i-1)*dt;	//Starting time for this integration step
			t=i*dt;			//Finishing time for this integration step
			//Call the Runge-Kutta routine to integrate derivs() from t0 to t:
			rkint(x,NDIFF,t0,t,eps,h1,hmin,nok,nbad,derivs);
			//Save the results x[1] & x[2] for this integration step to disk:
  			rk2out<<t<<"\t"<<x[1]<<"\t"<<x[2]<<endl;
		}
	//End of RK integration steps

	end=clock();	//Stop the clock
	cout<<"Time taken = "<<1000.*(end-start)/(1.*CLK_TCK)<<" ms"<<endl;

	rk2out.close();		//Closes the output file
	cout<<"\nPress a key to exit...";
	 _getch();		//Wait for a keystroke before closing console window
	return 0;   
} 
//End of main()


/***************************************************************************/
//rkint() Runge-Kutta integration routine:
//Based on odeint() in 'Numerical Recipes in C', Chapter 16
//Integrates a set of ndiff coupled first-order ODEs from t1 to t2
//Variables of integration are in the array p[] of dimension ndiff+1
//The routine varies the step size to achieve the required accuracy eps
//See the main program for the meaning of the other parameters
void rkint(double p[],int ndiff,double t1,double t2,double eps,
				double& h1,double hmin,int& nok,int& nbad,
				void (*derivs)(double,double[],double[]))
{
	int nstp,k;
	double t,hnext,hdid,hrk;
	double errmax,test;
	double maxarg1,maxarg2;

	//Constants:
	const int maxstp = 10000;
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
	//Use dynamic memory allocation for arrays used in RK calculation:
	double *pcopy=new double[ndiff+1];
	double *dery=new double[ndiff+1];
	double *pscal=new double[ndiff+1];
	double *perr=new double[ndiff+1];
	double *ptemp=new double[ndiff+1];
	double *ak2=new double[ndiff+1];
	double *ak3=new double[ndiff+1];
	double *ak4=new double[ndiff+1];
	double *ak5=new double[ndiff+1];
	double *ak6=new double[ndiff+1];

	t=t1;
	hrk=(t2>t1) ? fabs(h1) : -fabs(h1);
	nok=nbad=0;
	for(k=1;k<=ndiff;k++)pcopy[k]=p[k];
	for(nstp=1;nstp<=maxstp;nstp++)
		{
			derivs(t,pcopy,dery);
			for(k=1;k<=ndiff;k++)pscal[k]=fabs(pcopy[k])+fabs(dery[k]*hrk)+tiny;
			if((t+hrk-t2)*(t+hrk-t1)>0.0)hrk=t2-t;
			for(;;)
				{
					//Cash-Karp Runge-Kutta formulae:
					for(k=1;k<=ndiff;k++)
						ptemp[k]=pcopy[k]+b21*hrk*dery[k];
					derivs(t+a2*hrk,ptemp,ak2);
					for(k=1;k<=ndiff;k++)
						ptemp[k]=pcopy[k]+hrk*(b31*dery[k]+b32*ak2[k]);
					derivs(t+a3*hrk,ptemp,ak3);
					for(k=1;k<=ndiff;k++)
						ptemp[k]=pcopy[k]+hrk*(b41*dery[k]+b42*ak2[k]+b43*ak3[k]);
					derivs(t+a4*hrk,ptemp,ak4);
					for(k=1;k<=ndiff;k++)
						ptemp[k]=pcopy[k]+hrk*(b51*dery[k]+b52*ak2[k]+b53*ak3[k]+b54*ak4[k]);
					derivs(t+a5*hrk,ptemp,ak5);
					for(k=1;k<=ndiff;k++)
						ptemp[k]=pcopy[k]+hrk*(b61*dery[k]+b62*ak2[k]+b63*ak3[k]+b64*ak4[k]+b65*ak5[k]);
					derivs(t+a6*hrk,ptemp,ak6);
					for(k=1;k<=ndiff;k++)
						ptemp[k]=pcopy[k]+hrk*(c1*dery[k]+c3*ak3[k]+c4*ak4[k]+c6*ak6[k]);
					for(k=1;k<=ndiff;k++)
						perr[k]=hrk*(dc1*dery[k]+dc3*ak3[k]+dc4*ak4[k]+dc5*ak5[k]+dc6*ak6[k]);
					errmax=0.0;
					for(k=1;k<=ndiff;k++)
						{
							maxarg1=errmax;
							maxarg2=fabs(perr[k]/pscal[k]);
							errmax=(maxarg1 > maxarg2) ? maxarg1 : maxarg2;
						}
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
							for(k=1;k<=ndiff;k++)pcopy[k]=ptemp[k];
							break;
						}
				} //end for(;;) loop
			if(hdid==hrk)++nok;else ++nbad;
			if((t-t2)*(t2-t1)>=0.0)
				{
					for(k=1;k<=ndiff;k++)p[k]=pcopy[k];
					//Save hrk to h1 for next integration step
					h1=hrk;
					delete[] pcopy;delete[] dery;delete[] pscal;delete[] perr;delete[] ptemp;
					delete[] ak2;delete[] ak3;delete[] ak4;delete[] ak5;delete[] ak6;
					return;
				}
			if(fabs(hnext)<=hmin)cout<<"Step size too small in rkint"<<endl;
			hrk=hnext;
		} //end nstp loop
	cout<<"Too many steps in rkint"<<endl;
	
	//Free up the memory allocated to the arrays:
	delete[] pcopy;delete[] dery;delete[] pscal;delete[] perr;delete[] ptemp;
	delete[] ak2;delete[] ak3;delete[] ak4;delete[] ak5;delete[] ak6;
	
	return;
}
//End of rkint()
