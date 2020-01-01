#ifndef ROVER_HPP
#define ROVER_HPP
#include <iostream>
class Rover  {
	private:
	int x_ = 0;
	int y_ = 0;
	char orientation_ = 'N';

	public:
	Rover() = default;
	Rover(int x,int y,char orientation):x_(x), y_(y), orientation_(orientation){
		}
	int get_x() {
		return x_;
	 }

	int get_y() {
		return y_;
	 }

	char get_orientation() {
		return orientation_;
	 }

	void set_x(const int& x) {
		x_ = x;
	 }

	void set_y(const int& y) {
		y_ = y;
	 }

	char set_orientation(const char& N) {
		orientation_ = N;
	 }

	void display_position(){
	std::cout << x_ << " " << y_ << " " << orientation_ << "\n";
	}

	virtual void move_forward(){} ;
	virtual void move_left(){} ;
	virtual void move_right(){} ;
};

#endif

