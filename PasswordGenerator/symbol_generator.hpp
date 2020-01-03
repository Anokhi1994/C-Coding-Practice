#ifndef SYMBOL_GENERATOR_HPP
#define SYMBOL_GENERATOR_HPP
#include <iostream>
#include "basic_password_generator.hpp"

class symbol_generator : public basic_password_generator {
	public:
		explicit symbol_generator(size_t const len) noexcept
			:basic_password_generator(len)
        {}
		
		virtual std::string allowed_chars() const override{
			return "!@#$%&*(){}[]?<>";
		}	

};

#endif 
