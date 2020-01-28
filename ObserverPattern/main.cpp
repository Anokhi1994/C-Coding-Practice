#include "Observerable.hpp"
#include "Observer.hpp"
#include <vector>
int main(){
	Person p("Anokhi", 19);

	p.subscribe(std::make_unique<ConsolePersonObserver>());
	p.set_age(20);
	return 0;
}
