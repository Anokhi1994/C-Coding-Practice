#ifndef ROVER_DATA_HPP
#define ROVER_DATA_HPP
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <exception>
#include <sstream> 
#include <string>
#include "Rover.hpp"
#include "MovingRover.hpp"
#include "Exception.hpp"
struct RoverData : public MovingRover{
	   std::string inputPath;
	   std::string outputPath;
	   
	   RoverData()
        : MovingRover(0, 0, 'N')
        {}
	   
	   void DATA_FILES(const std::string& Inpath,const std::string& Opath ){
	   std::ifstream infile;
	   try{
		  infile.open(Inpath);
	   if(!infile){
			throw "Error opening file!";
		  }
		}
		catch (const char* &e) {
	        std::cerr << e << "\n";
	       }

		std::ofstream outfile;
		outfile.open(Opath);
		std::string header;
		std::getline(infile, header);
		std::istringstream stream(header);
		int n1;
		int n2;
		stream >> n1 >> n2;
		std::string line;
		while (std::getline(infile, line)) {
		std::istringstream roverStartingPosition(line);
			int x;
			int y;
			char direction;
			roverStartingPosition >> x >> y >> direction;
			this->set_x(x);
			this->set_y(y);
			this->set_orientation(direction);
			std::string FullCommands;
			char command;
			std::getline(infile, FullCommands);
			std::istringstream AllCommands(FullCommands);
			for(auto command : FullCommands){
				AllCommands >> command ;
				
				if(command == 'L') this->move_left();
				else if(command == 'R') this->move_right();
				else if(command == 'M') this->move_forward();
				else {
					infile.close();
					outfile.close();
					throw LoadException("Invalid command for moving rover - only accept L, R & M");
				}
							
			}
			    outfile  << this->get_x() << " "<<  this->get_y() << " "<< this->get_orientation() << "\n";				
	     }				
		}
}; 
#endif

/*
	class MarsRover{
		private:
			char m_orienation;
	};

	class MarsRoverCommand{
		private:
			MarsRover* m_rover; //m_rover knows starting pt, orientation, and its exploration directives
		public:
			void rotate_left()
			{ 
				const char orientation = m_rover->get_orientation();
				char newOrientation = leftRotate[orientation] // if orie = 'N', newOrien = 'E'
				m_rover->set_orientation(newOrientation);
			}

			void roate_right();
,			void move_forward();
	};
*/
