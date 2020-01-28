#ifndef MARKDOWN_HPP
#define MARKDOWN_HPP

#include "ListStrategy.hpp"

class Markdown : public ListStrategy{
public:
	  void add(std::ostringstream& oss,
			  const std::string& item) override;
};
#endif

