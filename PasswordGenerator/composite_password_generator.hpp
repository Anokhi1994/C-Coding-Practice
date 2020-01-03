#ifndef COMPSOTIE_PASSWORD_GENERATOR_HPP
#define COMPSOTIE_PASSWORD_GENERATOR_HPP
#include <random>
#include <algorithm>
#include "password_generator.hpp"
class composite_password_generator : public password_generator{
	private:
		std::random_device rd;
		std::mt19937 eng;
		std::vector<std::unique_ptr<password_generator>> generators;

		virtual std::string allowed_chars() const override {
			throw std::runtime_error("not implemented");
		}

		virtual size_t length() const override {
			throw std::runtime_error("not implemented");
		}
	
	public:
		composite_password_generator(){
			auto seed_data =std::array<int, std::mt19937::state_size>{};
			std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
			std::seed_seq(std::begin(seed_data), std::end(seed_data));
			
		}
			
		virtual std::string generate() override {
			std::string password;
			for(auto& generator : generators){
				std::string chars = generator->allowed_chars();
				std::uniform_int_distribution<> ud(
					0, static_cast<int>(chars.length()-1));

				for(size_t i=0; i < generator->length(); ++i)
				password += chars[ud(eng)];			
			}
			
			std::shuffle(std::begin(password), std::end(password), eng);
			return password;		
		}

		virtual void add(std::unique_ptr<password_generator> generator) override{
			generators.push_back(std::move(generator));
		}

};
#endif
