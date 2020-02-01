#include <iostream>
struct BSTNode{
    int data_;
    BSTNode* left_;
    BSTNode* right_;

    BSTNode(int data):
    data_(data), left_(nullptr), right_(nullptr){}

};

struct BST{
    BSTNode* root_{nullptr};

    void insert(BSTNode*& node, int value){
        if(!node){
            std::cout << "inserting at root node\n ";
            node = new BSTNode(value);
        }
        
        if(value < node->data_){
            std::cout << "inserting at left node\n";
            insert(node->left_ , value);     
                
        }

        if(value > node->data_){
            std::cout << "inserting at right node\n";
            insert(node->right_, value); 
        }
    }

    void insert(int value){
        insert(root_, value);
    }
};

int main(){
    std::cout << "Hello World\n";
    BST tree;
    tree.insert(11);
    tree.insert(10);
    tree.insert(12);
    return 0;
}
