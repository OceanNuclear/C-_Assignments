//RandomNumberGenerator class declaration:
class RandomNumberGenerator
{
	public:
		double Z();								//Returns a random double z between 0 and 1.0
		RandomNumberGenerator(unsigned iseed);	//Constructor
		RandomNumberGenerator();				//Default constructor
	private:
		unsigned iran;							//Holds random integer
		double ztable[32];						//Array for shuffle table
		void Init(unsigned iseed);				//Initializes the shuffle table
};
