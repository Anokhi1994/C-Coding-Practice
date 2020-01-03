#include "composite_password_generator.hpp"
#include "lower_letter_generator.hpp"
#include "upper_letter_generator.hpp"
#include "symbol_generator.hpp"
#include "digit_generator.hpp"
#include <memory>
int main(){
		composite_password_generator generator;
		generator.add(std::make_unique<symbol_generator>(2));
		generator.add(std::make_unique<digit_generator>(2));
		generator.add(std::make_unique<upper_letter_generator>(2));
		generator.add(std::make_unique<lower_letter_generator>(4));
		generator.add(std::make_unique<lower_letter_generator>(4));
		int num = 10;
		while(--num){
		auto password = generator.generate();
		std::cout << password << "\n";
		}
		
		return 0;
	}
