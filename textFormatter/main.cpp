#include <iostream>
#include <string>
#include <vector>
#include "TextFormatter.hpp"
int main(){
	std::vector<std::string> items{"dog", "house", "plants"};
	TextFormatter tf;
		tf.set_outputformatStrategy(OutputFormat::Markdown);
		tf.append_list(items);
	std::cout << tf.str();
	tf.clear();
	tf.set_outputformatStrategy(OutputFormat::html);
	tf.append_list(items);
	std::cout << tf.str();
	tf.clear(); 
	return 0;
}
