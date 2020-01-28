#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "Observer.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
template <typename T>
class Observable{
private:
	std::vector<std::unique_ptr<Observer<T>>> observers;
public:
	Observable() = default;


	virtual void notify(const T& source, const std::string& str) const noexcept {
		for(auto& observer : observers){
			observer->field_change(source, str);
		}
	}

	virtual void subscribe(std::unique_ptr<Observer<T>> obj) noexcept {
		observers.push_back(std::move(obj));
	}

	virtual ~Observable() = default;

};

class Person : public Observable<Person>{
private:
	std::string name_;
	int age_;
public:
	Person()= default;

	Person(const std::string& name, int age):name_(name),age_(age){}

	int get_age(){return age_;}

	void set_age(int age){
		age_=age;
		notify(*this, "age");
	}

	std::string get_name()const noexcept {return name_;}


};

class ConsolePersonObserver : public Observer<Person>{
public:
	virtual void field_change(const Person& person,
			const std::string& obj) const noexcept override {
		std::cout << person.get_name() << "'s age has been changed!\n";
	}

	virtual ~ConsolePersonObserver() = default;
};

#endif
