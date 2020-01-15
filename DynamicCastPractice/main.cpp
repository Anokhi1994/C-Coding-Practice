#include  <cstdint>
#include <iostream>
#include <type_traits>

class Base{
    private:
        int value_;
    public:
      Base(const int value) : value_(value){}
      int get_value(){
          return value_;
      }
	  virtual ~Base() = default;
};

class Derived: public Base{
    private:
        std::string mstring;
    public:
        Derived(int value, std::string srcString):
            Base(value), mstring(srcString){}
    std::string get_string(){
            return mstring;
    }
};

int second;
Base* get_object(bool isDerived){
	
	static int third;
	int frist;
	if(isDerived){
		return new Derived(1, "Apple");	
	}
	else return new Base(2);
}

namespace std{
	template <typename T>
	class vector{
		size_t vecSize;//size is 10 for now
		T* vecData{nullptr};
		public:
		vector(const vector& obj ) : vecSize(obj.vecSize) {
		    vecData = new T[obj.vecSize];
			for( int i=0; i< obj.vecSize; i++){
				vecData[i] = obj.vecData[i];
			}
		}
				
		~vector(){
			delete[] vecData;
		}		
	};
}
int main(){
	Base* base = get_object(false);
	Derived* derived = dynamic_cast<Derived*>(base);
	if(derived)
	std::cout << derived->get_string() << "\n";
	
	//unamed local scope
	{
		int LocalStackObject = 10;
	}//int stakcObject goes out of scope here
	
	int stackObject = 10;
	int* anotherObject = new int(10);
	std::vector<int> first {10, 20, 30, 40, 50};

	
	int array[10];
	int* arr2 = new int[10];
	delete[] arr2;
     return 0;
}

