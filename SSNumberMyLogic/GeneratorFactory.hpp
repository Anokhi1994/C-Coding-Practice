#include "northeria.hpp"
#include "southeria.hpp"
#include "DateGenerator.hpp"

class GeneratorFactory{
		public:	
			GeneratorFactory(const std::string& country, const std::string& sex_type, 
							int DD, int MM, int YYYY){
							if(country == "northeria"){
									Northeria north(sex_type, DD, MM, YYYY);	
									std::string s = north.generate_number(sex_type);
									std::cout << s << "\n";	
													
							}
							else if(country == "southeria"){
									Southeria south(sex_type, DD, MM, YYYY);
									std::string s = south.generate_number(sex_type);
									std::cout << s << "\n";						
							}
				
	
			}





};
