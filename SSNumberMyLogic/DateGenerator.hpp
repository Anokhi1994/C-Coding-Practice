#ifndef DATEGENERATOR_HPP
#define DATEGENERATOR_HPP

#include <string> 
#include <sstream> 





			
std::string generate_date_string(int DD, int MM, int YYYY){
	if( DD < 0 || DD > 31){
		throw "invalid day in date";				
	}
	if(MM < 0 || MM > 12){
		throw "invalid month in date";
	}
	if(YYYY < 1960 || MM > 2020){
		throw "invalid year in date";
	}


	
	
	std::string s = std::to_string(DD) + std::to_string(MM) + std::to_string(YYYY);
	return s;
}
			
#endif 

