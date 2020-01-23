#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include "MyException.hpp"


class Country{
	public:
		Country() = default;
		virtual std::stringstream& generate_number(std::string sex_type,
								int DD, int MM, int YYYY) const  = 0;

		virtual ~Country() = default;
		virtual std::ostream& format(std::ostream&) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Country& obj){
	return obj.format(os);
}

#endif


