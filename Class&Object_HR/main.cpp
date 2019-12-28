
#include "Student.hpp"
using namespace std;

// Write your Student class here

int main() {
    int n; // number of students
    std::cout << "number of students?\n";
    cin >> n;
    unique_ptr<Student[]>s = std::make_unique<Student[]>(5);
    std::cout << "marks for each student?\n";
    for(int i = 0; i < n; i++){
	std::cout << "Marks for " << i+1 << " student\n";
        s[i].input();
    }

    // calculate kristen's score
    //int kristen_score = s[0].calculateTotalScore();
    unique_ptr<int>kristen_score = 								             std::make_unique<int>(s[0].calculateTotalScore());

    // determine how many students scored higher than kristen
    unique_ptr<int>count = std::make_unique<int>(0);
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > *kristen_score){
            (*count)++;
        }
    }

    // print result
    cout << *count;
    
    return 0;
}


