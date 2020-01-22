#include "DateGenerator.hpp"
class Northeria{
		
		private:
			const std::string sex_type_m;
			int MM_, DD_, YYYY_;
		public:
			Northeria() = default;

			Northeria(std::string sex_type, int MM, int DD, int YYYY):
					sex_type_m(sex_type),
					MM_(MM), DD_(DD), YYYY_(YYYY){
			if((sex_type  != "F") && (sex_type != "M")){
					throw "invalid input";				
				}
			}

			std::string get_sex_type()const noexcept{
				return sex_type_m;			
			}

			std::string generate_number(const std::string& sex_type) const {
				std::string s = generate_date_string(MM_, DD_, YYYY_);
				if(sex_type == "F"){					
					s + std::to_string(1);
					return s;			
				}
				else if(sex_type == "M"){
					s + std::to_string(2);
					return s;				
				}
				else throw "invalid input";
			}





};
