 #include "Markdown.hpp"

 void Markdown::add(std::ostringstream& oss,
		  const std::string& item) 	{
    oss << " * " << item << "\n";
  }
