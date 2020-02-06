#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>

class ChatRoom;

class Person{
private:
	const std::string name_;
	std::string from_;
	ChatRoom* room_;
	std::vector<std::string> personal_chatlog;

public:
	Person();

	Person(const std::string& name);

	const std::string getName() const noexcept;

	void say(const std::string &msg);

	void set_from(std::string from);

	void pm(Person& to, const std::string& msg);

	void readMessage(const std::string& msg, const std::string& from);

	void show_my_messages();

	~Person() = default;

};
#endif
