#include <iostream>
#include <string>
#include <vector>

enum class Color {red, green, blue};
enum class Size {small, medium , large};

struct Product{
	std::string name_;
	Color color_;
	Size size_;
	Product(const std::string& name, const Color& color, const Size& size) :
		name_{name}, color_{color}, size_{size}{};
};

struct ProductFilter{
	std::vector<Product*> by_color(std::vector<Product*> items, Color sourceColor){
		std::vector<Product*> result;
		for(auto& i : items){
			if(i->color_ == sourceColor){
				result.push_back(i);			
			}		
		}
		return result;
	}
};

template<typename T> 
struct Specification{
	virtual bool is_satisfied(T* item) = 0;
}

template<typename T>
struct Filter{
	virtual vector<*T> filter(vector<T*> items, specification<T>& spec) = 0;	
}

struct BetterFilter : Filer<Product>{
	vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) {
	vector<Product*> result;
		for(auto& item : items){
			if(is_satisfied(item){
				result.push_back(item);			
			}		
		}
	}

}

void print(const std::vector<Product*>& items){
	for(auto& i: items){
		std::cout << i->name_ << "\n";
	}
}



int main(){
	Product Tree("Tree", Color::green, Size::medium);
	Product Apple("apple", Color::red, Size::small);
	Product Pant("Jeans", Color::blue, Size::medium);
	std::vector<Product*> items{&Tree, &Apple, &Pant};
	ProductFilter pf;
	print(pf.by_color(items, Color::red));
	
	return 0;
	}

