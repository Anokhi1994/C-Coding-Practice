#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

enum class Position{
	Regular_employee,
	Team_Leader,
	Dept_Manager,
	President
};

class Employee{


public:
	Employee() = default;

	virtual int getLimit() const noexcept = 0;

	virtual void set_manager(Employee* employee) noexcept = 0;

	virtual void approve_item(const std::string& itemName, const int price) = 0;

	virtual ~Employee();
};
#endif
