#include <iostream>
#include <vector>

    
void printVec(const std::vector<int>& vec){
        for(int i = 1; i < vec.size(); i++){
        std::cout << vec[i] << "  ";
    }
    std::cout << "\n";
}

void swap(std::vector<int>& vec, int parent, int child){
    int temp = vec[child];
    vec[child] = vec[parent];
    vec[parent] = temp;
}

void update(int& child, int& parent){
    child = parent;
    parent = parent/2;
}


void balanceMinHead(std::vector<int>& vec){
    int LastUsedIndex = vec.size()-1;
    int child = LastUsedIndex;
    int parent = LastUsedIndex/2+1;
    while(vec[parent] > vec[child]){
        swap(vec, parent, child);
        printVec(vec);
        update(child, parent);
    }
}


void insertMinHeap(std::vector<int>& vec, int data){
    vec.push_back(data);
    printVec(vec);
    balanceMinHead(vec);   
}

int getMinOfTwoNodes(const std::vector<int>& vec, const int index){
    int leftIndex = index*2;
    int rightIndex = leftIndex + 1;
    return vec[leftIndex] < vec[rightIndex] ? leftIndex : rightIndex;
}

void balanceMinHeap2(std::vector<int>& vec, int parentIndex){
        int childIndex = getMinOfTwoNodes(vec, parentIndex);
        while(vec[childIndex] < vec[parentIndex]){
           swap(vec, childIndex, parentIndex); 
           parentIndex = childIndex;
           childIndex = getMinOfTwoNodes(vec, parentIndex);
           //std::cout << "child " << vec[childIndex] << " parent " << vec[parentIndex]
               //     << "\n";
        }

}

void deleteMinHeap(std::vector<int>& vec){
    int currentIndex = vec.size()-1;
    vec[1] = vec[currentIndex];
    vec.pop_back();
    int parentIndex = 1;
    balanceMinHeap2(vec, parentIndex);

    }



int main(){
    std::vector<int> vec{-1, 3, 5, 8, 17, 19, 36, 40, 25, 100};
    //insertMinHeap(vec, 1);
    std::cout << "from main \n";
    printVec(vec);
    deleteMinHeap(vec);
    printVec(vec);


    return 0;
}
