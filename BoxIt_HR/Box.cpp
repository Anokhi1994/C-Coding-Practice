#include "Box.hpp"


Box::Box():l_{std::make_unique<ulong>(0)}, h_{std::make_unique<ulong>(0)}, b_{std::make_unique<ulong>(0)}{};
Box::Box(ulong l, ulong b, ulong h):l_{std::make_unique<ulong>(l)}, h_{std::make_unique<ulong>(h)}, b_{std::make_unique<ulong>(b)}{}; 
Box::Box(const Box& obj):l_(std::make_unique<ulong>(*obj.l_)), 
                            h_(std::make_unique<ulong>(*obj.h_)), 
                            b_(std::make_unique<ulong>(*obj.b_)){};

ulong Box::getLength() {
return *l_; 
}

ulong Box::getBreadth() {
return *b_; 
}

ulong Box::getHeight() {
return *h_; 
}

ulong Box::CalculateVolume() {
return (*l_ * *h_ * *b_);
}

Box& Box::operator = (const Box &obj) {
    this->l_ = std::make_unique<ulong>(*obj.l_);
    this->h_ = std::make_unique<ulong>(*obj.h_);
    this->b_ = std::make_unique<ulong>(*obj.b_);
 return *this;
} 

bool Box::operator < ( const Box  &obj) {  
 return ((*obj.l_ > *this->l_) || 
         (*obj.b_ > *this->b_ && *obj.l_ == *this->l_ ) || 
         (*obj.h_ > *this->h_ && *obj.b_ == *this->b_ && *obj.l_ == *this->l_ )); 
}

std::ostream& operator << (std::ostream& os, const Box& obj){
 os << *(obj.l_) << " " << *(obj.b_) << " " << *(obj.h_);
 return os;
}


