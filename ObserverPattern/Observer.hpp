#ifndef OBSERVER_HPP
#define OBSERVER_HPP
#include <string>
#include <iostream>
template<typename T>
class Observer{
public:
	Observer() = default;

	virtual void field_change(const T& source, const std::string& obj) const noexcept {
	}

	virtual ~Observer() = default;
};



#endif
