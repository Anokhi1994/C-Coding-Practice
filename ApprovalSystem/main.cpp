#include <iostream>
#include "RegularEmployee.hpp"
#include <vector>



int main(){

	RegularEmployee* John = new RegularEmployee;
	John->approve_item("Dog", 1000);
	RegularEmployee* Celik = new RegularEmployee;
	John->set_manager(Celik);
	John->approve_item("Bed", 5000);






	return 0;
}
