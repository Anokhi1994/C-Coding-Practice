#ifndef TEXTFORMATTER_HPP
#define TEXTFORMATTER_HPP
#include <memory>
#include "HTML.hpp"
#include "Markdown.hpp"
#include <ostream>
#include <sstream>

enum class OutputFormat{
	Markdown,
	html
};

class TextFormatter{
	std::ostringstream oss_;
	std::unique_ptr<ListStrategy> ls_;
public:
	TextFormatter()=default;

    void set_outputformatStrategy(const OutputFormat& opf){
    	if(opf == OutputFormat::Markdown){
    		ls_ = std::make_unique<Markdown>();
    	}
    	else if(opf == OutputFormat::html){
    		ls_ = std::make_unique<HTML>();
    	}
    }


    void append_list(std::vector<std::string>& item){
    	ls_->start(oss_);
    	for(const auto itemElem : item){
    		ls_->add(oss_, itemElem);
    	}
    	ls_->end(oss_);
    }

    std::string str() const { return oss_.str(); }

    void clear()  {
    	oss_.str("");
    	oss_.clear();

    }

};

#endif

