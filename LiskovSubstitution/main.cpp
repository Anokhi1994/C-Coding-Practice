#include <iostream>
#include <cmath>
constexpr float PI = 3.14159;

class Point{
	private:
		float x_;
	    float y_;
		Point(float x, float y) : x_(x), y_(y) {}
	public:
		static Point newCartesian(const float x, const float y) noexcept {
			return {x,y};
		}

		static Point newPolar(const float r, const float theta) noexcept {
			return {r*cos(theta), r*sin(theta)};
	    }

};



int main(){
	Point p1 = Point::newPolar(5, PI/4);
	Point p2 = Point::newCartesian(1,2);
	return 0;
}
