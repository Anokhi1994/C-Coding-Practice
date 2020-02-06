#include "Person.hpp"
#include "ChatRoom.hpp"

int main(){
	ChatRoom chatRoom1;
	Person John("John");
	chatRoom1.join(&John);
	Person Robert("Robert");
	chatRoom1.join(&Robert);
	Robert.say("Hi John");
	John.say("Hi Robert");
	Person Simon("Simon");
	chatRoom1.join(&Simon);
	Simon.say("Hello Everyone");
	Simon.pm(Robert, "how are you?");
	Robert.show_my_messages();
	Robert.pm(Simon, "Am fine");
	Simon.show_my_messages();
	John.show_my_messages();

	return 0;

	//output
	//John joins the chat room
	//Robert joins the chat room
	// John: Hi John
	//Recieved by John, Robert
}
