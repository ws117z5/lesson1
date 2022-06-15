#include <iostream>

using namespace std;

template<typename T>
class BSTNode {
private:
    BSTNode<T> * right = nullptr;
    BSTNode<T> * left = nullptr;
    int data;
public:
    BSTNode (T data) : data(data) {
        this->right = nullptr;
        this->left = nullptr;
    };

    void set (T data) {
        
    }

};