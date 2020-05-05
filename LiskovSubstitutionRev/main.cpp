#include <iostream>

class Rectangle{
protected:
    int width_m;
    int height_m;

public:
    Rectangle(const int &width, const int &height):
    width_m(width), height_m(height){}

   virtual void set_width(const int &width) noexcept{
       Rectangle::width_m = width;
   } 

   virtual void set_height(const int &height) noexcept {
       Rectangle::height_m = height;
   }

   int get_width() const {
       return width_m;
   }

   int get_height() const {
       return height_m;
   }

   int area() const {
       return width_m*height_m;
   }

};

class Square :public Rectangle{
    public:
    Square(const int& length):
    Rectangle(length, length){}
   virtual void set_width(const int &width) noexcept override{
       this->height_m = this->width_m = width;
   }

  virtual void set_height(const int &height) noexcept override{
       this->height_m = this->width_m = height;
   }
};

void process(Rectangle &r){
    int w = r.get_width();
    r.set_height(10);
    std::cout << "Expected " << (w*10) << " got " << r.area() << "\n";
}




int main(){
    Rectangle r(3,4);
    process(r);
    Square s(5);
    process(s);
    return 0;
}
