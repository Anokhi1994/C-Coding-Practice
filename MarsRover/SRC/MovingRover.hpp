#ifndef MOVING_ROVER_HPP
#define MOVING_ROVER_HPP
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <exception>
#include <sstream> 
#include <string>
#include <map>
#include "Rover.hpp"
class MovingRover : public Rover{
		public:
		MovingRover(int x,int y,char orientation)
        : Rover(x,y,orientation)
        {}
        
		virtual void move_forward(){
		switch (this->get_orientation()) { 
			case 'N': 
				this->set_y(this->get_y() + 1) ; 
				break;
			case 'W': 
				this->set_x(this->get_x() - 1); 
				break;
			case 'S': 
		        this->set_y(this->get_y() - 1); 
		        break;
			case 'E': 
				this->set_x(this->get_x() + 1) ;
				break;
	         }		
	    }

 		virtual void move_left(){
		switch (this->get_orientation()) { 
			case 'N': 
				this->set_orientation('W') ; 
				break;
			case 'W': 
				this->set_orientation('S'); 
				break;
			case 'S': 
		        this->set_orientation('E'); 
		        break;
			case 'E': 
				this->set_orientation('N'); 
				break;
	         }		
	    }

		 virtual void move_right(){
		switch (this->get_orientation()) { 
			case 'N': 
				this->set_orientation('E') ; 
				break;
			case 'W': 
				this->set_orientation('N'); 
				break;
			case 'S': 
		        this->set_orientation('W'); 
		        break;
			case 'E': 
				this->set_orientation('S'); 
				break;
	         }		
	    }


};

#endif
