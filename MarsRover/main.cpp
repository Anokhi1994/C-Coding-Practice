#include "SRC/Rover.hpp"
#include "SRC/RoverData.hpp"



int main(){

	try{
	RoverData movingRover;
	movingRover.DATA_FILES("../input.txt", "../output.txt");
	} 
	catch(std::exception& e) {
		std::cerr << e.what() << "\n";
		std::cerr << "Please handle the error appropriately- Force exiting the program\n";
		exit (1);

    }



	
	return 0;
}
