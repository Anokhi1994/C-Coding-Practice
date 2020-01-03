#ifndef PASSWORD_GENERATOR
#define PASSWORD_GENERATOR
#include <string>
#include <memory>
#include <iostream>
class password_generator{
	public:
		password_generator(){};
		virtual std::string generate() =0;
		virtual std::string allowed_chars() const = 0;
		virtual size_t length() const = 0;
		virtual void add(std::unique_ptr<password_generator> generator) = 0;
		virtual ~password_generator() = default;
};

#endif

