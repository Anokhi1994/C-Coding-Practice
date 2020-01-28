#ifndef TCPSTATE_HPP
#define TCPSTATE_HPP
#include <memory>
#include <iostream>
class TCPState{
	public:
	TCPState()=default;

	virtual void open(){}

	virtual void closed(){}

	virtual void acknowledge(){}

	virtual ~TCPState() = default;
};

class TCPEstablished : public TCPState{
	private:
	public:
		TCPEstablished()= default;
		virtual void closed(){std::cout << "Connection is not closed\n";}

		virtual void acknowledge(){std::cout << "Connection is now open\n";}
		~TCPEstablished()=default;
};

class TCPAListen : public TCPState{
	private:
	public:
		TCPAListen()= default;
		virtual void open(){std::cout << "Connection is open, acknowledged\n";}
		virtual void closed(){std::cout << "Connection is not closed, acknowledged\n";}
		virtual void acknowledge(){std::cout << "Connection is listening, acknowledged \n";}
		~TCPAListen()=default;
};

class TCPClosed : public TCPState{
	private:
	public:
	TCPClosed()= default;
		virtual void open(){std::cout << "Connection is not open\n";}
		virtual void acknowledge(){std::cout << "Connection is now closed\n";}
		~TCPClosed()=default;
};

#endif
