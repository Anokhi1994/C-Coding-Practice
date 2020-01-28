#include "HTML.hpp"



HTML::HTML()=default;

void HTML::start(std::ostringstream& os)  {
	os << "<html>\n";
}

HTML::~HTML()=default;
