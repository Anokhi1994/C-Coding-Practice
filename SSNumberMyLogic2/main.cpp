#include <iostream>
#include "Factory.hpp"
#include <memory>
int main(){

	auto ss1 = Factory::generate("northeria", "F", 28, 9, 2019);


	std::cout << *ss1;
	return 0;
}
