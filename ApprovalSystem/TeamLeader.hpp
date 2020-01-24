#ifndef TEAMLEADER_HPP
#define TEAMLEADER_HPP
#include "Employee.hpp"
#include <string>
class TeamLeader : public Employee{
private:
	const int limit_ = 10000;
	const Position pos = Position::Team_Leader;
public:
	virtual int getLimit() const noexcept override {
		return limit_;
	}

	virtual void set_manager(Employee* employee) noexcept override {
		std::cout << "do something";
	}

	virtual void approve_item(const std::string& itemName, const int price) override {
		if(price <= limit_){
			std::cout << "Approved";
		}
		else {
			std::cout << "To be approved by TeamLeader";
		}

	}
};
#endif
