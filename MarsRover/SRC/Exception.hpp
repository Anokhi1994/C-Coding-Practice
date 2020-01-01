#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <exception>
#include <iostream>
#include <string>
class LoadException: public std::exception {
private:
    std::string message_;
public:
    explicit LoadException(const std::string& message);
    virtual const char* what() const throw() {
        return message_.c_str();
    }
};


LoadException::LoadException(const std::string& message) : message_(message) {

}

#endif
