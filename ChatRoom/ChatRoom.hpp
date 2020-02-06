#ifndef CHATROOM_H
#define CHATROOM_H
#include "Person.hpp"
#include <vector>
#include <memory>


class ChatRoom{
private:
	//Person* person;
	std::vector<Person*> members_;
	std::vector<int> chat_ = std::vector<int>(5);

public:
	ChatRoom();

	void join(Person* person) noexcept {
		members_.push_back(person);
		std::string msg = "'" + person->getName() + " joined the group'\n";
		broadcast_message(msg);
	}

	void broadcast_message(
			const std::string& msg){
		std::cout << msg << "\n";
			//std::cout << msg << "\n";
		}





	~ChatRoom() = default;






};

#endif
