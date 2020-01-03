#ifndef BASIC_PASSWORD_GENERATOR
#define BASIC_PASSWORD_GENERATOR
#include "password_generator.hpp"
class basic_password_generator : public password_generator{
	private:
		size_t len;
	public:
		explicit basic_password_generator(size_t const len) noexcept : len(len){}

		virtual std::string generate() override{
			throw std::runtime_error("not implemented");		
		}

		virtual void add(std::unique_ptr<password_generator>) override{
			throw std::runtime_error("not implemented");		
		}

		virtual size_t length() const override final{
			return len;
        }

		


};

#endif
