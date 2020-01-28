#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
#include <cmath>
#include <limits>
using namespace std;

struct DiscriminantStrategy
{
	DiscriminantStrategy()=default;
    virtual double calculate_discriminant(double a, double b, double c) = 0;
    virtual ~DiscriminantStrategy()=default;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
	OrdinaryDiscriminantStrategy()=default;

	virtual double calculate_discriminant(double a, double b, double c){
		double discriminant = b*b - 4*a*c;
		return discriminant;
	}

	virtual ~OrdinaryDiscriminantStrategy()=default;
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
	RealDiscriminantStrategy()=default;
	virtual double calculate_discriminant(double a, double b, double c) override {
		double discriminant = b*b - 4*a*c;
		if(discriminant < 0){
			std::numeric_limits<double>::quiet_NaN();
		}
		return discriminant;
	}
	virtual ~RealDiscriminantStrategy() = default;
};

class QuadraticEquationSolver
{
    DiscriminantStrategy& strategy;
public:
    QuadraticEquationSolver()=default;

    QuadraticEquationSolver(DiscriminantStrategy& strategy) : strategy(strategy) {}

    void do_nothing(){std::cout << "do nothing";}

    tuple<complex<double>, complex<double>> solve(double a, double b, double c)
    {
    	std::complex<double> mycomplex1 = strategy.calculate_discriminant(a, b, c);
    	auto res = std::tuple(mycomplex1, -mycomplex1);
    	return res;
    }
    ~QuadraticEquationSolver()=default;
};

int main(){
	OrdinaryDiscriminantStrategy obj;
	QuadraticEquationSolver qES(obj);
	qES.solve(1.0, 1.0, 1.0);
	return 0;
}
