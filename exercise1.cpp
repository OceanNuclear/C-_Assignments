#include <iostream> //Declares cout
#include <fstream> //Use for file output
#include <conio.h> //Declares the _getch() function
using namespace std; //Allows use of cout instead of std::cout
//Main program:
int main(void)
	{
		ofstream outs;
		outs.open("tempout.txt");//just testing
			cout<<"1"<<endl;
			cout<<"2"<<endl;
			cout<<"if you are seeing this it works"<<endl;
		outs.close();
		_getch();
		return 0;
	}
//end of test program
