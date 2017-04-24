#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
	
	float g; float L; float V; float l; float v;  
	cout<<"What fraction of speed of light does Alex travel at?";//prompt input
	cin>>v;
	cout<<" "<<endl;
	if(v>=1){cout<<"incorrect value!"
	;
	return 0;
	}else if(v<0){cout<<"incorrect value!"
	;
	return 0;
	}else
	
	g=(1/sqrt(1-v*v));
	l=4;
	cout<<"The distance of him appearing to an observer on earth="<<l<<"light years" <<endl;//initial distance
	L=(1/g)*l;
	cout<<" "<<endl;
	cout<<"The distance travelled from Alex's perspective="
		<< setiosflags(ios::fixed | ios::showpoint)
        << setprecision(3)
        << L
		<<"light years"<<endl;

	return 0;
}
