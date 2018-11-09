#ifndef SIMULATION
#define SIMULATION

#include <string>

class GenMotifSim {
	
	public:
	
	//takes the file name of the genome, the threshold and whether it is a matrix or bed file
	GenMotifSim(std::string, double T, bool matrix);
	
	void run();
	
	
	private:
};

#endif
