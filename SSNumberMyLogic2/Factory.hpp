#ifndef GENERATORFACTORY_H
#define GENERATORFACTORY_H
#include "Northeria.hpp"
#include "Southeria.hpp"

class Factory{
	private:
		Factory() = default;
	public:


		static std::unique_ptr<Country> generate(const std::string& country,
						  const std::string& sex_type,
						  const int DD, const int MM, const int YYYY) {

			if(country == "northeria"){
				auto ptr = std::unique_ptr<Northeria>{new Northeria{sex_type, DD, MM, YYYY}}; // <- 1
				  return ptr;
			}
			else if(country == "southeria"){
				auto ptr = std::unique_ptr<Southeria>{new Southeria{sex_type, DD, MM, YYYY}}; // <- 1
				  return ptr;
			}
			else throw "invalid country input";
		}

		~Factory() = default;


};
#endif
