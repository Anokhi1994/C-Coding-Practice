#ifndef LISTSTRATEGY_HPP
#define LISTSTRATEGY_HPP
#include <ostream>
#include <vector>
#include <string>
#include <sstream>

class ListStrategy{
public:
	virtual void start(std::ostringstream& os){
	}

	virtual void add(std::ostringstream& oss,
			const std::string& item)=0;

	virtual void end(std::ostringstream& os){
	}

	virtual ~ListStrategy()=default;
};





#endif


