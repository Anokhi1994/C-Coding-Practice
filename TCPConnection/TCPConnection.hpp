#ifndef TCPCONNECTION_HPP
#define TCPCONNECTION_HPP
#include "TCPState.hpp"
#include <memory>
#include <string>
class TCPConnection{
	private:
		std::unique_ptr<TCPState>  state_;
		std::string website_;
		bool open=false;
		bool close=false;
	public:
		TCPConnection(){
			state_ = std::make_unique<TCPEstablished>();
		}

		TCPConnection(const std::string& website, std::unique_ptr<TCPState> obj):
		state_(std::move(obj)),
		website_(website)
			{
		}

		std::string getWebsite_TCPConnection(){
			return website_;
		}

		void set_state_TCPConnection(std::unique_ptr<TCPState> obj){
			if(state_){
			state_.release();
			}
			this->state_ = std::move(obj);
		}

		void open_TCPConnection(){
			set_state_TCPConnection(std::make_unique<TCPEstablished>());

		}

		void acknowledge_TCPConnection(){
			state_->acknowledge();
			std::cout << "website: " << website_ << "\n";
		}


		void close_TCPConnection(){
			set_state_TCPConnection(std::make_unique<TCPClosed>());
		}

		void listen_TCPConnection(){
			set_state_TCPConnection(std::make_unique<TCPAListen>());
		}



};

#endif
