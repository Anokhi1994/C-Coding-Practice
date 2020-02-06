#include "Person.hpp"
#include "ChatRoom.hpp"
Person::Person() = default;

Person::Person(const std::string& name):
	name_(name){}

const std::string Person::getName() const noexcept {
	return name_;
}

void Person::say(const std::string &msg){
	std::string messageInGroup = name_ + ": " + msg + "\n";
	room_->broadcast_message(messageInGroup);
}

void Person::set_from(std::string from){
	from_= from;
}

void Person::pm(Person& to, const std::string& msg){
	std::cout << to.name_ << " you have a personal message from "
			<< this->name_ << "\n";
	to.readMessage(msg, this->name_);

}

void Person::readMessage(const std::string& msg, const std::string& from){
	personal_chatlog.push_back(msg);
}

void Person::show_my_messages(){
	std::cout << name_ << " personal messages!\n";
	if(personal_chatlog.empty()){
		std::cout << "You have no pending messages";
	}
	else{
	for(auto message : personal_chatlog){
		std::cout << message << "\n";
	 }
	std::cout << "\n";
	}
}



