#ifndef SOUTHERIA_H
#define SOUTHERIA_H
#include "Country.hpp"
#include <memory>
#include <sstream>
class Southeria : public Country{
private:
	std::string sex_type_m;
	int DD_m;
	int MM_m;
	int YYYY_m;
public:
	Southeria() = default;

	Southeria(const std::string& sex_type, const int DD, const int MM, const int YYYY):
		sex_type_m(sex_type), DD_m(DD), MM_m(MM), YYYY_m(YYYY){
		if(sex_type_m != "F" && sex_type_m != "M"){
			throw LoadException("Invalid input for male or female");
		}
	}


	std::stringstream& generate_number(std::string sex_type,
									int DD, int MM, int YYYY) const {
		std::stringstream s;
		if(sex_type == "F"){
			s << 3 << std::to_string(DD) << std::to_string(MM) << std::to_string(YYYY);

		}
		else if(sex_type == "M"){
			s << 4 << std::to_string(DD) << std::to_string(MM) << std::to_string(YYYY);
		}
		else LoadException("Invalid input for male or female");

		return s;

	}

	~Southeria() = default;


	int getDdM() const {
		return DD_m ;
	}

	int getMmM() const {
		return MM_m;
	}

	const std::string& getSexTypeM() const {
		return sex_type_m;
	}

	int getYyyyM() const {
		return YYYY_m;
	}

	std::ostream& format(std::ostream& os) const {
		os << getSexTypeM() << getDdM() << getMmM() << getYyyyM();
	}

};
#endif
