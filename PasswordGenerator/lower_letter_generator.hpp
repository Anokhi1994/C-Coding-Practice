#ifndef LOWER_LETTER_GENERATOR_HPP
#define LOWER_LETTER_GENERATOR_HPP
#include <iostream>
#include "basic_password_generator.hpp"

class lower_letter_generator : public basic_password_generator {
	public:
		explicit lower_letter_generator(size_t const len) noexcept
			:basic_password_generator(len)
        {}
		
		virtual std::string allowed_chars() const override{
			return "abcdefghijklmnopqrstuvwxyz";
		}	

};

#endif
