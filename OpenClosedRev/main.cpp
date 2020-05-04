#include <iostream>
#include <vector>

enum class Color{red, green , yellow};
enum class Size{small, medium , big};

struct Product{
    std::string name_m;
    Color color_m;
    Size size_m;
    Product(const std::string& name, const Color &color, const Size& size):
    name_m(name), color_m(color), size_m(size){}

};

/* struct ProductFilter{
    std::vector<Product*> by_color(std::vector<Product*> items, Color color){
        std::vector<Product*> result;
        for(auto& i : items){
            if(i->color_m == color){
                result.push_back(i);
            }

        }
        return result;
    }
}; */

template <typename T> 
struct Specification{
    virtual bool is_satisfied(T* item)=0;
};

template <typename T> 
struct Filter{
    virtual std::vector<T*> filter(std::vector <T*> items, Specification<T> &spec)=0;
};

struct BetterFilter : Filter<Product>{
     virtual std::vector<Product*> filter(std::vector <Product*> items, Specification<Product> &spec) override{
        std::vector<Product*> result;
        for(auto& item : items){
            if(spec.is_satisfied(item)){
                result.push_back(item);
            }
        }
        return result;
    }
};

struct ColorSpecification : Specification<Product>{
    Color color_m;
    ColorSpecification(Color color) : color_m(color){}
    virtual bool is_satisfied(Product* item) override{
        return item->color_m == color_m;
    }
};

struct SizeSpecification : Specification<Product>{
    Size size_m;
    SizeSpecification(Size size) : size_m(size){}
    virtual bool is_satisfied(Product* item) override{
        return item->size_m == size_m;
    }
};

template <typename T> struct AndSpecification : Specification<T>{
    Specification<T> &first_m;
    Specification<T> &second_m;
    AndSpecification(Specification<T> &first, Specification<T> &second):
    first_m(first), second_m(second){}
    virtual bool is_satisfied(T* item) override{
        return first_m.is_satisfied(item) && second_m.is_satisfied(item);  
    }
};



int main(){
    
    Product apple1("Green Apple", Color::green, Size::big);
    Product apple2("Red Apple", Color::green, Size::medium);
    std::vector<Product*> items{&apple1, &apple2 };


  BetterFilter bf;
  ColorSpecification green(Color::green);
  SizeSpecification medium(Size::medium);
  AndSpecification<Product> greenAndMedium(green, medium);
  for(auto& item : bf.filter(items, green)){
      std::cout << item->name_m << " is green\n";
  }
  for(auto& item : bf.filter(items, medium)){
      std::cout << item->name_m << " is big\n";
  }

  for(auto& item : bf.filter(items,greenAndMedium )){
      std::cout << item->name_m << " is medium and big\n";
  }
    return 0;
}