#ifndef HTML_HPP
#define HTML_HPP
#include "ListStrategy.hpp"

class HTML : public ListStrategy{
public:
	HTML();
	virtual void start(std::ostringstream& os) override;
	  void add(std::ostringstream& oss,
			  const std::string& item) override{
	    oss << "  <li>" << item <<  "</li>\n";
	  }

		virtual void end(std::ostringstream& os) override {
			os << "</html>\n";
		}

	~HTML();
};

#endif
