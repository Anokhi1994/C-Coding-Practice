
#include "TCPConnection.hpp"

int main(){

	TCPConnection conn( "google.com" , std::make_unique<TCPEstablished>());
	conn.open_TCPConnection();
	conn.acknowledge_TCPConnection();
	conn.close_TCPConnection();
	conn.acknowledge_TCPConnection();
	conn.listen_TCPConnection();
	conn.acknowledge_TCPConnection();
	return 0;
}
