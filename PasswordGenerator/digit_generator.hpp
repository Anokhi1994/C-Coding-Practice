#ifndef DIGIT_GENERATOR_HPP
#define DIGIT_GENERATOR_HPP
#include <iostream>
#include "basic_password_generator.hpp"

class digit_generator : public basic_password_generator {
	public:
		explicit digit_generator(size_t const len) noexcept
			:basic_password_generator(len)
        {}
		
		virtual std::string allowed_chars() const override{
			return "0123456789";
		}	

};

#endif 
