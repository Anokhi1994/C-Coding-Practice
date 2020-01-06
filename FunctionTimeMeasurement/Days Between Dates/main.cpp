#include "date.h"
#include <iostream>

inline int number_of_days(int const y1, int const m1, int const d1, 
						  int const y2, int const m2, int const d2){
	   using namespace date;
	   return (sys_days{ year(y1) / month(m1) / day(d1) } -
				sys_days{ year(y2)/ month(m2)/ day(d2) }).count();
			
}

inline int number_of_days(date::sys_days const& first, date::sys_days const& last){
			return  (last - first).count();
}

int main(){
	auto diff1 = number_of_days(2016, 9, 23, 2017, 5, 15);
	std::cout << "diff 1" << diff1 << "\n";
	using namespace date::literals;
	auto diff2 = number_of_days(2019_y/sep/27, 2018_y/sep/29);
	std::cout << "diff 2" << diff2 << "\n";

}
