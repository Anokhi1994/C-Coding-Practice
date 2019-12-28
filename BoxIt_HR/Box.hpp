//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
//#include <numeric>
#ifndef BOX_HPP
#define BOX_HPP
#include <numeric>
#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <memory>

class Box{
    using ulong = unsigned long;
    private:
        std::unique_ptr<ulong> l_ = std::make_unique<ulong>();
        std::unique_ptr<ulong> h_ = std::make_unique<ulong>();
        std::unique_ptr<ulong> b_ = std::make_unique<ulong>();
    public:
        Box(); 

        Box(ulong l, ulong b, ulong h); 

        Box(const Box& obj); 
    
        ulong getLength();

        ulong getBreadth();

        ulong getHeight();

        ulong CalculateVolume();

        Box& operator = (const Box &obj); 

        bool operator < ( const Box  &obj);

        friend std::ostream& operator << (std::ostream& os, const Box& obj);
    
};
#endif 
