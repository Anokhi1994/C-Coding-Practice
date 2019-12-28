#include "Student.hpp"

void Student::input(){
    int marks;
    
    for(int i=0; i< 5; i++){
    std::cin >> marks;
    scores.push_back(marks);
    }
    
} 

int Student::calculateTotalScore(){
    return std::accumulate(scores.begin(), scores.end(), 0);
    
}
