#ifndef SOUNDEX_HPP
#define SOUNDEX_HPP
#include <unordered_map>
static const size_t MaxCodeLength(4);
class Soundex{
	private:
		std::string zeropad(const std::string &val) const {
			return val + std::string(MaxCodeLength - val.length(), '0');
		}  

		std::string head(const std::string &val) const {
			return val.substr(0,1);	
			 }
	

		std::string encodingDigits(const std::string &val) const {
			if(val.length() > 1) return encodedDigit(val[1]);
			return "";
		}

		std::string tail(const std::string& word) const {
			return word.substr(1);
		}

		std::string encodedDigits(const std::string& word) const {
			std::string encoding;
			for (auto letter: word) {
				if (isComplete(encoding)) break;
				encoding += encodedDigit(letter);
				}
				return encoding;
			}

		bool isComplete (const std::string& encoding) const {
		return encoding.length() == MaxCodeLength - 1;
		 }
					
		std::string encodedDigit(char letter) const {
			const std::unordered_map<char, std::string> encodings{
			{'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
			{'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
			{'s', "2"}, {'x', "2"}, {'z', "2"},
			{'d', "3"}, {'t', "3"},
			{'l', "4"},
			{'m', "5"}, {'n', "5"},
			{'r', "6"}
			};
			auto it = encodings.find(letter);
			return it == encodings.end() ? "" : it->second;
 		}
			
	public:
		
		
		Soundex(){};
		std::string encoded(const std::string &val) const {
			return zeropad(head(val) + encodingDigits(val));
		}
	};

#endif
